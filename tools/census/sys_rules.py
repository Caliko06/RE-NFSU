"""String and prose rules for tools/census/systems.py. Each rule: (system, weight, regex). First match wins.
weight 3 = a string only that system uses; 1 = a hint. Strings come from pc/Speed.exe itself (not guesses)."""
import re

R = lambda s, w, rx: (s, w, re.compile(rx))

# string-address bands (the string pool follows link order): (lo, hi, system)
BANDS = [(0x69a000, 0x6a8000, 'render'), (0x6a9000, 0x6b2000, 'runtime'), (0x6b2000, 0x6b5000, 'assets'), (0x6d2000, 0x6d4000, 'runtime')]

STRING_RULES = [
    # --- specific families first ---
    R('canon', 3, r'^MAGAZINE|^MAG_ICONS|^eGAME_TIP|GAME_TIP|^UnHighlight|^Highlight|^MultiTrack|Slider|^MU_UG|^MU_Pause|Pause'),
    R('audio', 3, r'\.csi$|\.CSI$|^Evt_Sys|EvtSys|EVTSYS|SNDSYS|Audio|AUDIO|AyncAudio|Volume|SND_|STRM_|^TURBO\\|^NOS\\|SKIDS_|IMPACT_MB|shifting_'),
    R('assets', 3, r'^Loaded\w*SlotPool'),   # pool of loaded resource packs, not a generic container
    R('hud', 3, r'^3rdperson_|^3RDPERSON|3rdPerson|driftometer|Turbolines'),
    # --- online (out of scope but must be told apart) ---
    R('online', 3, r'^MU_Online|Online|ONLINE|ps2nfs|\bea\.com|GameRoom|@server|^/tell|kicked out|http://|lobby|Lobby|\bping\b|netw|NETW|socket|^tuamMaster|^MU_MP|MPChoose'),
    # --- embedded middleware: D3DX effect compiler, shader assembler (render); libjpeg (assets); rcmp mad codec (canon movies) ---
    R('render', 3, r'^ID3DX|D3DX8|D3DX|^(vs|ps)(_|\.)\d|^(vs|ps)$|^tex(m\d|ld|crd|reg|dp3|kill|bem|cube|Cube|CUBE|2D|3D)|^TEXCOORD|^TEXCOORDSIZE|VERTEXSHADER|PIXELSHADER|^CLIPPLANE|^BUMPENV|^ZFUNC|STENCIL|^ALPHAARG|^COLORARG|^COLOROP|^ALPHAOP|^COLORWRITE|^MODULATE|^ADDSIGNED|^DOTPRODUCT|^BLENDTEXTURE|^SRCALPHA|^DESTALPHA|^FOG|^DITHER|^NORMALIZENORMALS|^MATERIAL(EMISSIVE|AMBIENT|DIFFUSE|SPECULAR)|^LIGHT(ATTEN|THETA|PHI|RANGE|FALLOFF)|^(AMBIENT|DIRECTIONAL|MINFILTER|MAGFILTER|MIPFILTER|POINTSPRITE|PSIZE|XYZRHW|XYZB|INDEXEDVERTEX|ADAPTIVETESS|CAMERASPACE|VIEWTRANSFORM|TEXTURETRANSFORM|SELECTARG)|^POINTSCALE|register|semantic|sampler|swizzle|instruction|identifier|shader|Shader|compiler|expression|unreferenced|unable to (emm|match)|cannot (map|match|bind|read|perform|quant|write|use|resolve|assign|convert|declare)|texcoord|dimension|\bmodifier|pragma|initializer|template|struct$|^float|^int(eger)?$|^vector$|^matrix|^sampler|texture\d|^SPECULAR|FilterTexture|EAGL|SHP%d|Gouraud|^D3DCOLOR|^transpose|^vFace|^oDepth|^break_c|^technique|^pass$'),
    R('assets', 3, r'JPEG|JFIF|jpeg|Sampling factors|Invalid SOS|Premature end|Huffman|quantiz|Quantiz|Application transferred|Invalid memory pool|\.(BUN|LZC|TPK|DDS|bun|lzc|dds|BIG|big)\b|^GLOBAL\\|^FRONTEND\\|^FRONTB|jdlz|JDLZ|compress|Decompress|DYNTEX'),
    R('canon', 3, r'^src/|RCMP|avplayer|rcmp|\.mad\b|\.MAD\b|MOVIES|\.vp6|VP6|ICON_FMV|FMV|^IntroFMV|bink|Bink|NIS|^LANGUAGES\\|^LANG_|LS_.*\.fng'),
    # --- audio ---
    R('audio', 3, r'\.(abk|ABK|ast|AST|mus|MUS|asf|vag|mpc)\b|^SND|SND:|SNDAUTHOR|SND |^SPCH|EAX|EA_?Trax|EATrax|Jukebox|AUDIOBAHN|Audiobahn|PlayStream|Proc Stream|^FE_SOUND|SoundObj|Sound Obj|BridgeWarningSound|m_Snd|_MB$|^FX_SHIFT|SparkChatter|Road Noise|Breaking Effect|AUDIO|Mixer|Speech|speech|Sound|sound|DSound|dsound|\bwav\b|\.wav|Engine Idle|Doppler|DOPPLER|reverb|Reverb|music|Music|^WIND_\d'),
    # --- input ---
    R('input', 3, r'^JOY_|^JOYLOG|joystick|Joystick|^KB_|Keyboard|keyboard|DINPUT|DirectInput|ForceFeedback|Force Feedback|^FEPad|FFB|^Menu (Up|Down|Left|Right|Rotate|Select|Back)|ButtonMap|^Button$|rumble|Rumble|[Gg]ear ?(up|down|shift)|^Steer'),
    # --- camera ---
    R('camera', 3, r'Camera|CAMERA|^CAM_|^SpeedCam|Bumper Cam|^POV|Pursuit Cam|Chase|flyby|FlyBy|CameraMover|^Debug Cam|HoodCam|^ZoomIn'),
    # --- hud (2D in-race UI) ---
    R('hud', 3, r'^HUD_|Gauge|^NOS_bar|nos_lines|Tach|Speedo|speedo|[Mm]ini[Mm]ap|^score_|LapText|LapNumber|BestLap|SplitTime|Style_Point|drift_multiplier|RacePositionNth|PLAYER_HUD|heat_fill|Shift_light|Chyron|Vignette|3rdPerson(Needle|Speed)|^Bar\d_|Backing_P|PlayersName|CarName_P|^smoke_show|^smoke_shape|^smoke_.*(text|icon)|Needle|needle|Countdown|countdown|NoWrongWay|NO_WRONG_WAY|WrongWay|^RightArrow|^LeftArrow|ArrowPick|MARKER_|TrackMap|SPEEDTRAP|Speedtrap|POSITION|^PositionQuant'),
    # --- traffic ---
    R('traffic', 3, r'[Tt]raffic|TRAFFIC|cross traffic'),
    # --- rivals / race manager / ai ---
    R('rivals', 3, r'^AIAction|^AI[A-Z]|^RC_|^RCSTATE|^RaceParam|RACE_STAGE|PLAYER_MODE|MODE_RACE|Opponent|OPPONENT|Racer|RACER|Get Unstuck|Linespeed|Must brake early|Force Race Finish|RaceStart|RACE_|REPLAY|Replay|^eRACE|RaceCoord|AutoPilot|Autopilot|Rubber|rubberband|Catchup|catchup'),
    # --- car / garage / customisation / tuning / physics ---
    R('car', 3, r'^DECAL|_DECAL|DECAL_|^VINYL|^CUSTOM\d|WINDSHIELD|^RIM_|RIMS|PAINT|^WRAP\d|_KIT|^HAS_(PERF|VIS)|^VISUAL_|UPGRADE|Upgrade|^MOD_DESC|MODIFIED|^CARS\\|^CARS$|^CARFX|CULLABLE_CAR|^ZPM_Car|^Car_\d|_BODY|_DOOR|_GLASS|_HOOD|SKIRT|WIDEBODY|GTWING|PERF_|_PERF|TIRE|Eng_UG|ENGINE|Engine|engine|ABS_|Shock|Suspens|Drivetrain|[Bb]rake|BRAKE|EBrake|Throttle|Turbo|TURBO|\bNOS\b|NITROUS|Nitrous|^MU_Garage|Garage|GARAGE|CarSkin|CarState|CarLoader|CarWorldObject|NEON|SPOILER|Spoiler|exhaust|EXH|C\dU\d_M\d|CARSELECT|^CAR_|CAR_THUMB|Gearbox|gearbox|Horsepower|horsepower|Tire|SANDWICH|^[A-Z]+_WHEEL|WHEEL|Wheel|FLAGS\d|FLAMES|LIGHTNING|TRIBAL|MODERN|STRIPES|TEAR|SPLASH\d|WILD\d|DREADS|PEARL|ROUGH|Collision ?Body|CollisionBody|GJK|Witness|PhysMov|Dynamics|DYNAMICS|AllCollision|AllCars|ALLCARS|HEADLIGHT|Headlight|TAILLIGHT|Taillight|Brakelight|BRAKELIGHT|INTAKE|Intake|^02_FAN|^IT\d|^FR\d|^GR\d|^XO_|KNENGINEERING|WILLWOOD|^\d+_KIT|^\d+(RED|BLUE)|^\d{3}[a-z]+'),
    # --- track / world ---
    R('track', 3, r'^TRACKS?\\|^TRACK_|^TRACKS?$|Track Streaming|Streamer|STREAMER|[Zz]one|ZONE|[Cc]ollision|COLLISION|[Ss]ection|SECTION|[Ss]cenery|SCENERY|\bROAD|[Rr]oad|Bridge|DrawBridge|[Ww]ater|WATER|Intersection|INTERSECTION|WorldGeometry|Subworld|SubWorld|NODE|[Ll]ane|LANE|[Bb]arrier|[Ss]kybox|SKY|[Ss]ky\b|[Ww]eather|[Rr]ain\b|puddle|PUDDLE|XETT|Shadow Zone|\\World\\|World\\|Location\d|GeometryStream|TopologySlot|Topology|Reverse|REVERSE|DEEPWATER|DIRT|SAND|GRASS|CONCRETE|ASPHALT|GRAVEL|MUD\b'),
    # --- render (effects, lights, particles) ---
    R('render', 2, r'[Pp]article|PARTICLE|[Ss]moke|SMOKE|[Ss]park|[Bb]lur|BLUR|[Bb]loom|[Ll]ens|[Ff]lare|FLARE|[Rr]eflect|REFLECT|ENVMAP|[Ee]nvmap|[Ss]hadow|SHADOW|GLOW|[Gg]low|\.efx|^fx\\|^FX_|[Tt]exture|TEXTURE|(?<![Hh]igh)[Ll]ight|LIGHT|[Vv]ertex|[Vv]iewport|Render|render|[Aa]lpha|ALPHA|Material|material|MATERIAL|Gloss|GLOSS|FXMGR|SpecularPower|CUBE|[Pp]ixel|Frame ?[Bb]uffer|Interleaved|VAPOR|STREET_GLOW|[Ll]ightning|Mip|MIP|Heat|HEAT|HAZE|[Hh]aze|DEPTH|Depth|Windscreen|Wiper|Rain|CLAMP|MIRROR|WRAP$|NOT DRAWING'),
    # --- canon (career, frontend menus, text, save) ---
    R('canon', 3, r'^MU_|\.fng|\.FNG|Screen$|Dialog|DIALOG|^GAMEFLOW|GameFlow|CAREER|Career|PROFILE|Profile|^PLAYERNAME|PLAYERCARNAME|\bSAVE|Save|Loading|LOADING|^eGAME_TIP|GAME_TIP|MAGAZINE|MAG_ICONS|^EVENT|^Option|OPTION|menubar|^DISC_DATA|DATA_\d|FEPackage|FEEPoly|FrontEnd|FRONTEND|Frontend|Language|^%s_(WID|DEC|SHA|SKI|BAD)|^MENU|Menu|^PC_|^LS_|^HELP|Tutorial|TUTORIAL|^BOOT|loading_|^GENERIC|Generic|Tip|^CARSELECT|StyleAndSkill|REWARD|Reward|Underground|UNDERGROUND|Unlock|UNLOCK|Persona|PERSONAS|^SP_|^IT_|Points|Cash|CASH|Bounty|Cheat|CHEAT|Be the|^I just|Smashing|^Not Bad|Fastest|Faster|Faster|About a|Natural Selection|Exodus|Dilated|Andy Hunter|Takashi|Brian|Mack-D|Samantha|Jared|MELISSA|Scott|Stewart|PsychoDriver|konopa'),
    # --- runtime ---
    R('runtime', 3, r'_Crt|CRT|^R60\d\d|runtime error|abort|Assertion|assert|SlotPool|[Mm]alloc|HeapAlloc|EMS|frexp|isfinite|QNAN|INF$|1#|LC_|^Get[A-Z]\w+|^Set[A-Z]\w+|\.dll$|kernel32|user32|Software\\|HARDWARE\\|ISMMX|ISSSE|MMX|GenuineIntel|AuthenticAMD|DisableMMX|speed\.exe|Underground$|NFS Undergroun|\.symtab|Memory|memory|MemoryPool|Pool|Heap|Thread|thread|Mutex|Event$|Semaphore|Critical|std::|vector|virtual|signed|unsigned|while|default|operator'),
    R('runtime', 1, r'^[%0-9 .:\-/,\[\]*xdsfuc]+$'),
]

