#pragma once
#include "types.h"

// Variable macros
#define VAR_U_(address, type)			(*(type*)(address)) // uninitialized variable
#define VAR_I_(address, type, value)	(*(type*)(address)) // initialized variable (value is just for info)
#define ARRAY_(address, type, length)	(*(type(*)length)(address)) // array (can be multidimensional)

//vars
#define input VAR_U_(0x00878D98, int)
#define dbinput   VAR_U_(0x00878DAC, int)
#define mycoll   VAR_U_(0x00E5BC20, COLL_INFO*)
#define lara    VAR_U_(0x00E5BD60, LARA_INFO)
#define lara_item    VAR_U_(0x00E5BF08, ITEM_INFO*)
#define DashTimer VAR_U_(0x00E5BF04, unsigned short)
#define anims	VAR_U_(0x00875158, ANIM_STRUCT*)
#define items	VAR_U_(0x00EEEFF0, ITEM_INFO*)
#define effects	VAR_U_(0x00E5C5E0, FX_INFO*)
#define room	VAR_U_(0x00875154, room_info*)
#define	meshes	VAR_U_(0x00875170, short**)
#define height_type VAR_U_(0x00EEEFF4, int)
#define trigger_index VAR_U_(0x00EEEF9C, short*)
#define xfront VAR_U_(0x00EEf928, long)
#define zfront VAR_U_(0x00EEf92C, long)
#define GLOBAL_cutseq_frame VAR_U_(0x00E7F024, int)
#define old_lara_holster VAR_U_(0x00E7EFE0, unsigned short)
#define actor_chat_cnt VAR_U_(0x0051CAB6, char)
#define gfCurrentLevel VAR_U_(0x00E5C2D0, int)
#define gfLevelComplete VAR_U_(0x00E5C2F0, int)
#define gfLevelFlags	VAR_U_(0x00E5C2A0, short)
#define gfGameMode	VAR_U_(0x005082C0, unsigned char)
#define cutseq_num	VAR_U_(0x0051CAA8, int)
#define cutseq_trig	VAR_U_(0x0051CAAC, int)
#define cutseq_busy_timeout	VAR_U_(0x0051CAB4, char)
#define bTrackCamInit	VAR_U_(0x0051D010, int)
#define bUseSpotCam	VAR_U_(0x0051D018, int)
#define SetDebounce	VAR_U_(0x00EEEA38, int)
#define framecount	VAR_U_(0x0051CA78, int)
#define GlobalCounter	VAR_U_(0x0051CA58, unsigned short)
#define cdtrack	VAR_U_(0x00506C64, short)
#define bDisableLaraControl	VAR_U_(0x0051D01C, int)
#define GLOBAL_enterinventory	VAR_U_(0x00508E18, int)
#define GLOBAL_playing_cutseq	VAR_U_(0x0051CAB0, int)
#define GLOBAL_inventoryitemchosen	VAR_U_(0x00508E1C, int)
#define reset_flag	VAR_U_(0x0051CA6C, int)
#define FadeScreenHeight	VAR_U_(0x0051D074, short)
#define thread_started	VAR_U_(0x00876C48, bool)
#define SniperCamActive	VAR_U_(0x0051CA1D, char)
#define BinocularRange	VAR_U_(0x0051CA30, long)
#define BinocularOn	VAR_U_(0x0051CA34, long)
#define BinocularOldCamera	VAR_U_(0x0051CA38, camera_type)
#define LaserSight	VAR_U_(0x0051CA3C, long)
#define InfraRed	VAR_U_(0x0051CA40, long)
#define inputBusy	VAR_U_(0x00878C94, int)
#define GotLaraSpheres	VAR_U_(0x00E51F2E, char)
#define InItemControlLoop	VAR_U_(0x0051CA53, unsigned char)
#define next_item_active	VAR_U_(0x00E5BF22, short)
#define next_fx_active	VAR_U_(0x00E5C5FC, short)
#define KillEverythingFlag	VAR_U_(0x0051CDF4, long)
#define SmokeCountL	VAR_U_(0x00E6C9E8, long)
#define SmokeCountR	VAR_U_(0x00E6C9EC, long)
#define SplashCount	VAR_U_(0x0051CDF8, long)
#define WeaponDelay	VAR_U_(0x0051CA52, unsigned char)
#define wibble	VAR_U_(0x0051CDF0, long)
#define XSoff1	VAR_U_(0x0055D200, short)
#define XSoff2	VAR_U_(0x0055D1FC, short)
#define YSoff1	VAR_U_(0x0055D210, short)
#define YSoff2	VAR_U_(0x0055D214, short)
#define	ZSoff1	VAR_U_(0x0055D244, short)
#define ZSoff2	VAR_U_(0x0055D248, short)
#define PoisonFlag	VAR_U_(0x00E5BF3E, char)
#define LaraDrawType	VAR_U_(0x00EEEAD0, char)
#define CamRot	VAR_U_(0x00E4B0E0, SVECTOR)
#define SmashedMeshCount	VAR_U_(0x0051CA5C, short)
#define health_bar_timer	VAR_U_(0x0051CEA8, int)
#define GameTimer	VAR_U_(0x00E5C27C, unsigned long)
#define Gameflow	VAR_U_(0x00E5C2BC, GAMEFLOW*)
#define camera	VAR_U_(0x00EEF940, CAMERA_INFO)
#define CamOldPos	VAR_U_(0x00EEFB00, PHD_VECTOR)
#define savegame	VAR_U_(0x00E52EB3, savegame_info)
#define NumRPickups	VAR_U_(0x00E5970C, unsigned char)
#define waterfallY	VAR_U_(0x0051CF54, int)
#define next_blood	VAR_U_(0x0051D088, long)
#define floor_data	VAR_U_(0x00875168, short*)
#define rand_1	VAR_U_(0x00516A38, long)
#define	rand_2	VAR_U_(0x00516A3C, long)
#define	last_target	VAR_U_(0x00EEFA30, GAME_VECTOR)
#define	last_ideal	VAR_U_(0x00EEFA40, GAME_VECTOR)
#define UseForcedFixedCamera	VAR_U_(0x00EEFA50, char)
#define	InGameCnt	VAR_U_(0x00E5BF0C, unsigned char)
#define	cheat_hit_points	VAR_U_(0x00E5BBF8, short)
#define	gfNumPickups	VAR_U_(0x0051CE38, unsigned char)
#define gfNumTakeaways	VAR_U_(0x0051CE39, unsigned char)
#define	disable_horizon	VAR_U_(0x0051CAA4, unsigned char)
#define	level_items	VAR_U_(0x0051CEB8, int)
#define	cutseq_num	VAR_U_(0x0051CAA8, int)
#define	cutseq_trig	VAR_U_(0x0051CAAC, int)
#define	numnailed	VAR_U_(0x00E6E4E4, int)
#define	GLOBAL_cutme	VAR_U_(0x00E711B0, NEW_CUTSCENE*)
#define	dels_cutseq_player	VAR_U_(0x0051CE2C, unsigned short)
#define	GLOBAL_oldcamtype	VAR_U_(0x00E711AC, camera_type)
#define	CurrentAtmosphere	VAR_U_(0x00EEEB90, unsigned char)
#define	IsAtmospherePlaying	VAR_U_(0x00EEEFFC, unsigned char)
#define gfRequiredStartPos	VAR_U_(0x00E5C2B4, unsigned char)
#define	ScreenFade	VAR_U_(0x0051D068, short)
#define	dScreenFade	VAR_U_(0x0051D06A, short)
#define	ScreenFadeBack	VAR_U_(0x0051D06C, short)
#define ScreenFadeSpeed	VAR_U_(0x0050A178, short)
#define	ScreenFadedOut	VAR_U_(0x0051D06E, short)
#define ScreenFading	VAR_U_(0x0051D070, short)
#define	cut_seethrough	VAR_U_(0x00506D9C, int)
#define	cutrot	VAR_U_(0x0051CAA0, int)
#define bDoCredits	VAR_U_(0x0051CE35, unsigned char)
#define num_fmvs	VAR_U_(0x0051CE25, char)
#define gfScriptWad	VAR_U_(0x0051CE20, unsigned char*)
#define	gfStringWad	VAR_U_(0x00E5C310, char*)
#define	gfFilenameWad	VAR_U_(0x00E5C2CC, char*)
#define gfScriptOffset	VAR_U_(0x0051CE10, unsigned short*)
#define	gfStringOffset	VAR_U_(0x00E5C2AC, unsigned short*)
#define gfStringOffset_bis	VAR_U_(0x00E5C2B8, unsigned short*)
#define gfStatus	VAR_U_(0x00E5C2B0, int)
#define gfLegend	VAR_U_(0x00E5C348, unsigned char)
#define gfLegendTime	VAR_U_(0x0051CE34, unsigned char)
#define gfUVRotate	VAR_U_(0x00E5C349, char)
#define gfNumMips	VAR_U_(0x0051CE37, unsigned char)
#define gfMirrorRoom	VAR_U_(0x00E5C24C, unsigned char)
#define gfMirrorZPlane	VAR_U_(0x00E6D748, long)
#define gfInitialiseGame	VAR_U_(0x005082C1, unsigned char)	
#define	gfLayer1Col	VAR_U_(0x00E5C2A4, CVECTOR)
#define gfLayer2Col	VAR_U_(0x00E5C280, CVECTOR)
#define	gfLayer1Vel	VAR_U_(0x00E5C276, char)
#define	gfLayer2Vel	VAR_U_(0x00E5C275, char)	
#define gfLensFlare	VAR_U_(0x00E5C2E0, PHD_VECTOR)
#define gfLensFlareColour	VAR_U_(0x00E5C2F4, CVECTOR)
#define gfResetHubDest	VAR_U_(0x00E5C2C8, unsigned char)
#define gfCutNumber	VAR_U_(0x0051CE36, unsigned char)
#define	changes	VAR_U_(0x0087515C, CHANGE_STRUCT*)
#define ranges	VAR_U_(0x00875160, RANGE_STRUCT*)
#define commands	VAR_U_(0x0087517C, short*)
#define	FXType	VAR_U_(0x00EEF900, short)
#define flipeffect	VAR_U_(0x00506C60, int)
#define	KeyTriggerActive	VAR_U_(0x0051CA56, unsigned char)
#define TriggerTimer	VAR_U_(0x0051CA5A, char)
#define OnObject	VAR_U_(0x00EEEAC8, int)
#define FootPrintNum	VAR_U_(0x00E5C350, int)
#define	number_dynamics	VAR_U_(0x00E6D82C, int)
#define	tiltyoff	VAR_U_(0x00EEEADC, int)
#define	tiltxoff	VAR_U_(0x00EEEAD4, int)
#define	baddie_slots	VAR_U_(0x00E5B834, creature_info*)
#define stats_mode	VAR_U_(0x0051CF26, short)
#define go_select	VAR_U_(0x00E59E2A, unsigned char)
#define	go_deselect	VAR_U_(0x00E5992C, unsigned char)
#define go_right	VAR_U_(0x00E5989C, unsigned char)
#define	go_left	VAR_U_(0x00E59899, unsigned char)
#define go_up	VAR_U_(0x00E59922, unsigned char)
#define go_down	VAR_U_(0x00E59929, unsigned char)
#define keypadx	VAR_U_(0x0051CF30, unsigned char)
#define keypady	VAR_U_(0x0051CF31, unsigned char)
#define keypadnuminputs	VAR_U_(0x0051CF32, unsigned char)
#define keypadpause	VAR_U_(0x0051CF33, unsigned char)
#define GnFrameCounter	VAR_U_(0x00E4B0FC, unsigned long)
#define use_the_bitch	VAR_U_(0x00E59921, char)	
#define menu_active	VAR_U_(0x00E5989A, char)
#define inventry_xpos	VAR_U_(0x0051CF34, short)
#define inventry_ypos	VAR_U_(0x0051CF36, short)
#define SmokeWeapon	VAR_U_(0x00E6CAA0, long)
#define HKTimer	VAR_U_(0x0051CEC9, char)
#define HKShotsFired	VAR_U_(0x0051CEC8, char)
#define joy_fire	VAR_U_(0x00878D9C, int)
#define joy_x	VAR_U_(0x00878DA0, int)
#define joy_y	VAR_U_(0x00878DA4, int)
#define XATrack	VAR_U_(0x00510B14, short)
#define MusicVolume	VAR_U_(0x00E4B0EC, int)
#define TargetSnaps	VAR_U_(0x0051CA2D, char)
#define SniperCount	VAR_U_(0x0051CA1C, char)
#define TLFlag	VAR_U_(0x0051CA44, char)
#define SniperOverlay	VAR_U_(0x0051D022, char)
#define sound_effects	VAR_U_(0x00E5C5F8, OBJECT_VECTOR*)
#define number_sound_effects	VAR_U_(0x00E5C5F0, int)
#define sound_active	VAR_U_(0x0051D004, int)
#define sample_infos	VAR_U_(0x00E528A8, SAMPLE_INFO*)
#define wf	VAR_U_(0x005078F0, long)
#define sample_lut	VAR_U_(0x00E528A4, short*)
#define examine_mode	VAR_U_(0x0051CF24, short)
#define boxes	VAR_U_(0x00EEFB64, box_info*)
#define SubHitCount	VAR_U_(0x0051CEE4, char)
#define subsuit	VAR_U_(0x00E5B850, SUBSUIT_INFO)
#define OldPickupPos	VAR_U_(0x00E59700, PHD_VECTOR)
#define CurrentSequence	VAR_U_(0x00E4EA61, unsigned char)
#define FlashFadeR	VAR_U_(0x0051D07A, short)
#define FlashFadeG	VAR_U_(0x0051D07C, short)
#define FlashFadeB	VAR_U_(0x0051D07E, short)
#define FlashFader	VAR_U_(0x0051D080, short)
#define PickupX	VAR_U_(0x00E5BF38, short)
#define PickupY	VAR_U_(0x00E5BF26, short)
#define PickupVel	VAR_U_(0x00E5BF3A, short)
#define CurrentPickup	VAR_U_(0x00E5BF3C, short)
#define Chris_Menu	VAR_U_(0x0051CE2E, char)
#define title_controls_locked_out	VAR_U_(0x00E5C2A8, char)


