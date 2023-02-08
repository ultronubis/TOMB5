#include "../tomb5/pch.h"
#include "effects.h"
#include "sound.h"
#include "hair.h"
#include "delstuff.h"
#include "control.h"
#include "tomb4fx.h"
#include "items.h"
#include "deltapak.h"
#include "spider.h"
#include "lot.h"
#include "effect2.h"
#include "objects.h"
#include "sphere.h"
#include "../specific/dxsound.h"
#include "footprnt.h"
#include "../specific/function_stubs.h"
#include "../specific/audio.h"
#include "../specific/function_table.h"
#include "../specific/polyinsert.h"
#include "../specific/3dmath.h"
#include "draw.h"

long FogTableColor[28] =
{
	0,
	RGBONLY(245, 200, 60),
	RGBONLY(120, 196, 112),
	RGBONLY(202, 204, 230),
	RGBONLY(128, 64, 0),
	RGBONLY(64, 64, 64),
	RGBONLY(243, 232, 236),
	RGBONLY(0, 64, 192),
	RGBONLY(0, 128, 0),
	RGBONLY(150, 172, 157),
	RGBONLY(128, 128, 128),
	RGBONLY(204, 163, 123),
	RGBONLY(177, 162, 140),
	RGBONLY(0, 223, 191),
	RGBONLY(111, 255, 223),
	RGBONLY(244, 216, 152),
	RGBONLY(248, 192, 60),
	RGBONLY(252, 0, 0),
	RGBONLY(198, 95, 87),
	RGBONLY(226, 151, 118),
	RGBONLY(248, 235, 206),
	RGBONLY(0, 30, 16),
	RGBONLY(250, 222, 167),
	RGBONLY(218, 175, 117),
	RGBONLY(225, 191, 78),
	RGBONLY(77, 140, 141),
	RGBONLY(4, 181, 154),
	RGBONLY(255, 174, 0)
};

void(*effect_routines[59])(ITEM_INFO* item) =
{
	turn180_effect,
	floor_shake_effect,
	PoseidonSFX,
	LaraBubbles,
	finish_level_effect,
	ActivateCamera,
	ActivateKey,
	RubbleFX,
	SwapCrowbar,
	void_effect,
	SoundFlipEffect,
	ExplosionFX,
	lara_hands_free,
	void_effect,
	void_effect,
	void_effect,
	shoot_right_gun,
	shoot_left_gun,
	void_effect,
	void_effect,
	void_effect,
	invisibility_on,
	invisibility_off,
	void_effect,
	void_effect,
	void_effect,
	reset_hair,
	void_effect,
	SetFog,
	void_effect,
	LaraLocation,
	ClearSpidersPatch,
	AddFootprint,
	ResetTest,
	void_effect,
	void_effect,
	void_effect,
	void_effect,
	void_effect,
	void_effect,
	void_effect,
	void_effect,
	void_effect,
	void_effect,
	void_effect,
	LaraLocationPad,
	KillActiveBaddies,
	TL_1,
	TL_2,
	TL_3,
	TL_4,
	TL_5,
	TL_6,
	TL_7,
	TL_8,
	TL_9,
	TL_10,
	TL_11,
	TL_12,
};

void WaterFall(short item_number)
{
	ITEM_INFO* item;
	long x, z, ang;

	item = &items[item_number];
	ang = item->pos.y_rot + 0x8000;
	x = item->pos.x_pos - (phd_sin(ang) * 512 >> 14);
	z = item->pos.z_pos - (phd_cos(ang) * 512 >> 14);

	switch (ang)
	{
	case 0:
		x += (phd_sin(ang + 0x4000) * _wf >> 14);
		z += (phd_cos(ang + 0x4000) * _wf >> 14);
		break;

	default:
		x += (phd_sin(ang - 0x4000) * _wf >> 14);
		z += (phd_cos(ang - 0x4000) * _wf >> 14);
		break;
	}

	TriggerWaterfallMist(x, item->pos.y_pos, z, item->pos.y_rot + 0x8000);
	SoundEffect(SFX_WATERFALL_LOOP, &item->pos, SFX_DEFAULT);
}