# prose keywords for docs and patch comments (lower case); (system, weight)
PROSE = [
    ('audio', r'\b(audio|sound|dsound|abk|\.ast|speech|music|mixer|volume|slider)\b'),
    ('render', r'\b(blur|flare|bloom|reflection|envmap|shader|d3d9?|light|lights|particle|render|draw|efx|texture|night|glow|headlight)\b'),
    ('hud', r'\b(hud|minimap|map|gauge|speedo|tach|2d)\b'),
    ('camera', r'\b(camera|cam|jumpcam|fov)\b'),
    ('traffic', r'\b(traffic|trafficai|teleporter)\b'),
    ('rivals', r'\b(rival|rivals|racer|racers|ai|opponent|personality|autopilot)\b'),
    ('car', r'\b(tuning|physics|handling|steer|steering|car|garage|part|parts|upgrade|skin|tire|engine|drivetrain|nos|speed cap|caps)\b'),
    ('track', r'\b(track|zone|zones|stream|streamer|collision|citygraph|city|node|nodes|lane|road|world|mesh|barricade|fence|free run|freerun)\b'),
    ('props', r'\b(prop|props|barricade|sign|cone)\b'),
    ('canon', r'\b(career|event|events|profile|save|menu|frontend|movie|movies|text|language|unlock|reward|magazine)\b'),
    ('input', r'\b(input|keyboard|joystick|pad|dinput|keys?)\b'),
    ('assets', r'\b(bun|lzc|bin|dds|jdlz|loader|file|files|resource|pool)\b'),
    ('runtime', r'\b(crt|memory|heap|thread)\b'),
]
PROSE = [(s, re.compile(rx)) for s, rx in PROSE]

