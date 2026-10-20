// dsound: for now this PC has no sound card. DirectSoundCreate answers DSERR_NODRIVER, as documented
// for a machine without an audio device. The Web Audio device is a later block.
#include "host.h"

static uint32_t DirectSoundCreate_(Ctx *c) {
    if (ARG(1)) st(c, ARG(1), 0, 4);
    rn_log("dsound DirectSoundCreate -> DSERR_NODRIVER (no sound device yet)");
    return 0x88780078u;
}

const Api dsound_apis[] = {
    {"dsound.dll", "#1", 3, DirectSoundCreate_},
};
const int dsound_api_count = sizeof dsound_apis / sizeof dsound_apis[0];
