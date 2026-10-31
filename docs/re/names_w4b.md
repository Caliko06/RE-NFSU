# Names wave 4b (120 functions)

Source: census/names_w4b.tsv. Tools: Ghidra dossiers (/root/re/dossiers), live Ghidra decompile, and a scan of pc/Speed.exe data for the screen factory table (0x6f9c20..) and vtables. V = 10, I = 109, U = 1 (0x4b0150).

## What we learned

- The front-end screen table in .data (about 0x6f9c20, entries hash, name pointer, Create function) names every FNG screen; the ctor is the function Create calls. This named 7 screen constructors for certain (online screens, DummyMagazine).
- In a screen vtable the slot right after FEScreen::MessageStub is the message handler (NotificationMessage); the entry before the handler is the scalar deleting dtor, which names its dtor body.
- Race and online code: StyleItem::UpdateNearMiss (0x43f630) tracks a CollisionBodyWitness pair that involves the player car and fires StyleItem::Trigger when it separates without contact; StyleItem::OnCollision (0x43fbb0) resets the chain on wall or two-car hits.
- Physics: World::ProcessContacts (0x420380) is the collision phase of World::Step (broadphase, TestForContact list, time-budgeted contact processing); PhysicsMover::SolveWheelContacts (0x478570) relaxes the 4 wheel forces 5 times against chassis mass and inertia; Contact::ResolveImpulse (0x46bae0) is the impulse response.
- Many D3DX back-end passes (0x5fd5b7..0x617905) are generic and only named by position in the shader compiler; they are I, not understood in detail.

## assets

| addr | name | conf |
|---|---|---|
| 0x4454d0 | SolidRef::SolidRef | I |
| 0x47c310 | IntroNisCoordinator::CreateAnimControllers | I |
| 0x53f220 | StrmHdrRes::Create | I |
| 0x644b88 | RCMP::AV_PLAYER::Init | I |
| 0x6453b2 | RCMP::AV_PLAYER::CreateDecoders | I |

## audio

| addr | name | conf |
|---|---|---|
| 0x654b50 | SNDSYSI_InitChannelTables | I |

## audio.engine

| addr | name | conf |
|---|---|---|
| 0x525c10 | EAXTunerCar::EAXTunerCar | I |
| 0x5272f0 | EAXTunerCar::PlaySparkChatter | I |
| 0x529100 | EAXShifting::PlayUpShiftSnd | I |
| 0x535530 | EAXTunerCar::DtorBase2 | I |

## camera

| addr | name | conf |
|---|---|---|
| 0x423530 | Race::IntroNisStage::OnMessage | I |
| 0x42ae50 | PreviewComet::PreviewComet | I |
| 0x42b040 | PreviewComet::~PreviewComet | I |
| 0x47d940 | Camera::BuildNoiseRotation | I |
| 0x480ff0 | DragCamera::ComputeOrbitTransform | I |
| 0x482230 | DragCameraManager::HandleAction | I |
| 0x4922c0 | ZonePreviewCameraMover::~ZonePreviewCameraMover | I |
| 0x492700 | ZonePreviewCameraMover::Update | I |
| 0x4936e0 | ZonePreviewCameraMover::EvalSplinePath | I |

## canon

| addr | name | conf |
|---|---|---|
| 0x4151c0 | Screen_PC_Graphics::UpdateResolutionList | I |
| 0x415300 | Screen_PC_Graphics::HandleMouse | I |
| 0x4e6ac0 | Screen_PC_MenuBar::RegisterEntries | I |

## car

| addr | name | conf |
|---|---|---|
| 0x43f630 | StyleItem::UpdateNearMiss | I |
| 0x43fbb0 | StyleItem::OnCollision | I |
| 0x46bae0 | Contact::ResolveImpulse | I |
| 0x472950 | CollisionBodyWitness::RefreshSeparation | I |
| 0x472cf0 | CarShape::CloneFrom | I |
| 0x5894e0 | Skid::AddPoint | I |

## car.garage