# import -> system.  First regex match on "dll!name" wins; None = no information.
IMPORT_RULES = [
    ('online', 'ws2_32|wsock|tapi32|netapi32|inet|Internet'),
    ('render', 'd3d9|ddraw|d3dx|gdi32'),
    ('input', 'dinput|!GetAsyncKeyState|!GetKeyState|!keybd_event|!GetCursorPos|!SetCursorPos|!ShowCursor|!ClipCursor|!GetKeyboardState|!MapVirtualKey|!SendInput|!ReadConsoleInput|Joy'),
    ('audio', 'dsound|winmm.dll!(waveOut|waveIn|mixer|midi|mci|PlaySound)'),
    ('assets', r'kernel32.dll!(CreateFile|ReadFile|WriteFile|SetFilePointer|GetFileSize|FindFirstFile|FindNextFile|FindClose|GetFileAttributes|SetFileAttributes|CreateDirectory|DeleteFile|MoveFile|CopyFile|GetFileType|SetEndOfFile|FlushFileBuffers|GetFullPathName|GetLongPathName|GetShortPathName|CreateFileMapping|MapViewOfFile|UnmapViewOfFile|LockFile|GetDiskFreeSpace|GetDriveType|GetVolumeInformation|GetLogicalDrive)'),
    ('runtime', r'kernel32.dll!(CreateThread|ExitThread|TerminateThread|Sleep|WaitFor|CreateEvent|SetEvent|ResetEvent|CreateMutex|ReleaseMutex|CreateSemaphore|ReleaseSemaphore|InitializeCriticalSection|EnterCriticalSection|LeaveCriticalSection|DeleteCriticalSection|HeapAlloc|HeapFree|HeapCreate|HeapDestroy|HeapReAlloc|HeapSize|HeapValidate|VirtualAlloc|VirtualFree|VirtualProtect|VirtualQuery|GlobalAlloc|GlobalFree|LocalAlloc|TlsAlloc|TlsGetValue|TlsSetValue|TlsFree|InterlockedExchange|InterlockedIncrement|InterlockedDecrement|GetTickCount|QueryPerformance|GetSystemTime|GetLocalTime|GetSystemInfo|GetVersion|GetModuleHandle|GetModuleFileName|GetProcAddress|LoadLibrary|FreeLibrary|GetCommandLine|GetEnvironment|ExitProcess|GetStartupInfo|SetUnhandledExceptionFilter|UnhandledExceptionFilter|RaiseException|IsDebuggerPresent|OutputDebugString|GetLastError|SetLastError|GetCurrentThread|GetCurrentProcess|GetStdHandle|SetStdHandle|SetHandleCount|GetACP|GetOEMCP|GetCPInfo|MultiByteToWideChar|WideCharToMultiByte|LCMapString|GetStringType|CompareString|FlsAlloc|TerminateProcess|SetErrorMode|CreateToolhelp32|Process32|GetCurrentDirectory|SetCurrentDirectory|FormatMessage|LocalFree|GetProcessHeap|RtlUnwind|GetLocaleInfo|GetUserDefault|GetTimeZone|FileTimeTo|SystemTimeTo|GetExitCode|ReadConsole|SetConsole|GetConsole|Beep|CloseHandle|DuplicateHandle|lstr|MulDiv)|advapi32|shell32|shfolder|netapi32'),
    ('canon', r'user32.dll!(MessageBox|LoadString|GetWindowText)'),
    ('runtime', r'user32|ole32|oleaut32|comctl32|comdlg32|winmm.dll!(timeGetTime|timeBeginPeriod|timeEndPeriod|timeSetEvent|timeKillEvent)'),
]
IMPORT_RULES = [(s, re.compile(rx)) for s, rx in IMPORT_RULES]

