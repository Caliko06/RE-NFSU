# Road-graph caves (patches.py "WIDEN"), assembled at CODE_AREA 0x797000 (zero RAM past the image, lifted like .text).
# Regenerate: .venv/bin/python tools/recomp/caves/road_asm.py   (prints the hex that patches.py holds in _ROAD_CODE).
# RB = ROAD_ADDR + 0x810, the road id bound: 100 on retail (the game's own constant), 1 + the highest list-0 section id otherwise.
# Each "@ name addr" line starts a snippet assembled at that address; entries are 0x20 apart.

# @ H 0x797000
# PostLoad 0x4430b0 at 0x443123 (was mov eax,[0x736154]): RB from the section table, then the original instruction and on.
H:
    mov ecx, 99
    xor edx, edx
1:  mov eax, dword ptr [edx*4 + 0x796010]
    test eax, eax
    jz 3f
    cmp dword ptr [eax + 0xc], 0
    jne 3f
    cmp edx, ecx
    jle 3f
    mov ecx, edx
3:  inc edx
    cmp edx, 256
    jb 1b
    inc ecx
    mov dword ptr [0x796810], ecx
    xor ecx, ecx
4:  mov dword ptr [ecx*4 + 0x796410], 0
    inc ecx
    cmp ecx, 256
    jb 4b
    mov eax, dword ptr [0x736154]
    cmp eax, 255
    ja 5f
    JMPA 0x443128
# More than 255 entries: no sort and no remap (their 0x100 byte stack map holds 256). A node's slot byte is then the rank inside
# its source section, EBASE[section] the index of that section's first entry (lowest index wins: walk down). Callee-saved
# registers are free here because the epilogue pops them.
5:  mov ecx, eax
    mov esi, dword ptr [0x736150]
6:  test ecx, ecx
    jz 7f
    dec ecx
    mov edx, ecx
    shl edx, 5
    movzx edx, byte ptr [esi + edx + 0xa]
    mov dword ptr [edx*4 + 0x796410], ecx
    jmp 6b
7:  JMPA 0x443286

# @ C1 0x797080
# 0x59b2f8 loop head, was cmp [ebp-0xc],0x64; jae; mov eax,[ebp-0xc]: flags for the jae that follows, eax = i.
    mov eax, dword ptr [ebp - 0xc]
    cmp eax, dword ptr [0x796810]
    ret

# @ C2 0x7970a0
# 0x599b4a loop head, was cmp [ebp-0xc],0x63; jge; mov eax,[ebp-0xc] (ecx kept).
    push ecx
    mov ecx, dword ptr [0x796810]
    dec ecx
    mov eax, dword ptr [ebp - 0xc]
    cmp eax, ecx
    pop ecx
    ret

# @ C3 0x7970c0
# 0x59af45 loop head, was cmp [ebp-4],0x64; jae; mov eax,[ebp+0xc]: flags of i < RB, eax = [ebp+0xc].
    mov eax, dword ptr [ebp - 4]
    cmp eax, dword ptr [0x796810]
    mov eax, dword ptr [ebp + 0xc]
    ret

# @ R1 0x7970e0
# 0x4627ee, was mov dword [edx],0x63: the racer's last road id (edx = out pointer).
    mov eax, dword ptr [0x796810]
    dec eax
    mov dword ptr [edx], eax
    ret

# @ R2 0x797100
# 0x5836ed, was mov dword [ecx],0x63: the traffic driver's last road id (ecx = out pointer, eax = the first out pointer).
    push eax
    mov eax, dword ptr [0x796810]
    dec eax
    mov dword ptr [ecx], eax
    pop eax
    ret

# @ S 0x797120
# 0x5836d5, was mov [eax],0x64; mov [ecx],0x77: the stub range of the traffic driver. Retail 100..119; with road ids past 100
# the stubs park on id 255, which stays empty.
    cmp dword ptr [0x796810], 100
    je 1f
    mov dword ptr [eax], 255
    mov dword ptr [ecx], 255
    ret
1:  mov dword ptr [eax], 100
    mov dword ptr [ecx], 0x77
    ret

# Entry readers. A node's slot byte k (0xff none) names entry EBASE[node section] + k; EBASE is 0 on retail, so the pointer is then the
# stock [0x736150] + (k << 5). Each cave replaces the 30 (27 at 0x5a6da9) byte block "movzx, cmp 0xff, table add, jmp, xor" and ends in the
# same registers as the stock code (the table base register is overwritten on a hit, untouched on none).

# @ E1 0x797180
# 0x4564bd (walker): node edi, slot index edx, entry ptr or 0 in ebp, eax scratch.
    movzx ebp, byte ptr [edi + edx + 0x81]
    cmp ebp, 0xff
    je 1f
    movzx eax, byte ptr [edi + 0x83]
    add ebp, dword ptr [eax*4 + 0x796410]
    shl ebp, 5
    mov eax, dword ptr [0x736150]
    add ebp, eax
    ret
1:  xor ebp, ebp
    ret

# @ E2 0x7971c0
# 0x5a53f8 (path step): node ecx, slot index ebp, entry ptr or 0 in esi, eax scratch.
    movzx esi, byte ptr [ecx + ebp + 0x81]
    cmp esi, 0xff
    je 1f
    movzx eax, byte ptr [ecx + 0x83]
    add esi, dword ptr [eax*4 + 0x796410]
    shl esi, 5
    mov eax, dword ptr [0x736150]
    add esi, eax
    ret
1:  xor esi, esi
    ret

# @ E3 0x797200
# 0x5a56ce: node ebp, slot index ecx, entry ptr or 0 in eax, edi scratch.
    movzx eax, byte ptr [ecx + ebp + 0x81]
    cmp eax, 0xff
    je 1f
    movzx edi, byte ptr [ebp + 0x83]
    add eax, dword ptr [edi*4 + 0x796410]
    shl eax, 5
    mov edi, dword ptr [0x736150]
    add eax, edi
    ret
1:  xor eax, eax
    ret

# @ E4 0x797240
# 0x5a6da9: node ebp, slot index esi, eax = 0xff, entry ptr or 0 in ecx, edx scratch.
    movzx ecx, byte ptr [esi + ebp + 0x81]
    cmp ecx, eax
    je 1f
    movzx edx, byte ptr [ebp + 0x83]
    add ecx, dword ptr [edx*4 + 0x796410]
    shl ecx, 5
    mov edx, dword ptr [0x736150]
    add ecx, edx
    ret
1:  xor ecx, ecx
    ret

# @ F 0x797280
# FIX 0x458c86 (decider cache 0x458bd0 full, ebp was -1 and the store hit [AIVehicle+8]): count the skipped store at [0x7977f0] (host/crashwatch.c reads
# it) and leave through the epilogue 0x458cb3 that the type-9 exit uses (same stack: ebx, ebp, esi pushed, bl = the answer).
    inc dword ptr [0x7977f0]
    JMPA 0x458cb3
