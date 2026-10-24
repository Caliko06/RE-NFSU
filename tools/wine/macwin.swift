// The Wine reference on this Mac without the OWNER's focus (GPTK Wine has only the macOS driver: a real window).
// usage: macwin list                         windows: id pid owner title
//        macwin front                        pid of the frontmost app (to give the focus back)
//        macwin activate PID                 bring that app back to the front
//        macwin guard NAME BACKPID SECS      while a process named NAME (wine64-preloader) is frontmost, give the front back
//        macwin key PID NAME...              key taps posted to that process only (CGEventPostToPid): Return Right Down ...
//        macwin rec WID SECS OUT.mp4 [WxH]   60 fps recording of one window (ScreenCaptureKit; works while covered)
//        macwin shot WID OUT.png
// rec and shot need the Screen Recording permission for the app that runs this (the terminal).
import AppKit
import AVFoundation
import ScreenCaptureKit

let a = CommandLine.arguments
_ = NSApplication.shared   // ScreenCaptureKit needs the window server connection set up
func die(_ s: String) -> Never { FileHandle.standardError.write((s + "\n").data(using: .utf8)!); exit(1) }

let keycodes: [String: CGKeyCode] = ["Return": 36, "Left": 123, "Right": 124, "Down": 125, "Up": 126, "Escape": 53, "space": 49]

func window(_ wid: UInt32) async -> SCWindow {
    guard let c = try? await SCShareableContent.excludingDesktopWindows(false, onScreenWindowsOnly: false) else { die("no screen content: Screen Recording permission?") }
    guard let w = c.windows.first(where: { $0.windowID == wid }) else { die("no window \(wid)") }
    return w
}

final class Rec: NSObject, SCStreamOutput {
    let writer: AVAssetWriter, input: AVAssetWriterInput
    var started = false
    init(out: String, w: Int, h: Int) {
        try? FileManager.default.removeItem(atPath: out)
        writer = try! AVAssetWriter(outputURL: URL(fileURLWithPath: out), fileType: .mp4)
        input = AVAssetWriterInput(mediaType: .video, outputSettings: [AVVideoCodecKey: AVVideoCodecType.h264, AVVideoWidthKey: w, AVVideoHeightKey: h,
            AVVideoCompressionPropertiesKey: [AVVideoAverageBitRateKey: 40_000_000]])
        input.expectsMediaDataInRealTime = true
        writer.add(input)
    }
    func stream(_ s: SCStream, didOutputSampleBuffer b: CMSampleBuffer, of t: SCStreamOutputType) {
        guard t == .screen, b.isValid,
              let att = (CMSampleBufferGetSampleAttachmentsArray(b, createIfNecessary: false) as? [[SCStreamFrameInfo: Any]])?.first,
              let st = att[.status] as? Int, st == SCFrameStatus.complete.rawValue else { return }
        if !started { writer.startWriting(); writer.startSession(atSourceTime: b.presentationTimeStamp); started = true }
        if input.isReadyForMoreMediaData { input.append(b) }
    }
}

func config(_ w: SCWindow, _ size: String?) -> SCStreamConfiguration {
    let c = SCStreamConfiguration()
    let wh = (size ?? "\(Int(w.frame.width))x\(Int(w.frame.height))").split(separator: "x").map { Int($0)! }
    c.width = wh[0]; c.height = wh[1]
    c.minimumFrameInterval = CMTime(value: 1, timescale: 60)
    c.showsCursor = false
    c.queueDepth = 8
    return c
}

func main() async throws {
    switch a.count > 1 ? a[1] : "" {
    case "list":
        let l = CGWindowListCopyWindowInfo([.optionAll], kCGNullWindowID) as! [[String: Any]]
        for w in l where (w[kCGWindowLayer as String] as? Int) == 0 {
            let b = w[kCGWindowBounds as String] as? [String: Any] ?? [:]
            print(w[kCGWindowNumber as String]!, w[kCGWindowOwnerPID as String]!, "\(b["Width"] ?? 0)x\(b["Height"] ?? 0)", w[kCGWindowIsOnscreen as String] ?? 0, w[kCGWindowOwnerName as String] ?? "", w[kCGWindowName as String] ?? "")
        }
    case "front":
        print(NSWorkspace.shared.frontmostApplication?.processIdentifier ?? 0)
    case "activate":
        NSRunningApplication(processIdentifier: pid_t(a[2])!)?.activate()
    case "guard":
        let back = pid_t(a[3])!, end = Date().addingTimeInterval(Double(a[4])!)
        while Date() < end {
            if let f = NSWorkspace.shared.frontmostApplication, f.localizedName == a[2] || f.executableURL?.lastPathComponent == a[2] {
                NSRunningApplication(processIdentifier: back)?.activate()
                print(String(format: "%.1f", end.timeIntervalSinceNow), "front given back"); fflush(stdout)
            }
            usleep(50_000)
        }
    case "key":
        let pid = pid_t(a[2])!
        for name in a.dropFirst(3) {
            guard let k = keycodes[name] else { die("unknown key \(name)") }
            for down in [true, false] {
                CGEvent(keyboardEventSource: nil, virtualKey: k, keyDown: down)!.postToPid(pid)
                usleep(down ? 300_000 : 400_000)   // the game polls DirectInput once a frame
            }
        }
    case "rec":
        let w = await window(UInt32(a[2])!), secs = Double(a[3])!, c = config(w, a.count > 5 ? a[5] : nil)
        let r = Rec(out: a[4], w: c.width, h: c.height)
        let s = SCStream(filter: SCContentFilter(desktopIndependentWindow: w), configuration: c, delegate: nil)
        try s.addStreamOutput(r, type: .screen, sampleHandlerQueue: DispatchQueue(label: "rec"))
        try await s.startCapture()
        try await Task.sleep(nanoseconds: UInt64(secs * 1e9))
        try await s.stopCapture()
        r.input.markAsFinished()
        await r.writer.finishWriting()
        if !r.started { die("no frames") }
    case "shot":
        let w = await window(UInt32(a[2])!)
        let img = try await SCScreenshotManager.captureImage(contentFilter: SCContentFilter(desktopIndependentWindow: w), configuration: config(w, nil))
        let rep = NSBitmapImageRep(cgImage: img)
        try rep.representation(using: .png, properties: [:])!.write(to: URL(fileURLWithPath: a[3]))
    default:
        die("usage: macwin list | front | activate PID | key PID NAME... | rec WID SECS OUT.mp4 [WxH] | shot WID OUT.png")
    }
}

Task { do { try await main() } catch { die("\(error)") }; exit(0) }
dispatchMain()