| addr | name | conf |
|---|---|---|
| 0x4b0150 | Unk_garage_4b0150 | U |
| 0x4e2a00 | GarageVinylLayerScreen::GarageVinylLayerScreen | I |
| 0x4e3060 | GarageVinylLayerScreen::PositionHighlight | I |
| 0x4e3320 | GarageVinylLayerScreen::NotificationMessage | I |
| 0x4e3b10 | GarageVinyl_FindNextUnlockedPart | I |
| 0x4e3f40 | GarageVinyl_FindFirstUnlockedPart | I |

## car.physics

| addr | name | conf |
|---|---|---|
| 0x475d00 | Mellovator::ApplyForces | I |

## gameflow

| addr | name | conf |
|---|---|---|
| 0x4b59b0 | QuickRace::FillRaceSetupFromOptions | I |

## hud

| addr | name | conf |
|---|---|---|
| 0x40bef0 | Poly2D::DrawQuad | I |
| 0x41f240 | FEMenuData::HandleCursorBlink | I |
| 0x49f000 | Screen_RewardPopup::ShowReward | I |
| 0x4b8e60 | Screen_MU_QuickRaceOptions_PC::SetupOptionRows | I |
| 0x4bb1c0 | Screen_MU_MultiTrack::NotificationMessage | I |
| 0x4f0700 | cFEng::QueueMessageNode | I |
| 0x4f6c80 | FEng_IsScriptRunning | I |
| 0x4f6d10 | FEObject::GetTopLeft | I |
| 0x4f7000 | FEObject::SetTopLeft | I |
| 0x4f7140 | FEObject::SetPositionXY | I |
| 0x5024b0 | FEPackage::LoadResponses | I |

## input

| addr | name | conf |
|---|---|---|
| 0x5740b0 | InputEvents::RemoveSource | I |

## online

| addr | name | conf |
|---|---|---|
| 0x43af80 | OnlineManager::BeginRaceStart | I |
| 0x43cb60 | Net_WriteRideSetupBits | I |
| 0x43d3d0 | OnlineManager::HandlePeerUpdate | I |
| 0x43d4f0 | OnlineManager::CheckPeerTimeout | I |
| 0x43da90 | OnlineManager::IsRaceEndWaitOver | I |
| 0x4eb7c0 | Screen_MU_Online_WarningDialog::Screen_MU_Online_WarningDialog | V |
| 0x546980 | Net_HostStartRaceWhenAllReady | I |
| 0x547770 | Net_BroadcastBitStream_Type06 | I |
| 0x547c60 | Net_SendPlayerStatePacket | I |
| 0x548250 | Net_HandleRaceSetupPacket | I |
| 0x54be20 | Online::HandleChatMessage | I |
| 0x54dd30 | Online::BuildClientInfoString | I |
| 0x550830 | OnlineGameRoom_PlayerList::OnlineGameRoom_PlayerList | I |
| 0x550d00 | Screen_MU_OnlineGameRoom::Screen_MU_OnlineGameRoom | V |
| 0x551280 | Screen_MU_OnlineGameRoom::NotificationMessage | I |
| 0x5534a0 | Screen_MU_OnlineGameRoom::InitChatBox | I |
| 0x554730 | Screen_MU_OnlineGameRoom::UpdatePlayerSlots | I |
| 0x556460 | Screen_MU_OnlineGameRoom::HandleReply | I |
| 0x556e70 | Screen_MU_OnlineMenu::Screen_MU_OnlineMenu | I |
| 0x5583f0 | Screen_MU_Online_CreateAccount_StepOne::Screen_MU_Online_CreateAccount_StepOne | V |
| 0x55a610 | Screen_MU_Online_AnotherAccount::Screen_MU_Online_AnotherAccount | V |
| 0x55b6d0 | Screen_MU_Online_ParentalEmailRequired_PC::Screen_MU_Online_ParentalEmailRequired_PC | V |
| 0x55da00 | Screen_MU_Online4PlayerGameDialogueBox::OnReplyCancel | I |
| 0x55ec30 | Screen_MU_Online_RankingsBoard::Screen_MU_Online_RankingsBoard | V |

## physics

| addr | name | conf |
|---|---|---|
| 0x420380 | World::ProcessContacts | I |
| 0x478570 | PhysicsMover::SolveWheelContacts | I |
| 0x584b80 | ChildBody::SetPlacement | I |

