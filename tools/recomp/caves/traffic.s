# Traffic caves at 0x63b270 (dead CRT routine: no call/jmp rel32 and no pointer reaches 0x63b270..0x63b3bf).
# Regenerate: tools/recomp/asm.py asm 0x63b270 tools/recomp/caves/traffic.s  (hex -> patches.py, PATCH 0x57d060 block).
# [0x1301c] = SCREEN_ADDR+28, written by win32_init: 1 = this traffic, 0 = the original (RN_TRAFFIC=0).

# Data first, at fixed addresses 0x63b270..0x63b27f (the code reads them by absolute address).
# Every tuner row but LANCER (no paints): 19 x 5/19 = 5 of 20 total weight, so 1 traffic car in 4 is a tuned racer in a career preset (host/free.c free_traffic), OWNER 2026-11-04.
stock:  .long 0x000fdfff
wstock: .float 0.21052632
kmin:   .float 0.85
kspan:  .float 0.0011764706

# Weight of type row ecx (pick loop 0x57d0c1); same as below.
w_ecx:
    push eax
    mov eax, ecx
    call w_eax
    pop eax
    ret

# Weight of type row eax (sum loop 0x57d060), was fld [eax+esi*4+0xc60] (esi = district).
# Traffic rows (usage 2) that the game weights in any district get 1.0 in every district (12 normal types; BUS,
# AMBULANCE, FIRETRUCK stay 0). Racer rows (usage 0, let in by iter below) get WSTOCK if their type id is in STOCK.
w_eax:
    cmp dword ptr [0x1301c], 0
    jne 1f
    fld dword ptr [eax + esi*4 + 0xc60]
    ret
1:  push edx
    mov edx, dword ptr [eax + 0xc54]
    test edx, edx
    jz 2f
    mov edx, dword ptr [eax + 0xc60]
    or edx, dword ptr [eax + 0xc64]
    or edx, dword ptr [eax + 0xc68]
    or edx, dword ptr [eax + 0xc6c]
    or edx, dword ptr [eax + 0xc70]
    jz 3f
    fld1
    pop edx
    ret
2:  mov edx, dword ptr [eax + 0xc50]
    cmp edx, 31
    ja 3f
    bt dword ptr [0x63b270], edx
    jnc 3f
    fld dword ptr [0x63b274]
    pop edx
    ret
3:  fldz
    pop edx
    ret

# Iterator 0x57cfa0 row test, was mov ecx,[eax+0xc54]; cmp ecx,esi; jne 0x57cfed (esi = wanted usage).
# The traffic pick (wanted 2, its only caller 0x57d000) also accepts racer rows (usage 0); the d9 > 0 skin test stays.
iter:
    mov ecx, dword ptr [eax + 0xc54]
    cmp ecx, esi
    je 4f
    cmp dword ptr [0x1301c], 0
    je 5f
    test ecx, ecx
    jne 5f
    cmp esi, 2
    jne 5f
4:  JMPA 0x57cfd1
5:  JMPA 0x57cfed

# Count, was movsx edx, byte [ecx+edi*2+0xc0] at 0x4b3b01 (trackinfo traffic count, 12 on most tracks): x1.5, at most 55
# (rides cap 64 at 0x4322a0, 1 player + 8 rivals).
count:
    movsx edx, byte ptr [ecx + edi*2 + 0xc0]
    cmp dword ptr [0x1301c], 0
    je 6f
    lea edx, [edx + edx*2]
    sar edx, 1
    cmp edx, 55
    jle 6f
    mov edx, 55
6:  ret

# Desired speed of a traffic car, at the two calls of 0x5a6b00 (speed of the lane path at a distance: node byte +0x6a via
# 0x5a7690) in the traffic driver 0x583910 (class of ctor 0x582f90, vtable 0x6b96b0; racers use 0x5a6ef0 from 0x462b30).
# esi = that car's AI object, so x(0.85 .. 1.15) from a hash of esi stays the same for the car's whole life.
drive:
    push dword ptr [esp + 4]
    CALLA 0x5a6b00
    cmp dword ptr [0x1301c], 0
    je 8f
    push eax
    mov eax, esi
    imul eax, eax, 0x9e3779b1
    shr eax, 24
    push eax
    fild dword ptr [esp]
    pop eax
    fmul dword ptr [0x63b27c]
    fadd dword ptr [0x63b278]
    fmulp st(1), st
    pop eax
8:  ret 4