void void_effect(ITEM_INFO* item)
{
	return;
}

void turn180_effect(ITEM_INFO* item)
{
	item->pos.y_rot -= 32768;
	item->pos.x_rot = -item->pos.x_rot;
}

void floor_shake_effect(ITEM_INFO* item)
{
	long dx, dy, dz, dist;

	dx = item->pos.x_pos - camera.pos.x;
	dy = item->pos.y_pos - camera.pos.y;
	dz = item->pos.z_pos - camera.pos.z;

	if (abs(dx) < 0x4000 && abs(dy) < 0x4000 && abs(dz) < 0x4000)
	{
		dist = SQUARE(dx) + SQUARE(dy) + SQUARE(dz);
		camera.bounce = -66 * (0x100000 - dist / 256) / 0x100000;
	}
}

void PoseidonSFX(ITEM_INFO* item)
{
	SoundEffect(SFX_J_GRAB_OPEN, 0, SFX_DEFAULT);
	flipeffect = -1;
}

void finish_level_effect(ITEM_INFO* item)
{
	gfLevelComplete = gfCurrentLevel + 1;
}

void ActivateCamera(ITEM_INFO* item)
{
	KeyTriggerActive = 2;
}

void ActivateKey(ITEM_INFO* item)
{
	KeyTriggerActive = 1;
}

void RubbleFX(ITEM_INFO* item)
{
	ITEM_INFO* eq;
	
	eq = find_a_fucking_item(EARTHQUAKE);

	if (eq)
	{
		AddActiveItem(eq - items);
		eq->status = ITEM_ACTIVE;
		eq->flags |= IFL_CODEBITS;
	}
	else
		camera.bounce = -150;

	flipeffect = -1;
}

void SwapCrowbar(ITEM_INFO* item)
{
	short* tmp;
	
	tmp = meshes[objects[LARA].mesh_index + 2 * LM_RHAND];

	if (lara.mesh_ptrs[LM_RHAND] == tmp)
		lara.mesh_ptrs[LM_RHAND] = meshes[objects[CROWBAR_ANIM].mesh_index + (2 * LM_RHAND)];
	else
		lara.mesh_ptrs[LM_RHAND] = tmp;
}

void SoundFlipEffect(ITEM_INFO* item)
{
	SoundEffect(TriggerTimer, 0, SFX_DEFAULT);
	flipeffect = -1;
}

void ExplosionFX(ITEM_INFO* item)
{
	SoundEffect(SFX_EXPLOSION1, 0, SFX_DEFAULT);
	camera.bounce = -75;
	flipeffect = -1;
}

void lara_hands_free(ITEM_INFO* item)
{
	lara.gun_status = LG_NO_ARMS;
}

void shoot_right_gun(ITEM_INFO* item)
{
	lara.right_arm.flash_gun = 3;
}

void shoot_left_gun(ITEM_INFO* item)
{
	lara.left_arm.flash_gun = 3;
}

void invisibility_on(ITEM_INFO* item)
{
	item->status = ITEM_INVISIBLE;
}

void invisibility_off(ITEM_INFO* item)
{
	item->status = ITEM_ACTIVE;
}

void reset_hair(ITEM_INFO* item)
{
	InitialiseHair();
}

void SetFog(ITEM_INFO* item)
{
	ushort rgb;
	char r, g, b;

	GlobalFogOff = 0;
	rgb = TriggerTimer;

	if (!IsVolumetric())
	{
		flipeffect = -1;
		return;
	}

	if (TriggerTimer == 100)
	{
		GlobalFogOff = 1;
		flipeffect = -1;
		return;
	}

	r = (FogTableColor[rgb] >> 16) & 0xFF;
	g = (FogTableColor[rgb] >> 8) & 0xFF;
	b = FogTableColor[rgb] & 0xFF;
	SetFogColor(r, g, b);
	gfFog.r = r;
	gfFog.g = g;
	gfFog.b = b;
	flipeffect = -1;
	return;
}