## raceai

| addr | name | conf |
|---|---|---|
| 0x45cb00 | Path::CheckLaneOverlapAhead | I |

## render

| addr | name | conf |
|---|---|---|
| 0x5b982e | D3DX_Compiler_Dtor_5b982e | I |
| 0x5c55ad | D3DX_Preproc_Dtor_5c55ad | I |
| 0x5da7de | D3DX_HlslGen_EmitIntrinsic_5da7de | I |
| 0x5dad99 | D3DX_HlslGen_EmitIntrinsic_5dad99 | I |
| 0x5db2b5 | D3DX_HlslGen_EmitIntrinsic_5db2b5 | I |
| 0x5dbae8 | D3DX_HlslGen_EmitVectorOp_5dbae8 | I |
| 0x5dbe7e | D3DX_HlslGen_ApplyNodeFlags | I |
| 0x5e7078 | D3DX_Asm_AddNamedSymbol | I |
| 0x5fc336 | D3DX_Ps1Back_AssignRegisters | I |
| 0x5fd5b7 | D3DX_Ps1Back_Pass_5fd5b7 | I |
| 0x5ff66c | D3DX_Back_Pass_5ff66c | I |
| 0x602b94 | D3DX_Ps1Back_Pass_602b94 | I |
| 0x6047ce | D3DX_Back_Pass_6047ce | I |
| 0x604fb1 | D3DX_Back_Pass_604fb1 | I |
| 0x60ed62 | D3DX_Back_Pass_60ed62 | I |
| 0x617905 | D3DX_Back_Pass_617905 | I |

## runtime

| addr | name | conf |
|---|---|---|
| 0x417560 | LinkedListPair::FreeAll | I |
| 0x5721f0 | ReplayManager::Update | I |
| 0x641a90 | EAsys_Event_Signal | V |
| 0x6497c0 | Util_ReturnThis_6497c0 | V |
| 0x673fda | CRT::setlocale_get_all | I |
| 0x67593c | CRT::freeptd | I |
| 0x67f34b | CRT::TestDefaultLanguage | I |

## track

| addr | name | conf |
|---|---|---|
| 0x579c00 | AnimController::UpdateSpaceNode | I |
| 0x590dd0 | TrackMap::ProjectQuadCorners | I |

## ui

| addr | name | conf |
|---|---|---|
| 0x4b1c50 | GarageMainScreen::HideObject_3b7f8ae | I |
| 0x4bba40 | Screen_MU_TrackMapScroller::SetMapTextures | I |
| 0x4c3120 | CarSelect_UpdateBrandBanner | I |
| 0x4c9850 | Screen_MU_PlayerLogin::~Screen_MU_PlayerLogin | I |
| 0x4ca670 | Screen_MU_PlayerLogin::LoadProfilesState | I |
| 0x4cdea0 | Screen_MU_Pause_PC::BuildMenuForMode | I |
| 0x4ce370 | Screen_MU_Pause_PC::InitOptionButtons | I |
| 0x4d5cf0 | Screen_EA_TRAX_Jukebox::PushRowObject | I |
| 0x4dae20 | Screen_PC_ColorPicker::~Screen_PC_ColorPicker | I |
| 0x4dafa0 | Screen_PC_ColorPicker::NotificationMessage | I |
| 0x4e1290 | Screen_MU_MultiplayerCarSelect::NotificationMessage | I |
| 0x4e1d70 | MPChooseGarageScreen::FindSlotObjects | I |
| 0x4f8000 | FEScreen::BuildObjectPresenceMask | I |
| 0x4f87f0 | FEListBox::UpdateScrollArrows | I |
| 0x4f9b70 | Screen_MU_HorizontalBrowserBack::SetPageState | I |
| 0x4fd3d0 | FEListBox::ResizeCellArrayA | I |
| 0x4fd5e0 | FEListBox::ResizeCellArrayB | I |
| 0x513780 | Screen_DummyMagazine::Screen_DummyMagazine | V |
| 0x51bb50 | UndergroundMagazineScreen::UnloadMagazineTextures | V |