#define	phd_winxmax	VAR_U_(0x0055D218, short)
#define	phd_winxmin	VAR_U_(0x0055D234, short)
#define	phd_winymax	VAR_U_(0x0055D240, short)
#define	phd_winymin	VAR_U_(0x0055D1E8, short)
#define phd_mxptr	VAR_U_(0x00E4B0F8, int*)
#define phd_dxptr	VAR_U_(0x0055DA2C, int*)
#define f_persp	VAR_U_(0x0051D15C, float)
#define f_znear	VAR_U_(0x0051D158, float)
#define	f_znear3	VAR_U_(0x0055D24C, float)
#define	f_zfar	VAR_U_(0x0055DA38, float)
#define f_oneopersp	VAR_U_(0x0055D254, float)
#define phd_centery	VAR_U_(0x0055D1B4, int)
#define	phd_centerx	VAR_U_(0x0055D1B0, int)
#define font_height	VAR_U_(0x00E4DEA8, int)
#define	CurrentFOV	VAR_U_(0x00E4F504, short)
#define	phd_winheight	VAR_U_(0x0055D164, int)
#define	phd_winwidth	VAR_U_(0x0055D29C, int)
#define	f_persp_bis	VAR_U_(0x0055D268, float)
#define	f_persp_bis_over_znear3	VAR_U_(0x0055D238, float)
#define	one	VAR_U_(0x0050A444, float)
#define	phd_persp	VAR_U_(0x0055D208, int)
#define	LfAspectCorrection	VAR_U_(0x0055DA30, float)
#define	f_perspoznear	VAR_U_(0x0055D668, float)
#define IsRoomOutsideNo	VAR_U_(0x00EEF902, short)
#define _CutSceneTriggered1	VAR_U_(0x00EEF004, unsigned long)
#define _CutSceneTriggered2	VAR_U_(0x00EEF000, unsigned long)
#define richcutfrigflag	VAR_U_(0x0051CA5E, char)



