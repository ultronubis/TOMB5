#pragma once
#include "../global/vars.h"

void inject_tomb4fx(bool replace);

long GetFreeBlood();
void UpdateBlood();
void TriggerBlood(long x, long y, long z, long angle, long num);
long LSpline(long x, long* knots, long nk);
LIGHTNING_STRUCT* TriggerLightning(PHD_VECTOR* s, PHD_VECTOR* d, char variation, long rgb, uchar flags, uchar size, uchar segments);
void LaraBubbles(ITEM_INFO* item);
void ControlElectricFence(short item_number);
void ControlTeleporter(short item_number);
void DrawWeaponMissile(ITEM_INFO* item);
void DrawLensFlares(ITEM_INFO* item);
long ExplodingDeath2(short item_number, long mesh_bits, short Flags);
void SetGunFlash(short weapon);
void DrawGunflashes();
void trig_actor_gunflash(long* mx, PHD_VECTOR* pos);
void TriggerLightningGlow(long x, long y, long z, long rgb);
void CalcLightningSpline(PHD_VECTOR* pos, SVECTOR* dest, LIGHTNING_STRUCT* lptr);
void UpdateLightning();
void TriggerShockwaveHitEffect(long x, long y, long z, long rgb, short dir, long speed);
long GetFreeShockwave();
void TriggerShockwave(PHD_VECTOR* pos, long InnerOuterRads, long speed, long bgrl, long XRotFlags);
void UpdateShockwaves();
long GetFreeDrip();
void TriggerLaraDrips();
void UpdateDrips();
void Fade();
void SetScreenFadeOut(short speed, short back);
void SetScreenFadeIn(short speed);
void UpdateFadeClip();
void SetFadeClip(short height, short speed);
long GetFreeBubble();
void CreateBubble(PHD_3DPOS* pos, short room_number, long size, long biggest, long flags, short xv, short yv, short zv);
void UpdateBubbles();
void TriggerSmallSplash(long x, long y, long z, long num);
long GetFreeGunshell();
void TriggerGunShell(short leftright, short objnum, long weapon);
void UpdateGunShells();
void DrawGunshells();
void TriggerShatterSmoke(long x, long y, long z);
void TriggerGunSmoke(long x, long y, long z, long xVel, long yVel, long zVel, long notLara, long weaponType, long shade);
long GetFreeSmokeSpark();
void UpdateSmokeSparks();
void S_DrawFires();
void AddFire(long x, long y, long z, long size, short room_number, short fade);
long GetFreeFireSpark();
void TriggerGlobalFireSmoke();
void TriggerGlobalFireFlame();
void TriggerGlobalStaticFlame();
void ClearFires();
void keep_those_fires_burning();
void UpdateFireSparks();
void TriggerFenceSparks(long x, long y, long z, long yv, long fric);

extern LIGHTNING_STRUCT Lightning[16];
extern SHOCKWAVE_STRUCT ShockWaves[16];
extern DRIP_STRUCT Drips[32];
extern BUBBLE_STRUCT Bubbles[40];
extern RIPPLE_STRUCT ripples[32];
extern SPLASH_STRUCT splashes[4];
extern DEBRIS_STRUCT debris[256];
extern GUNFLASH_STRUCT Gunflashes[4];
extern GUNSHELL_STRUCT Gunshells[24];
extern FIRE_SPARKS fire_spark[20];
extern SPARKS spark[1024];
extern SP_DYNAMIC spark_dynamics[8];
extern FIRE_LIST fires[32];
extern SMOKE_SPARKS smoke_spark[32];
extern BLOOD_STRUCT blood[32];
extern long next_fire_spark;
extern long next_smoke_spark;
extern long next_gunshell;
extern long next_bubble;
extern long next_drip;
extern long next_blood;
extern long next_debris;
extern short FlashFadeR;
extern short FlashFadeG;
extern short FlashFadeB;
extern short FlashFader;
extern short ScreenFade;
extern short dScreenFade;
extern short ScreenFadeBack;
extern short ScreenFadedOut;
extern short ScreenFading;
extern short FadeScreenHeight;
extern short DestFadeScreenHeight;
extern short ScreenFadeSpeed;
extern char scratchpad[1024];
extern char tsv_buffer[16384];