# addresses learned in the docs, by file (system for every address of the doc; None = classify each line with PROSE)
DOC_SYSTEM = {
    'docs/re_audio_default.md': 'audio', 'docs/re_minimap.md': 'hud', 'docs/flare_re.md': 'render', 'docs/night_re.md': 'render',
    'docs/traffic_placement.md': 'traffic', 'docs/openworld_e_re.md': None, 'docs/driving_patches.md': None,
    'docs/OPENWORLD.md': None, 'docs/archive/PLAN.md': None, 'docs/coverage.md': None,
    'docs/openworld/re_ai_interact.md': 'rivals', 'docs/openworld/re_rivals_ai.md': 'rivals', 'docs/openworld/re_racer_cap.md': 'rivals',
    'docs/openworld/re_racer_cap_probe.md': 'rivals', 'docs/openworld/re_rival_personality.md': 'rivals', 'docs/openworld/re_rival_turnback.md': 'rivals',
    'docs/openworld/re_citygraph.md': 'track', 'docs/openworld/re_coll.md': 'track', 'docs/openworld/re_mesh.md': 'track', 'docs/openworld/re_stream.md': 'track',
    'docs/openworld/re_zones.md': 'track', 'docs/openworld/world_entry.md': 'track', 'docs/openworld/fences_z.md': 'track',
    'docs/openworld/re_props.md': 'props', 'docs/openworld/re_barricade.md': 'props',
    'docs/openworld/re_freerun_menu.md': 'canon', 'docs/openworld/re_select_picture.md': 'canon', 'docs/openworld/re_hud_free.md': 'hud',
    'docs/openworld/re_trackmap.md': 'hud', 'docs/openworld/re_jumpcam.md': 'camera', 'docs/openworld/re_handling.md': 'car',
    'docs/openworld/re_traffic_racers.md': 'traffic', 'docs/openworld/re_traffic_teleport.md': 'traffic',
    'docs/openworld/re_answers_0b.md': None, 'docs/openworld/audit.md': None, 'docs/openworld/d2.md': None, 'docs/openworld/d3.md': None,
}
# q_*.py topic -> system (file name prefix, first match)
Q_SYSTEM = [
    (r'q_(ai|aispeed|aitraf|aix_|apdrift|apdrive|apon|autopilot|rskill|rgoal|ract|rcsetup|rcslots|unstuck|walker|steer|tlane|nodelane)', 'rivals'),
    (r'q_(career|careerinit|careerpost|careerptr|cevent|creward|evbrief|evdone|eventtab|evtype|fepush|hub|jccall|jcgate|jump|cjump|magazine|mag|magaccept|magscr|magtask|menu|movies|moviep|newcareer|nextstage|options|optsave|optui|pause|postres|profnew|prunload|retscr|rewardpop|saveload|savefiles|stageidx|tourstage|trklist|unlockq|unlocktab|crossfin|dbgfin|forcefin|beatgame|cheats|cheatuse|modes|ug|qr|resetreq|fsm|frame)', 'canon'),
    (r'q_(blur|fxblur|fxrefl|fxshadow|render|carlight|worldflare|hlproj|lscale|styleanim)', 'render'),
    (r'q_(garage|part|partfit|carpick|ccar|ccarpick|phys|drag|tspeed|skilltab|cobj|resetcar)', 'car'),
    (r'q_(coll|owcoll|owcoll2|owstream|owzone|owroad|tsec|owaudit|owprops)', 'track'),
    (r'q_(tpool|tooslow)', 'traffic'),
    (r'q_(mapdraw|mapmode|viewscale|praitems)', 'hud'),
    (r'q_(dinput|keybind)', 'input'),
]