//GUESSED
#define gfFogColour	VAR_U_(0x0051CE30, CVECTOR)
#define	lara1_look_fade	VAR_U_(0x00511A18, short)
#define	lara4_look_fade	VAR_U_(0x00511A1A, short)

//arrays
#define cutseq_meshbits	ARRAY_(0x00E7EEA0, unsigned long, [10])
#define objects	ARRAY_(0x0086CF50, OBJECT_INFO, [460])
#define SmashedMesh	ARRAY_(0x00EEF8C0, MESH_INFO*, [16])
#define SmashedMeshRoom	ARRAY_(0x00EEF480, short, [16])
#define blood	ARRAY_(0x00E4C9C0, BLOOD_STRUCT, [32])
#define RPickups	ARRAY_(0x00E596E0, unsigned char, [16])
#define AnimatingWaterfalls	ARRAY_(0x00E59720, OBJECT_TEXTURE*, [6])
#define AnimatingWaterfallsV	ARRAY_(0x00E59760, float, [6])
#define interpolated_bounds	ARRAY_(0x00E6E4D0, short, [6])
#define LM	ARRAY_(0x00506B94, char, [15])
#define	keymap	ARRAY_(0x0086BB8C, char, [256])
#define gfTakeaways	ARRAY_(0x00E5C290, unsigned char, [16])
#define gfPickups	ARRAY_(0x00E5C300, unsigned char, [16])
#define	weapons	ARRAY_(0x005085B0, WEAPON_INFO, [9])
#define	DeadlyBounds	ARRAY_(0x00E6C3C0, long, [6])
#define cutseq_meshswapbits	ARRAY_(0x00E7EEE0, unsigned long, [10])
#define	cutseq_control_routines	ARRAY_(0x00506DA0, CUTSEQ_ROUTINES, [45])
#define fmv_to_play	ARRAY_(0x0051CE28, char, [2])
#define gfResidentCut	ARRAY_(0x00E5C278, unsigned char, [4])
#define	LightningRGB	ARRAY_(0x00E6E4B8, unsigned short, [3])
#define LightningRGBs	ARRAY_(0x00E6CAF0, unsigned short, [3])
#define gfMips	ARRAY_(0x00E5C2C0, unsigned char, [8])
#define inventry_objects_list	ARRAY_(0x00508E38, INVOBJ, [100])
#define itemlist	ARRAY_(0x00E88EA0, ITEM_INFO*, [1024])//what the fucking fuck
#define meshlist	ARRAY_(0x00E872A0, MESH_INFO*, [1024])//what the fucking fuck
#define staticlist	ARRAY_(0x00E89EA0, MESH_INFO*, [1024])//what the fucking fuck
#define	FootPrint	ARRAY_(0x00E5C3E0, FOOTPRINT, [32])
#define	gfLevelNames	ARRAY_(0x00E5C320, unsigned char, [40])
#define	dynamics	ARRAY_(0x00E6C3E0, DYNAMIC, [64])
#define Slist	ARRAY_(0x00E51FE0, SPHERE, [34])
#define keypadinputs	ARRAY_(0x00E59778, unsigned char, [4])
#define hairs	ARRAY_(0x00E5C000, HAIR_STRUCT, [2][7])
#define smoke_spark	ARRAY_(0x00E4B940, SMOKE_SPARKS, [32])
#define layout	ARRAY_(0x00516C3C, short, [2][18])
#define conflict	ARRAY_(0x00878C4C, int, [18])
#define reg_class	ARRAY_(0x0057A080, char, [4])
#define flip_stats	ARRAY_(0x00EEF060, int, [255])
#define LaSlot	ARRAY_(0x00E52420, SoundSlot, [32])
#define rings	ARRAY_(0x00E59900, RINGME*, [2])
#define SequenceUsed	ARRAY_(0x00E4EA78, unsigned char, [6])
#define SequenceResults	ARRAY_(0x00E4EA80, unsigned char, [3][3][3])
#define Sequences	ARRAY_(0x00E4EA9C, unsigned char, [3])
#define ClosedDoors	ARRAY_(0x0051CAC0, ITEM_INFO*, [32])
#define flipmap	ARRAY_(0x00EEEBA0, int, [255])
#define spark	ARRAY_(0x00E5F380, SPARKS, [128])
#define pickups	ARRAY_(0x00E5BF40, DISPLAYPU, [8])
#define ShatterSounds	ARRAY_(0x00506BAC, unsigned char, [18][10])


//defs
#define NO_HEIGHT -32512
#define	NO_ITEM	-1


//unknowns
#define dword_51CE04	VAR_U_(0x0051CE04, int)//SetFog
#define	dword_50A440	VAR_U_(0x0050A440, float)//AlterFOV
#define	flt_55D1F8	VAR_U_(0x0055D1F8, float)//AlterFOV
#define	dword_55D224	VAR_U_(0x0055D224, int)//AlterFOV
#define byte_51CB40	VAR_U_(0x0051CB40, char)//OpenThatDoor//DoorControl
#define dword_00E916F0	VAR_U_(0x00E916F0, int)//special 1 control, special 2 init, special 3 init, special 4 init
