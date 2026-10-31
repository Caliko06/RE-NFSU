# Names wave 4a (120 unnamed functions, slice A)

Source: Ghidra headless decompile (tools/ghidra/gpar.sh, project /root/ghidra_named) plus the dossiers in /root/re/dossiers; names in census/names_w4a.tsv.
120 rows: I 117, V 3. No U rows: every function got a behaviour-based name; screen classes whose real name is not known carry the address or a role (I).

## What we learned

- FEng queue: the cFEng object keeps a deferred command list (count +0x4128, head +0x412c, tail +0x4130). Node vtable 0x6c2c64, type at +0x14: 1 pop (0x4f09b0), 2 push (UIListNode_Alloc 0x4f08f0), 3 switch (0x4f0800), 4/8 flag change (0x4f0a50). Screens only queue; the FEng update drains.
- FEng helpers pass the package in EAX/ECX and the object hash in EDI/ESI (register ABI), so Ghidra shows no arguments: the string/colour/visibility setters 0x495f00, 0x495f70, 0x4c39d0, 0x4f75b0 all find the object first with FEngFindPackage + FEng_VisitChildrenSEH, then FEng_FindObjectInPackage.
- Career screens reach the 3D garage background through one lookup (0x4b2330 finds the GarageMain package data, 0x4b2480 sets the dramatic camera); the garage show car wheels are rebuilt each frame by 0x4b1760.
- Online race: OnlineManager state 4/5/6 runs TickRaceSync 0x43ac10 -> RankRacers 0x43bfe0 (bubble sort by finished state, time, drift score) -> SendRacerStatePacket 0x43c300; UpdateFinishTimeouts 0x4394f0 forces Race::FinishCar when the countdown after the first finisher runs out.
- Race start: RaceCoordinator::BeginRace 0x421f00 mallocs Race (0x568), World (0x17a0, ctor 0x41f6e0) and queues flow messages 2,1,3 that Race::HandleFlowStep 0x422eb0 executes (streaming seed, SetRaceStage, wait for StreamSections idle).

## Interesting for traffic / AI / car physics

- 0x4576b0 AI::PredictClosestApproachTime: collision look-ahead used by AI::FindClosestAvoidable; walks both cars' DriveTarget polylines (20 points, 0x50-byte records) and returns the earliest time they get close (99999.0 = none). Traffic avoidance candidate.
- 0x4281e0 World::ProcessZoneTriggers: trigger type 0x10006 uses GetNearestTrafficLane and Car_GetLaneSpeedCapFraction (lane distance to the 0x24cebc53 object).
- 0x57d340 RideInfo::FillDefaultParts is called by Race::SpawnTraffic and Race::BuildRandomOpponentRide (default part hashes for traffic and opponent rides).
- 0x46d1c0 DriveTrain::BuildGearSpeedTable (also used by MakeAccelerationTable and RideInfo::ComputeMiscStats), 0x42a860 steer-assist force, 0x47a090 launch assist state machine (DAT_00735fb8), 0x465830 contact impulse accumulation with terrain sound tables, 0x471de0/0x472830 GJK distance and cache.

## runtime (17)