# patches.py PATCH block (first address) -> system, read by hand from the block text (evidence: the comment itself)
PATCH_SYSTEM = {
    0x4f5891: 'canon', 0x40877e: 'render', 0x40bf09: 'hud', 0x4f2f13: 'hud', 0x408a24: 'render', 0x4494c4: 'render',
    0x735ec1: 'canon', 0x702a38: 'render', 0x702a40: 'render', 0x40d615: 'render', 0x702a84: 'render', 0x40debb: 'camera',
    0x56e0d2: 'car', 0x409bdb: 'render', 0x40fbb7: 'render', 0x4470f0: 'runtime', 0x42d4b0: 'rivals', 0x42d4a9: 'rivals',
    0x4609e3: 'car', 0x585b94: 'runtime', 0x4b4321: 'rivals', 0x57119a: 'rivals', 0x4b528d: 'track', 0x4b3c2f: 'traffic',
    0x422b36: 'traffic', 0x598774: 'traffic', 0x5833eb: 'traffic', 0x59a5cf: 'track', 0x59a4b8: 'track', 0x5987f6: 'traffic',
    0x430dbd: 'car', 0x7007ec: 'canon', 0x422a78: 'rivals', 0x422a86: 'rivals', 0x410c1b: 'render', 0x57d060: 'traffic',
    0x598c4b: 'traffic', 0x4aa21e: 'audio', 0x426dd7: 'camera',
}