void LaraLocation(ITEM_INFO* item)
{
	lara.location = TriggerTimer;

	if (lara.highest_location < TriggerTimer)
		lara.highest_location = TriggerTimer;

	flipeffect = -1;
}

void ClearSpidersPatch(ITEM_INFO* item)
{
	ClearSpiders();
}

void ResetTest(ITEM_INFO* item)
{
	ITEM_INFO* target_item;
	short room_num, item_num;

	for (item_num = next_item_active; item_num != NO_ITEM; item_num = target_item->next_active)
	{
		target_item = &items[item_num];

		if (objects[target_item->object_number].intelligent)
		{
			target_item->status = ITEM_INVISIBLE;
			RemoveActiveItem(item_num);
			DisableBaddieAI(item_num);
			room_num = target_item->item_flags[2] & 0xFF;
			target_item->pos.y_pos = target_item->item_flags[2] + room[room_num].minfloor;
			target_item->pos.x_pos = ((target_item->item_flags[1] << 2) + room[room_num].x + 512);
			target_item->pos.z_pos = (((target_item->item_flags[1] & 0xFF) << 10) + room[room_num].z + 512);
			target_item->pos.y_rot = target_item->TOSSPAD;
			target_item->item_flags[3] = target_item->item_flags[0] & 0xFF;
			target_item->ai_bits = target_item->item_flags[0] >> 8;

			if (target_item->object_number == CHEF)
				target_item->anim_number = objects[CHEF].anim_index + 0;
			else if (target_item->object_number == TWOGUN)
				target_item->anim_number = objects[TWOGUN].anim_index + 6;
			else if (objects[SWAT].loaded)
				target_item->anim_number = objects[SWAT].anim_index + 0;
			else
				target_item->anim_number = objects[BLUE_GUARD].anim_index + 0;

			target_item->current_anim_state = 1;
			target_item->goal_anim_state = 1;
			target_item->frame_number = anims[target_item->anim_number].frame_base;

			if (target_item->room_number != room_num)
				ItemNewRoom(item_num, room_num);
		}
	}

	flipeffect = -1;
}

void LaraLocationPad(ITEM_INFO* item)
{
	flipeffect = -1;
	lara.location = TriggerTimer;
	lara.locationPad = TriggerTimer;
}

void KillActiveBaddies(ITEM_INFO* item)
{
	ITEM_INFO* target_item;
	short item_num;

	for (item_num = next_item_active; item_num != NO_ITEM; item_num = target_item->next_active)
	{
		target_item = &items[item_num];

		if (objects[target_item->object_number].intelligent)
		{
			target_item->status = ITEM_INVISIBLE;

			if (item != ((void*)0xABCDEF))
			{
				RemoveActiveItem(item_num);
				DisableBaddieAI(item_num);
				target_item->flags |= IFL_INVISIBLE;
			}
		}
	}

	flipeffect = -1;
}

void BaddieBiteEffect(ITEM_INFO* item, BITE_INFO* bite)
{
	PHD_VECTOR pos;

	pos.x = bite->x;
	pos.y = bite->y;
	pos.z = bite->z;
	GetJointAbsPosition(item, &pos, bite->mesh_num);
	DoBloodSplat(pos.x, pos.y, pos.z, (GetRandomControl() & 3) + 4, item->pos.y_rot, item->room_number);
}

void TL_1(ITEM_INFO* item)
{
	if (savegame.TLCount < 1)
	{
		IsAtmospherePlaying = 0;
		S_CDPlay(9, 0);
		savegame.TLCount = 1;
	}
}

void TL_2(ITEM_INFO* item)
{
	if (savegame.TLCount < 2)
	{
		IsAtmospherePlaying = 0;
		S_CDPlay(7, 0);
		savegame.TLCount = 2;
	}
}

void TL_3(ITEM_INFO* item)
{
	if (savegame.TLCount < 3)
	{
		IsAtmospherePlaying = 0;
		S_CDPlay(23, 0);
		savegame.TLCount = 3;
	}
}

void TL_4(ITEM_INFO* item)
{
	if (savegame.TLCount < 4)
	{
		IsAtmospherePlaying = 0;
		S_CDPlay(39, 0);
		savegame.TLCount = 4;
	}
}