| Address | Name | Conf | Evidence |
|---|---|---|---|
| `0x41f6e0` | `World::World` | I | I: 0x17a0-byte object malloc'd by 0x421f00: sets three empty circular list heads at +0,+8,+0x10, eh_vector_constructor_iterator, then InitSlotPool of CarEmitterPosition/Skid/Clan and Teleporter::InitSpawnRecords, Path::ClearLine;  |
| `0x41f9b0` | `World::~World` | I | I: tears down what 0x41f6e0 builds: List_DeleteAllNodes, FUN_00421900 list releases, PtrList_FreeAllPayloadsAndClear, CollisionBodyWitness::EliminateAllWitnesses, bMemoryPool_Validate, Skid/Clan/Teleporter pool destroy; sole calle |
| `0x421900` | `SlotList::ReleaseAllNodes` | I | I: EDI=circular list head; for every node unlinks it, pushes it on the SlotPool free list (pool+0x10, count pool+0x18 decremented) and destroys the pool when the count reaches 0; 12 callers (cPostRaceScreenManager dtor, HudOnline  |
| `0x421c00` | `RaceCoordinator::QueueMessage` | I | I: SlotPool::Alloc a node, sets [+8]=type [+0xc]=arg and appends it at the tail of the list at this+8/+0xc; same node layout 0x421f00 builds for types 2,1,3 which Race::PumpFlowMessages consumes; callers Player::UpdateFrame and th |
| `0x421f00` | `RaceCoordinator::BeginRace` | I | I: mallocs and builds the race objects (0x50b8-byte 0x571fa0 -> 0x7345d0, Race (0x568 bytes) via Race::Race -> 0x73619c, World (0x17a0) via 0x41f6e0), Grid::PlaceAllRacers, 0x4222a0, picks the race stage/type (9/10/2/4 from 0x78a3 |
| `0x422eb0` | `Race::HandleFlowStep` | I | I: __thiscall(step 1..): 1 = TrackStreamer::ClearStreamingPositions, NIS or normal StreamSections::SeedViewer for the start position (FindNisSceneOriginPosition), shows the FEng package; 2 = FEngStopInteraction and Race::SetRaceSt |
| `0x423f20` | `RaceCoordinator::FinishRaceFlow` | I | I: calls Race::SimulateRaceFinish 0x435a70, cFrontendDatabase::NotifyTheRaceIsOver, checks the player's racing car state (+0x10 == 10) and rank totals, creates cPostRaceScreenManager (CreateInstance) and chooses the first screen w |
| `0x424db0` | `RacerNode::GetField18` | I | I: returns [this+0x18] (this in EAX); sits in the RacerNode getter run 0x424d50..0x424e10 (IsPlayerKind, IsLocalHuman, IsRemote, +0x3c, +0x40, speed +0x3d4); callers DriftManager::UpdateLeaderBoard and the OptionsMenu Setup functi |
| `0x4281e0` | `World::ProcessZoneTriggers` | I | I: __thiscall from World::Step 0x420b40: iterates the WorldZone_Query list and switches on trigger type [+0xc] 0x10003..0x10009 (replay camera 'FlattenFern', 0x10006 uses GetNearestTrafficLane and Car_GetLaneSpeedCapFraction path/ |
| `0x42b0d0` | `Player::Player` | V | V: constructor: zeroes fields, StyleItemTable::StyleItemTable at +0x258 (600), DriftManager::DriftManager, stores itself in the player table 0x7361b4[index], sets up 0x7588c4+index*0xf944 state, HudManager::HudManager(index) for p |
| `0x42fee0` | `Player::SetPreviewComet` | I | I: (id): frees the old PreviewComet at [this+0x130] (DisableEmitters, eh_vector_destructor 0xc0 elements), looks id up in the list at 0x73769c, creates a new PreviewComet (malloc 0x34) when found, then Player::ResetMatrix140, clea |
| `0x4300f0` | `Player::UpdatePreviewComet` | I | I: EBX=player; spawns a preview comet for the next route target when 0x59def0 finds one closer than 0x6b7afc (calls 0x42fee0), then transforms the car and its 4 wheel positions (Car::CalculateWheelPosition, Matrix_InvertRigid, D3D |
| `0x43a2e0` | `OnlineManager::IsActive` | I | I: __fastcall this; returns 1 when byte [+0x1a] is set or counter 0x7354e0 or 0x735500 is above 0; both counters are written by Net_SetState3/4AndBroadcast 0x547560/0x5475c0; sits at the start of OnlineManager (0x43a360 Update); ~ |
| `0x579750` | `WorldObject::WorldObject` | I | I: __thiscall(this, ?, ptr): constructor that allocates a SlotPool object, initializes a CAnimCtrl (0x47b040 InitFields, 0x47b0b0, 0x47b1c0/220/600) and a SpaceNode matrix chain, falls back to the 'DEBUG_CUBE' model when the solid |
| `0x674099` | `CRT::_expandlocale_core` | I | I: same body as VC7 _expandlocale(expr, output, LC_ID*, codepage*): null gives null, 'C' gives output 'C' with zeroed LC_ID and codepage, else __lc_strtolc then ___get_qualified_locale; callers 0x6741c5 and 0x6743e3 (the latter na |
| `0x6741c5` | `CRT::_setlocale_set_cat` | I | I: (category in ESI, locale string): calls 0x674099 to expand the name, strcmp against the current name table 0x6eb694 (stride 12), else saves state, installs the new LC_ID/codepage, swaps the LC_CTYPE tables (case 2, ___crtGetStr |
| `0x6820f2` | `CRT::_chsize_lk` | I | I: (handle, new size): __lseek_lk to end, if the file is shorter writes zero blocks with __write_lk (0x1000 chunk on the stack, _memset), else seeks to the size and truncates with SetEndOfFile (via __get_osfhandle); sets errno/dos |

## car (16)

| Address | Name | Conf | Evidence |
|---|---|---|---|
| `0x4250c0` | `Dtor4250c0::DtorBody` | I | I: __fastcall, 7 bytes: stores vtable 0x6caadc into this; called only from EH unwind stubs of PhysicsMover, Mellovator, MellowMover and 0x463630-class constructors/destructors |
| `0x427c50` | `Car::InitKinematicState` | I | I: (position vec3, speed, heading angle16): Car_SetMode/0x464c80 once, TrackPath::UpdateCursor, writes heading +0x3b4, position +0x60..0x68, speed +0x3d0, GroundQuery::ClearCache, velocity from Vec3_ScaleToLength, speed magnitude  |
| `0x4286a0` | `Car::UpdateTireSurfaceEffects` | I | I: per-wheel loop over flags at +0x350, surface id at +0x354 (table stride 0x94 at 0x6ef328: surfaces 0xd/0xe set a mask), per-wheel slip speed from +0x374 compared with table thresholds 0x6ef32c/0x6ef330 and timers at +0x8ac step |
| `0x42a860` | `PhysicsMover::ApplySteerAssistForce` | I | I: ESI=mover; needs wheels (+0x30), body (+0x34) and +0x1c; when speed [+0x3d4] is inside the clamp 0x6b7c08..0x6b7c0c and +0xb8 >= 0x6cc7b8 it takes LinearTable::Lookup11(table 0x706490, /velocity/), scales by body [+0x144], rota |
| `0x43e310` | `DriftManager::Update` | I | I: per-frame drift scoring: calls CalcDriftIntensity 0x43e540, CalcDriftMultiplier 0x43e790, CalcBonusZoneMult 0x43e6e0, GetCollisionIntensity 0x43e9d0; above the drift-speed gate triggers StyleItem::SetLevel/Trigger and StyleItem |
| `0x43ef30` | `DriftManager::UpdateSpeedGate` | I | I: counts speed gates in [this+0x58] (<7): when speed 0x432c80 exceeds the ModeFlags row [+8] it triggers StyleItem::Trigger(1.0), increments the count and calls FEngHud::SetTrapSpeed; only caller DriftManager::Update 0x43e310 |
| `0x43f240` | `RacingCar::UpdateStyleItems` | I | I: per-frame style/airtime scoring: 0x43f430..0x43fa90 sub-updates (incl. Commentator::ShortcutZoneEntered), StyleItem::Trigger for airtime (MiscStyleManager::IsAirTimeActive, 0x78a310 frame threshold), leader bonus (RaceManager:: |
| `0x465150` | `Car::BuildWheelMatrix` | I | I: EAX=wheel index (0..3), param=car state: builds two 4x4 matrices (identity, Matrix_MultiplyRotationY_Angle16 from _ftol angle, Matrix_RotationZ_Angle16 plus D3DXMatrixMultiply for the front wheels <2), writes the wheel position |
| `0x465830` | `Collision::AddContactImpulse` | I | I: (collision record, contact point, impulse vec3, magnitude): adds the impulse into +0x50..+0x58 and its length into +0x60, stores point/normal, SpecialCamCaller_465d00, then per terrain type table 0x6ef350/0x6ef35c (stride 0x94) |
| `0x46d1c0` | `DriveTrain::BuildGearSpeedTable` | I | I: __fastcall: for each gear (count at [param_3+0x18]) steps the rpm range [EDI[0],EDI[1]] and uses UniformTable::Lookup (torque curve) against the wheel-force line fVar3/fVar2 until the curve drops below it, storing the crossover |
| `0x471de0` | `GJKWitness::ComputeDistance` | I | I: returns the distance (float10) between the two convex bodies using SCEA_GJKsimplexPair (copy ctor 0x4723a0, operator= 0x4724b0, DistanceSqr 0x46ea50), bNormalize3 for the closest-point direction and D3DXVec3Transform for body-s |
| `0x472830` | `GJKWitness::SetBodyTransforms` | I | I: (ESI=witness, EDI=pos A, param_3=pos B): if both positions are within 0x6cc8bc of the cached ones (+0x40..+0x48) and 0x471d60 agrees, keeps the cache, else marks dirty [+0x240]=1; when dirty copies both rotation matrices (bMatr |
| `0x47a090` | `PhysicsMover::UpdateStartAssist` | I | I: (mover, a): one-time init of the globals 0x78f1a4..0x78f1cc (moving average with 0x20 samples) then a state machine in DAT_00735fb8 (0 init, 999 wait until both /velocity/ vectors of the car are zero, 1, 2) that drives car fiel |
| `0x4b1760` | `GarageMainScreen::UpdateShowCarWheels` | I | I: (screen, car obj, mirror flag): uses ride info [+0x114] (wheel table +0x1570), rebuilds physics info once (RideInfo::RebuildPhysicsInfo), builds four 0x40-byte wheel matrices (CallNTimes Util_ReturnThis, Matrix_RotationZ/Multip |
| `0x56c140` | `CarRenderInfo::~CarRenderInfo` | I | I: eh_vector_destructor_iterator over 2 elements of 0xa0 at +0x1ac0 and 2 of 0x68 at +0x19e0 (the Car Lights nodes built by CarRenderInfo::InitCarLightsList 0x5712a0), then frees the list at +0x19d8 node by node; callers Car::Dest |
| `0x57d340` | `RideInfo::FillDefaultParts` | I | I: loops part slots 0..0x22 (skips 6, 0xc and 0x1f..0x22) and writes the default part hash for each; string 'BRAKES' plus the DECAL_*_MEDIUM names (s__s_DECAL_FRONT_WINDOW_WIDE_MEDIUM 0x6f88ac ...) via bStringHashPrintf/BinarySear |

## raceai (3)

| Address | Name | Conf | Evidence |
|---|---|---|---|
| `0x4576b0` | `AI::PredictClosestApproachTime` | I | I: __thiscall(this AI, path A, path B, other car, dt step, out*): turns both cars' DriveTarget points into 20-entry polyline buffers (0x458150, 0x458220/0x458290, DriveTarget::GetFirstPoint), steps both along their paths at the ca |
| `0x45e970` | `PsychoDriver::UpdateControls` | I | I: __thiscall(dt, min 0.0001): reads the car ([this+0x1f0]) speed +0x3d4 with sign of +0x3d0 and the steering angle16 [+0x1d0], per-wheel contact flags at car+0x350, counts down timers [0x87]/[0x81], writes the driver axes [0x77]/ |
| `0x463f20` | `SteerController::Update` | I | I: __thiscall(dt): integrates time [this+0xc], evaluates a path (0x464660 at t and t+offset), derives a steering vector, averages with MovingAverage::AddSample, scales by a table term and writes the result as two float pairs (flag |

## hud (15)

| Address | Name | Conf | Evidence |
|---|---|---|---|
| `0x495f00` | `FEngSetLabelHashByName` | V | V: EAX=package, EDI=object hash; finds the object (FEngFindPackage+FEng_VisitChildrenSEH, else FEng_FindObjectInPackage), if type [+0x18]==2 (string) sets [+0x5c]=label hash and calls the DAT_00735710 text-changed callback; same b |
| `0x495f70` | `FEng_SetObjectInvisibleByHash` | V | V: mirror of FEng_SetObjectVisible 0x495fc0: package ESI, hash EDI; finds the object in the package and calls FEObject__SetInvisible; 15 callers (GarageMainScreen, Briefing::Build, ColorPicker) |
| `0x4c39d0` | `FEng_CopyTextToObject` | I | I: finds the object (package ECX, hash EAX) like FEngSetLanguageHash and copies a C string (max 0x100 bytes) into the object's text buffer [+0x24], then sets dirty flag 0x400000; callers are movie screens (BootMovieScreen, MovieTh |
| `0x4c96c0` | `FEng_SendBaseMessage` | I | I: FEPackageList::FindByName(EAX) then FEScreen::HandleBaseMessage 0x4f7c00(msg, 0, 0, package [+0x18]) when the package has a screen ([+0x14]); 27 callers (screen handlers) pass the messages 0x9120409e, 0xb5971bf1, 0x72619778, 0x |
| `0x4cd180` | `FEScreenSound::PlayForScreenEvent` | I | I: ECX=package name string hashed with x33 (-1 start); checks the 'HELP_Generic.fng' hash and the 0x7469b4 list, picks a sound event by mode (0x4cd0d0 switch 1..7: FEScreenSound_MapEventDefault, PostRaceSpeech_MapRewardType2, Find |
| `0x4f0800` | `FEManager::QueueSwitchPackage` | I | I: mallocs a 0x20-byte queue node (vtable 0x6c2c64, 0xabadcafe links), type [+0x14]=3, saves the package flags [+0x1c] and clears them, appends at the tail of the cFEng queue (count +0x4128, head +0x412c, tail +0x4130); called by  |
| `0x4f75b0` | `FEObject::SetColor` | I | I: ECX=object (type < 0x100); if FEColor_NearlyEqual(colour) is false sets dirty flag 0x400000 in [+0x1c], then writes the colour via 0x4ff2f0(obj,0,0); callers are HUD widget Update functions (HudTach, HudTachDrag, NitrousGauge,  |
| `0x4f7c00` | `FEScreen::HandleBaseMessage` | I | I: ESI=screen; message 0xc519bfc3 opens InfoDialog (text 0x639) for the object at [+0x3c]; message 0xc98356ba pushes package 0x32 if [+0x38] and caches the focused object ([+0x80] of the current package) in [+0x24]; then forwards  |
| `0x4f7d30` | `FEScreen::HandleArrowMouseClicks` | I | I: ESI=screen; when mouse is enabled (0x7064b2) tests the cursor (0x70649c-0x140, 0x7064a0-0xf0) against the object pairs at [+0x28]/[+0x2c] and [+0x30]/[+0x34] with 0x4f7660 and sends 0x9120409e / 0xb5971bf1 (left/right) via 0x4c |
| `0x4f8340` | `FEScreenSound::PlayScreenSoundByName` | I | I: EAX=screen/package name hash; scans the 14 pairs (stride 8) at 0x6f8a48 for it, then calls FEScreenSound::PlayForScreenEvent 0x4cd180 with 0; called by FEScreen::HandleBaseMessage 0x4f7c00 just before it opens the info dialog,  |
| `0x4f89d0` | `FEListBox::UpdateCursorPulse` | I | I: EDI=list box; 0x4f8b80 first, then a pulse timer [+0x38] (wraps at 1.0, +0.02 step) scales the highlighted cell's alpha: GetHudObjectColor, FEObject::GetPosition, colour = 0xffffff with alpha from 0x437f0000 (255.0) times the p |
| `0x4f9420` | `FEBreadcrumbScreen::FEBreadcrumbScreen` | I | I: FEScreen ctor (vtable 0x6c1884, sdd 0x4f93a0) that finds the objects 'Crumb_0%d' (bSPrintf_regdst) in its package and keeps their colours (FEColor::operator unsigned long); only caller 0x4f93c0 |
| `0x4ff030` | `FEObject::RebaseTrackOffsets` | I | I: walks the object's track list ([+0x54]+0x1c, stride 0x38); for track types 3/4 clears bit 7 of the flags and, per value kind (1..6: int, float, vec2, vec3, quaternion via FEQuaternion_Multiply, rect), stores delta = current obj |
| `0x4ff2f0` | `FEObject::WriteKeyTrackValue` | I | I: obj,trackKind,relative flag; ESI points at 4 ints (colour/rect); writes them into the object's data block (FEObject::GetDataOffset) and into every track of that kind (type byte compared with table 0x6b66e4), absolute or added w |
| `0x500560` | `Dtor500560::DtorBody` | I | I: 7 bytes, stores vtable 0x6c2c5c into this (EAX); called by Dtor500560::ScalarDeletingDtor 0x4eeb70 and 100+ EH unwind stubs of FEng screens and HUD widgets, i.e. the base-class step of their destructors (same pattern as FENode: |

## ui (25)

| Address | Name | Conf | Evidence |
|---|---|---|---|
| `0x413a70` | `Screen_PC_Controller_Config::InitKeyboardConfig` | I | I: zeroes this+0x90..0x98, finds 'keyboard_config_title' and the disabled objects, queues FEManager::QueueSwitchPackage 0x4f0800, FEObject::RebaseTrackOffsets 0x4ff030, cFEng::SetCurrentButton; callers Screen_PC_Controller_Config  |
| `0x414ab0` | `Dtor414ab0::DtorBody` | I | I: 7 bytes, stores vtable 0x6cbe74 into this; called only from EH unwind stubs of OptionsMenu and Screen_MU_Options_PC |
| `0x415f90` | `Screen_PC_Customize_Graphics::BindOptionRow` | I | I: (name hash in EAX, label hash, max, row 0..0x1f): clamps max by EAX, for EAX==0 queues a FEng message and button state else sets [this+0x2b4]; finds the FEng object (FEngFindPackage/FEng_VisitChildrenSEH) and stores it at +0x13 |
| `0x417c30` | `Screen_MU_UG_NewOrLoad_PC2::~Screen_MU_UG_NewOrLoad_PC2` | I | I: sets vtable 0x6cbc18, frees buffer [+0x260] (bFree/_free), LinkedList_FreeAll twice, eh_vector_destructor_iterator over 0x20 WStrings at [+0x60], FEScreen::~FEScreen; called by Dtor417c30::ScalarDeletingDtor 0x417c10 right afte |
| `0x41f140` | `FEMenuData::~FEMenuData` | I | I: __fastcall; eh_vector_destructor_iterator over 32 elements of 0xc bytes at [this+0x10] with WString_Free; paired with FEMenuData::FEMenuData 0x41f0c0 which the lobby screen ctor 0x55bfc0 uses |
| `0x49f2e0` | `Screen_RewardPopup::UpdateState` | I | I: switch on state [this+8]: waits Screen_RewardPopup::HasDisplayTimeElapsed 0x49f2b0, advances the reward list ([+0xc]/[+4]) and plays the FEng script 'Flashy' (FEng_SetScriptByName) for each item, shows items with FEng_SetObject |
| `0x4af5d0` | `GarageMain_EndCarPreview` | I | I: FEPackageList::FindByName, if DAT_006fb02c (car preview active) calls 0x4aff20, then sets DAT_00735e84=1, DAT_006fb02c=0, DAT_0074810c=now (0x73ad3c); called by the garage browsers (GaragePartsBrowser/PerfTuner/PerfBrandPackage |
| `0x4b2330` | `GarageMain_GetScreenObject` | I | I: FEPackageList::FindByName(name in EAX) on the package list 0x746104; returns package-data [+0x14] when [+0x18] is set, else child slot [+0x40]/[+0x44] chosen by ESI (0/1); used by the career front-end screens (NewOrLoad, Main,  |
| `0x4b2480` | `GarageMain_SetDramaticCamera` | I | I: gets the GarageMain screen via 0x4b2330 (or its child slot [+0x44]) and passes it to 0x4b14e0, which stores it at screen+0x124/+0x8c and calls SelectCarCameraMover::SetDramaticMode; 18 callers are front-end screen constructors |
| `0x4b70c0` | `Screen_MU_QuickRaceModeSelect::SetupModeButtons` | I | I: for each race mode formats 'Mode_%d' and finds the FEng object, sets button state (cFEng::SetButtonState); per-mode objects 'MODE_CIRCUIT'/'QR_circuit', 'MODE_SPRINT'/'QR_sprint', 'MODE_RACE_DRAG', 'QR_drift' else 'GENERICPLACE |
| `0x4b9070` | `Screen_MU_QuickRaceOptions_PC::InitOptionRows` | I | I: EAX=screen; loops 4 times 0x4b8d50(i), then stores row ids 1..n and callback labels (0x4b8560, 0x4b85c0, 0x4b8650 ...) and refreshes each row with QuickRaceOptions_UpdateRowOpt10/20/18/18Switch/14; only caller BuildOptionList 0 |
| `0x4ba100` | `Screen_MU_QuickRaceTrackSelect::BuildTrackList` | I | I: formats 'TRACK_IMAGE_%d', 'REVERSE_TRACK_IMAGE_%d', 'TRACK_%d_ICON', 'REVERSE_TRACK_%d_ICON' (fallback 'GENERICPLACEHOLDER'), tests cFrontendDatabase::IsTrackAvailableForRaceType, Texture_FindByHash, adds items (AddTrack 0x4b9f |
| `0x4bc170` | `Screen_MU_QuickRaceCarSelect::BuildCarList` | I | I: groups cars by manufacturer (string 'HONDA', 'CARSELECT_MANUFACTURER_%s' via bStringHashPrintf), GetStockPerformanceMeasure for sorting, adds entries with FEListBox::AddItem/SelectItemByData and calls 0x4bd0f0 to show the first |
| `0x4bd0f0` | `Screen_MU_QuickRaceCarSelect::ChangeSelectedCar` | I | I: message (0x9120409e-like hashes -0x6edfbf62 / -0x4a68e40f) moves the car cursor prev/next in the list at [+0x40..+0x48]; shows/hides lock icons; loads the car into GarageMain (GarageMainScreen::SetCarType, or for locked cars Ri |
| `0x4c1ca0` | `Screen_MU_PauseOptions_PC::InitOptionRows` | I | I: EAX=screen; loops 2 times 0x4c13b0(i,0), finds the title object (hash 0x39cac62) and shows it, OptionsCameraUI 0x4be6c0; only caller Screen_MU_PauseOptions_PC::BuildOptionList 0x4c0b60 |
| `0x4c4f50` | `Screen_MU_UG_MapScreen::NotificationMessage` | I | I: __thiscall(screen, message hash): 0x9795550e shows an object by name, 0x911ab364 FEngSwitchPackages, 0x9120409e opens the event (0x4c4be0), 0xc407210 select; calls 0x4f7d30 (arrow clicks), 0x4f89d0 (list pulse), FEngSetScript,  |
| `0x4c7790` | `UndergroundRewardPartScreen::UndergroundRewardPartScreen` | I | I: FEScreen ctor (vtable 0x6c51a4, object 0x7c0 bytes built by 0x4c8ab0): FEListBox 'master_thumb'/'car_thumb', hash of 'WHEELS' and 'CAR_THUMB', CarPartDatabase::GetCarPart lookups, reward speech via switch 0x4c76d0 (events 48,53 |
| `0x4c8b70` | `UndergroundMagazineGiveth::UndergroundMagazineGiveth` | I | I: FEScreen ctor (object 0x8c bytes built by 0x4c9410): FEListBox 'master_thumb'/'car_thumb', 'STATUS_MAGAZINES_ICON', GetEventHashForMagazineThumb 0x4e93b0, Frontend_LoadMagazineTextures 0x51bad0, 'MU_HorizontalBrowserBack.fng'/' |
| `0x4cdb60` | `Screen_MU_Pause_PC::SetupOptionButton` | I | I: when the 0x43a2e0 (online) flag is set greys the button (FEObject::SetColor 0xff606060, cFEng::SetButtonState 0), then prints the localized text for 'OptionName_%1d' (LanguageStrings::FindByHash, FEngPrintf); callers 0x4ce120 a |
| `0x4ce120` | `Screen_MU_Pause_PC::BuildOptionButtons` | I | I: sets the per-button handler pointer ([this+0x4c] = 0x4cdca0), formats 'OptionName_%1d' for every pause entry, finds the button objects (hashes 0x1aec7d0c...) and updates their state/text through 0x4cdb60 and 0x4cda80; caller 0x |
| `0x4d8600` | `ColorPicker::UpdateLockedIcons` | I | I: for each colour slot formats 'locked_icon_%d'/'LOCKED_ICON_%d'/'COLORELEMENT_%d' (bSPrintf, bStringHashPrintf), finds the FEng objects and shows or hides them with FEng_SetObjectVisible/0x495f70 according to IsLevel2PaintsOwned |
| `0x4da1a0` | `Screen_PC_ColorPicker::InitControls` | I | I: called by Screen_PC_ColorPicker ctor 0x4dab10; ColorPicker_BindElements, hides 'MU_HorizontalBrowserBack.fng', finds objects by hash, builds 'NUMREMAPCOLOURS' and '%s %i' labels, ComputeVinylIconHash, FEng_SetImageTextureByName |
| `0x4dbf90` | `ColorPicker::ShowPartPrice` | I | I: EBX=screen; FEObject::GetPosition of the selected swatch, builds a rect (_ftol), GetCarPartCost 0x5a08f0, prints it with FEngPrintf, and shows/hides the level lock objects (IsLevel2/3PaintsOwned); callers Screen_PC_ColorPicker  |
| `0x59e850` | `FEWidget::InitFromDescriptor_59e850` | I | I: this + descriptor: stores package, finds up to three FEng objects by hash from the descriptor (type 1 image at +8, type 2 string at +0x10), then builds a list of item objects named with the format at 0x6c3eb4 and an index (hash |
| `0x59eac0` | `FEWidget::InitFromDescriptor_59eac0` | I | I: sibling of 0x59e850 (same pattern, 169 lines): resolves its objects from a descriptor by hash with FEngFindPackage/FEng_VisitChildrenSEH/FEng_FindNodeByName, bSPrintf_regdst names, mallocs the item nodes; no direct callers |

## camera (5)

| Address | Name | Conf | Evidence |
|---|---|---|---|
| `0x47e300` | `DemoCameraCoordinator::CreateMover` | I | I: __fastcall: picks a camera mover for the current demo shot and mallocs it: TrackCarCameraMover (0x470), BumperCameraMover (0x45c), TrackFlyCameraMover (0x19c), DriveCameraMover (0x3a0), CubicCameraMover (0x54), seeded with Came |
| `0x490770` | `PreviewComet::UpdateTrail` | I | I: (this, a, dt, flag): evaluates the Catmull-Rom spline of the comet path (Spline_CatmullRomEval, 0x582a90/0x582b50), builds the trail quads with ePoly::ePoly/0x40c300 and projects them (bNormalize3, D3DXMatrixMultiply, _ftol); v |
| `0x493c70` | `ZonePreviewCameraMover::BuildPathSpline` | I | I: __thiscall with 10 args: samples road points (RoadEntries_Sort, Float_Truncate), fits Catmull-Rom segments (Spline_CatmullRomEval, 0x4936e0/0x493a90/0x493bd0/0x582cf0) into a camera path, 0x2170 bytes of stack; only caller Zone |
| `0x4b0340` | `GarageMainScreen::UpdateCarCamera` | I | I: state machine on [this+0xec] (0..4) driving SelectCarCameraMover: IsPresetDone/SetPresetA/EndPreset, CameraMover_SetupSpline with float pairs 0x42c60000 (99.0) and 0x42340000 (45.0), transition params A/B, timer polynomial in [ |
| `0x5825c0` | `CameraPath_FreeBuffers` | I | I: frees the malloc buffers at [this+0x10] and [this+0x2c] when set (ESI=this); only called from EH unwind stubs of camera classes at 0x4936e0 and 0x4922c0 |

## online (19)

| Address | Name | Conf | Evidence |
|---|---|---|---|
| `0x4394f0` | `OnlineManager::UpdateFinishTimeouts` | I | I: resets [+0x1b4]=0,[+0x1b8]=-1.0,[+0x1bc]=-1.0; while a race is on (state 4 via 0x421960, not all players finished) counts down the two timers [+0x1ac]/[+0x1b0] (int_Sub, bTickerToSeconds) against 0x77c788: warning state 1/2 wit |
| `0x43a8a0` | `OnlineManager::UpdateFrameTime` | I | I: __thiscall(float dt): 0x43a2e0 active test, after more than 14 consecutive frames over the lag threshold (0x78eb58) pushes a localized message with HudOnlineMsgBox::PushLocalizedMessage, tracks race time with bTickerToSeconds/F |
| `0x43ac10` | `OnlineManager::TickRaceSync` | I | I: for online states (*this == 4,5,6) per player calls 0x439470/0x439860, then 0x43bfe0 (style sync), 0x43c300 (racer-state packet), 0x43d120, 0x439f80; otherwise 0x4390d0(7) or 0x43a220(0); sets 0x6f0894=3.0 |
| `0x43be30` | `OnlineManager::OnRacerFinished` | I | I: (player index, time, reason): for the local player (== this[1]) outside mode 0/3/4/5/6, rejects an early finish (0x4399a0(0x10)); in drift mode sends the finish time with 0x43d030; calls NetPlayer::SendFinishMessage; on reason  |
| `0x43bfe0` | `OnlineManager::RankRacers` | I | I: collects the active players (4 slots at this+8), bubble-sorts them by finished state ([+8]==10 finished counts 2), then race time / lap / drift score ([+0xf4+track*4] in drift mode), writes the rank into the racer record and th |
| `0x43c300` | `OnlineManager::SendRacerStatePacket` | I | I: NetBitStream_Reset then writes race mode (0..3 from drift/0x421a50 flags), track, laps, then for each of 4 racers: id, rival flag, lap/time floats (bTickerToSeconds), finish state, accel/top-speed/handling ratings (RideInfo rat |
| `0x43cef0` | `OnlineManager::SendCheckpointListPacket` | I | I: if byte [this+0x40] (count) is set: NetBitStream_Reset, writes the count, the race time (BitStream::WriteFloatRounded of bTickerToSeconds) and per entry a byte (BitStream::WriteByteBits) plus a rounded float, then sends with 0x |
| `0x43d030` | `OnlineManager::SendFinishTimePacket` | I | I: reads race clock via 0x432d10/Race_TickTrackerSet, resets NetBitStream, writes the racer id byte, bumps finish counter [racer+0x1a8], writes two values with BitStream::WriteBitsThunk and sends with 0x546850 when 0x5466e0; calle |
| `0x43d2d0` | `OnlineManager::OnRacerTimeout` | I | I: (player index, a, b): when more than one racer remains (Float2_ToIntPair > 1) and the race countdown (Countdown::GetTotalSeconds) has passed, calls 0x4399a0(1), and forwards (a,b) to the racer's vtable slot 3 via RaceManager::F |
| `0x54f200` | `OnlineRoomListScreen::FillRoomRows` | I | I: __thiscall switch over the list state, per row formats '%s0%d'/'%s%d' with FE_GetSlotPrefix 0x4abd40, finds 'RoomName_DATA' and 'PlayersRoom_DATA' objects, prints names (Online::FindNthEntryByFirstTwoChars 0x549ca0, LanguageStr |
| `0x5544a0` | `OnlineGameOptionsScreen::OnlineGameOptionsScreen` | I | I: FEScreen ctor (vtable 0x6bcdec, only caller 0x554420): 0x589260 member init, [+0x68]=0x33650b60, Ptr_SetNull members, RaceOptions_Get, 0x554730/0x5556e0/0x555720 setup of the race-type/track/laps rows |
| `0x554f60` | `OnlineGameOptionsScreen::NotificationMessage` | I | I: message switch on FEng hashes (0xaabbccdd, 0x911ab364 back, 0xaffffa0, 0x406415e3, 0x911c0a4b ...), opens GenericDialogData/InfoDialog::OpenModalDialog, sends host/join state through 0x5494f0/0x5543xx leaves; vtable method (no  |
| `0x5558d0` | `OnlineGameOptionsScreen::UpdateLapsRow` | I | I: RaceOptions_Get values into 0x555ff0, stores the choice at [+0x60], FEngPrintf of 'LapsData' (bSPrintf_regdst) for race types 1 and 3, otherwise FEngSetScript 'GreyOut'; callers 0x555720 and 0x555a80 (option changed handlers) |
| `0x555dd0` | `OnlineGameOptionsScreen::SelectFirstAvailableTrack` | I | I: loops all tracks (Leaf_4a9950 count, TrackInfo_GetRow), keeps those allowed by cFrontendDatabase::IsTrackAvailableForRaceType and Leaf_554400, calls 0x555ce0 to add them; only caller 0x554730 |
| `0x5570a0` | `OnlineScreen_5570a0::NotificationMessage` | I | I: __thiscall(screen, message, arg): on 0x911ab364 pushes 'GenericDialog.fng' via FEng_PushScreenWithFactory_B with the dialog block (0x7ab61b3f, 0x22334455, 0x541389e5, 0xb8a7c6cd), on 0xc407210 switches on the pressed button has |
| `0x557a40` | `OnlineScreen_557a40::NotificationMessage` | I | I: __thiscall(screen, message, arg): message 0x12bd8a2 builds a URL string ('%s %s') and calls ShellExecuteA(NULL,'open',...) (opens the EA web page), 0xc407210 handles the three buttons (hashes 0x448e93e0, 0x5e4efa1b, -0x4255a42e |
| `0x55bfc0` | `OnlineLobbyScreen::OnlineLobbyScreen` | I | I: FEScreen ctor (vtable 0x6bc99c; called by 0x55bf60): FEMenuData members, finds 'Player_DATA_%.2d' and 'TEXT_ENTRY%d' objects per row, fills rows with Online::FillPlayerDataRow 0x55c550 |
| `0x55e3b0` | `OnlineRaceSetupScreen::UpdateLapsRow` | I | I: like OnlineGameOptionsScreen::UpdateLapsRow but reads RaceOptions field +8 via 0x55e350 into [this+0x70], looks the FEng object up and prints 'LapsData' or sets script 'GreyOut'; callers 0x55dcf0 and 0x55dfa0 |
| `0x664e00` | `Online::SendTaggedRequest` | I | I: only accepts the 4-char tags 'idle' (0x69646c65), 'auth' (0x61757468), 'acct' (0x61636374), 'skey' (0x736b6579) at [this+0xc], builds the request with 0x664380 and the 0x667xxx writers and scrambles with DirtySock::ScrambleStri |

## render (13)

| Address | Name | Conf | Evidence |
|---|---|---|---|
| `0x402d30` | `Particles_UpdateEmitter` | I | I: (system, emitter, dt, flag): per-particle update with Angle16_Sin, rotation matrices (Matrix_RotationZ/MultiplyRotationX/Y_Angle16), bNormalize3, D3DXMatrixMultiply, List_ReleaseAllToPool for dead ones; ~360 lines; callers Part |
| `0x4b1b70` | `GarageMainScreen::QueueBackdropSolid` | I | I: when DAT_006f1dfc is set and [this+0x90]==0: ScratchAlloc64xN matrix, eIdentity, translation from 0x6b6b50..58, rotations by 3 angles (bDegreesToAngle16 0x6b6b5c/64/60) and Solid_QueueGroups(0x740460+idx*0x18) for the garage ba |
| `0x56d8d0` | `CarRenderInfo::DrawLampFlares` | I | I: (info, view, ..., flags): for each lamp node tests AABB_ClassifyAgainstFrustum, Car::LightsOnForDraw, projects with D3DXVec3Transform and LampFlare_ProjectAndFade / eView::CalcSphereScreenSize; callers 0x570c70 and 0x570d00 |
| `0x5bb1eb` | `D3DX_HlslSema_ResolveConstDims` | I | I: node type [+4]==0xc (matrix/array type): copies the two dimensions from its child (+0x10, type 8: +0x18,+0x1c) into [+0x14],[+0x18]; non-constant child gives 1 and the InternalErrorUnknownNode text; 14 callers inside D3DX HLSL  |
| `0x5bbe7f` | `D3DX_HlslSema_TypesEqual` | I | I: (a, b, flag): returns 1 when both are null or structurally equal, 0 otherwise; walks type nodes (kind [+4]==8 scalar/vector) with the helpers InternalErrorUnknownNode_5ba799/5ba80b/5bac05; callers are the cannot-convert / incor |
| `0x5c0e2d` | `D3DX_HlslSema_EvalLiteralDimension` | I | I: evaluates a literal-dimension expression: Value_5c0cfc, requires a scalar node (type 8) via 0x5ba77a, then 0x5bcf1c stores the value (error 0x80004005-like code otherwise) and deletes the temp; callers are the vector/matrix/arr |
| `0x5dc02b` | `D3DX_HlslGen_EmitIfStatement` | I | I: __thiscall; generates code for an if node, the string 'asymetric returns from if statements not yet implemented' is raised when only one branch returns; uses D3DX_Back_Container_GetItemA, 0x5f7cfc, malloc/free of per-branch reg |
| `0x5e4bb7` | `D3DX_HlslGen_AllocNodeRegisterArray` | I | I: __thiscall: for a type 0xc node mallocs count*size dwords, fills with -1 (D3DX_HlslGen_FillMinusOne), assigns result registers (ResultRegisterInv_5d9fa1), stores the current id into every item (D3DX_Back_Container_GetItemA) and |
| `0x5f7760` | `D3DX_Back_Container_Init` | I | I: __thiscall (kind, count, aux, flag): stores them in [0],[1],[3]; the high nibble of kind (0x10000000/0x20000000/0x30000000 + 0x31..0x35 families) selects the element size and mallocs the array; 34 callers in the D3DX back-end ( |
| `0x5ffbd5` | `D3DX_Back_LowerNodes` | I | I: 958-line __fastcall back-end pass over the IR: builds constants with D3DX_Ir_NewConstantNode, tests type classes (D3DX_Ir_IsTypeClass0/1), copies fields (Container_CopyField34), Container_Reset/DeletingDtor; sole caller 0x60417 |
| `0x600fa7` | `D3DX_Back_AllocRegisterFile` | I | I: __fastcall: clears per-class use counts [entry+0x10], raises them to (reg+1) over the instruction list (flags 2 set, 0x200 clear), sums them, mallocs the total*4 table and fills it using D3DX_Back_Container_Reset/CopyField34, D |
| `0x60c8b9` | `D3DX_Ps1Back_Compile` | I | I: __fastcall ps_1_x backend driver: builds the 0.0 and 1.0 constants with D3DX_Ir_NewTypeNode(0x69ecd8,0x189,1,4)/NewConstantNode, then runs the Ps1Back passes (0x6043ad TexcoordInputsUsedDirectly, 0x6046ad..0x605ecb, Tex3D 0x605 |
| `0x61319b` | `D3DX_String_Create` | I | I: __thiscall(str, len, flags, out): returns E_FAIL (0x80004005) for len>0 with null str; len==-1 means strlen; flags default /2; mallocs len+1 and copies the string into a new node returned in *out; 8 callers in the assembler/ps2 |

## assets (4)

| Address | Name | Conf | Evidence |
|---|---|---|---|
| `0x53e9e0` | `Resource_QueueLoadByHashArray` | I | I: (list set, hash array, count, callback, user, flag): looks each hash up with SolidListSet_FindListByHash+BinarySearch_Hash, collects entries in a bMalloc'd list sorted by offset (bList__Sort), loads each with 0x53e830 and calls |
| `0x53eed0` | `ResourceFileList_OpenOrAddRef` | I | I: StringList_Find(list, name): if present increments [+0xb0] and returns it; else rejects names over 0x7f chars, mallocs the entry, opens the file (bOpenFile 0x594c60, bLargestFreeBlock checks) and links it; callers GameFlow::Loa |
| `0x594d40` | `bCloseFile` | I | I: ESI=file object; if [+0x1c] (pending ops) > 0 only sets [+0x14]=1; else closes the handle with 0x63c2c0(handle,100) or drops the refcount at [[+0x10]+8], marks [+4]=-1 and returns the object to the file pool (count at pool+0x18 |
| `0x59f7c0` | `Language_LoadTextureBin` | I | I: finds the ResourceFile of 'LANGUAGES\LANGUAGETEXTURES.BIN' in the file table below 0x6ee6f0, unloads it (UnloadResourceFile) and clears the four loaded-chunk pointers at [file+0x60/+0x64/+0x68] according to the four char flags, |

## audio (1)

| Address | Name | Conf | Evidence |
|---|---|---|---|
| `0x533a50` | `EnvStaticSoundObject::Update` | I | I: __fastcall: SoundObject::Update, EAXRamp::Update(0.001), clamps volume [+0x4c] to 0..0xffff and distance to 0..0x1fa0 into the voice record [+0x280], scales by the master volume tables (0x6f4f30, 0x6f4f48, DAT_007356ac+0xab8),  |

## track (2)

| Address | Name | Conf | Evidence |
|---|---|---|---|
| `0x47c580` | `NisScene::UpdateCarAnimations` | I | I: (scene, dt): for each of the paired animation controllers in table 0x7798f0 advances CAnimCtrl::AdvanceAnimTime (clamped to the clip length scaled by 1/DAT_006ffdbc), evaluates 0x47b3d0, composes the body and wheel matrices (bM |
| `0x47cb50` | `NisScene::BuildWorldMatrix` | I | I: sets the 4x4 blocks at +0x20/+0x60/+0xa0 to identity-with-zero, finds the scene origin with NisSceneManager::FindNisSceneOriginPosition, GroundQuery::FindSurfaceBelow for the height, TrackPathCoordinate, Atan2ToAngle16 heading, |