void TL_5(ITEM_INFO* item)
{
	if (savegame.TLCount < 5)
	{
		IsAtmospherePlaying = 0;
		S_CDPlay(2, 0);
		savegame.TLCount = 5;
	}
}

void TL_6(ITEM_INFO* item)
{
	if (savegame.TLCount < 6)
	{
		IsAtmospherePlaying = 0;
		S_CDPlay(22, 0);
		savegame.TLCount = 6;
	}
}

void TL_7(ITEM_INFO* item)
{
	if (savegame.TLCount < 7)
	{
		IsAtmospherePlaying = 0;
		S_CDPlay(51, 0);
		savegame.TLCount = 7;
	}
}


void TL_8(ITEM_INFO* item)
{
	if (savegame.TLCount < 8)
	{
		IsAtmospherePlaying = 0;
		S_CDPlay(3, 0);
		savegame.TLCount = 8;
	}
}

void TL_9(ITEM_INFO* item)
{
	if (savegame.TLCount < 9)
	{
		IsAtmospherePlaying = 0;
		S_CDPlay(4, 0);
		savegame.TLCount = 9;
	}
}

void TL_10(ITEM_INFO* item)
{
	if (savegame.TLCount == 9)
	{
		IsAtmospherePlaying = 0;
		S_CDPlay(13, 0);
		savegame.TLCount = 10;
	}
}

void TL_11(ITEM_INFO* item)
{
	if (savegame.TLCount == 10)
	{
		IsAtmospherePlaying = 0;
		S_CDPlay(0, 0);
		savegame.TLCount = 11;
	}
}

void TL_12(ITEM_INFO* item)
{
	if (savegame.TLCount == 11)
	{
		IsAtmospherePlaying = 0;
		S_CDPlay(35, 0);
		savegame.TLCount = 12;
	}
}

void SoundEffects()
{
	OBJECT_VECTOR* sound;
	SoundSlot* slot;
	
	for (int i = 0; i < number_sound_effects; i++)
	{
		sound = &sound_effects[i];

		if (flip_stats[((sound->flags & 1) + (sound->flags & 2)
			+ 3 * (((sound->flags & 0x1F) >> 2) & 1)
			+ 5 * (((sound->flags & 0x1F) >> 4) & 1)
			+ 4 * (((sound->flags & 0x1F) >> 3) & 1))])
		{
			if (sound->flags & 0x40)
			{
				SoundEffect(sound->data, (PHD_3DPOS*)sound, 0);
				continue;
			}
		}
		else if (sound->flags & 0x80)
		{
			SoundEffect(sound->data, (PHD_3DPOS*)sound, 0);
			continue;
		}
	}

	if (flipeffect != -1)
		effect_routines[flipeffect](0);

	if (!sound_active)
		return;

	for (int i = 0; i < 32; i++)
	{
		slot = &LaSlot[i];

		if (slot->nSampleInfo >= 0)
		{
			if ((sample_infos[slot->nSampleInfo].flags & 3) != 3)
			{
				if (!S_SoundSampleIsPlaying(i))
					slot->nSampleInfo = -1;
				else
				{
					GetPanVolume(slot);
					S_SoundSetPanAndVolume(i, (short)slot->nPan, (ushort)slot->nVolume);
				}
			}
			else
			{
				if (!slot->nVolume)
				{
					S_SoundStopSample(i);
					slot->nSampleInfo = -1;
				}
				else
				{
					S_SoundSetPanAndVolume(i, (short)slot->nPan, (ushort)slot->nVolume);
					S_SoundSetPitch(i, slot->nPitch);
					slot->nVolume = 0;
				}
			}
		}
	}
}

short DoBloodSplat(long x, long y, long z, short random, short y_rot, short room_number)
{
	GetFloor(x, y, z, &room_number);

	if (room[room_number].flags & ROOM_UNDERWATER)
		TriggerUnderwaterBlood(x, y, z, random);
	else
		TriggerBlood(x, y, z, y_rot >> 4, random);

	return -1;
}

void DoLotsOfBlood(long x, long y, long z, short speed, short ang, short room_number, long num)
{
	long bx, by, bz;

	for (; num > 0; num--)
	{
		bx = x - (GetRandomControl() << 9) / 0x8000 + 256;
		by = y - (GetRandomControl() << 9) / 0x8000 + 256;
		bz = z - (GetRandomControl() << 9) / 0x8000 + 256;
		DoBloodSplat(bx, by, bz, speed, ang, room_number);
	}
}

long ItemNearLara(PHD_3DPOS* pos, long rad)
{
	short* bounds;
	long dx, dy, dz;

	dx = pos->x_pos - lara_item->pos.x_pos;
	dy = pos->y_pos - lara_item->pos.y_pos;
	dz = pos->z_pos - lara_item->pos.z_pos;

	if (dx >= -rad && dx <= rad && dz >= -rad && dz <= rad && dy >= -3072 && dy <= 3072 && SQUARE(dx) + SQUARE(dz) <= SQUARE(rad))
	{
		bounds = GetBoundsAccurate(lara_item);

		if (dy >= bounds[2] && dy <= bounds[3] + 100)
			return 1;
	}

	return 0;
}

void Richochet(GAME_VECTOR* pos)
{
	TriggerRicochetSpark(pos, mGetAngle(pos->z, pos->x, lara_item->pos.z_pos, lara_item->pos.x_pos) >> 4, 3, 0);
	SoundEffect(SFX_LARA_RICOCHET, (PHD_3DPOS*)pos, SFX_DEFAULT);
}

void inject_effects(bool replace)
{
	INJECT(0x00432640, SoundEffects, replace);
	INJECT(0x00432CA0, WaterFall, replace);
	INJECT(0x00432DD0, void_effect, replace);
	INJECT(0x00432E10, turn180_effect, replace);
	INJECT(0x00432E40, floor_shake_effect, replace);
	INJECT(0x00432FD0, PoseidonSFX, replace);
	INJECT(0x00432DF0, finish_level_effect, replace);
	INJECT(0x00433000, ActivateCamera, replace);
	INJECT(0x00433020, ActivateKey, replace);
	INJECT(0x00432F40, RubbleFX, replace);
	INJECT(0x00433040, SwapCrowbar, replace);
	INJECT(0x00432F10, SoundFlipEffect, replace);
	INJECT(0x00433080, ExplosionFX, replace);
	INJECT(0x00433440, lara_hands_free, replace);
	INJECT(0x00433460, shoot_right_gun, replace);
	INJECT(0x00433480, shoot_left_gun, replace);
	INJECT(0x00433570, invisibility_on, replace);
	INJECT(0x00433590, invisibility_off, replace);
	INJECT(0x004335C0, reset_hair, replace);
	INJECT(0x004334A0, SetFog, replace);
	INJECT(0x004330C0, LaraLocation, replace);
	INJECT(0x00433670, ClearSpidersPatch, replace);
	INJECT(0x00433130, ResetTest, replace);
	INJECT(0x00433100, LaraLocationPad, replace);
	INJECT(0x00433360, KillActiveBaddies, replace);
	INJECT(0x004335E0, BaddieBiteEffect, replace);
	INJECT(0x00433690, TL_1, replace);
	INJECT(0x004336D0, TL_2, replace);
	INJECT(0x00433710, TL_3, replace);
	INJECT(0x00433750, TL_4, replace);
	INJECT(0x00433790, TL_5, replace);
	INJECT(0x004337D0, TL_6, replace);
	INJECT(0x00433810, TL_7, replace);
	INJECT(0x00433850, TL_8, replace);
	INJECT(0x00433890, TL_9, replace);
	INJECT(0x004338D0, TL_10, replace);
	INJECT(0x00433910, TL_11, replace);
	INJECT(0x00433950, TL_12, replace);
	INJECT(0x00432760, DoBloodSplat, replace);
	INJECT(0x00432800, DoLotsOfBlood, replace);
	INJECT(0x00432580, ItemNearLara, replace);
	INJECT(0x00432710, Richochet, replace);
}
