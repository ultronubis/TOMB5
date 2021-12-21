#include "../tomb5/pch.h"
#include "debris.h"
#include "../specific/function_stubs.h"
#include "tomb4fx.h"
#include "../specific/3dmath.h"

void TriggerDebris(GAME_VECTOR* pos, void* TextInfo, short* Offsets, long* Vels, short rgb)
{
	DEBRIS_STRUCT* dptr;

	if (GetRandomControl() & 3)
	{
		if (rgb < 0)
			rgb = -rgb;
	}
	else if (rgb >= 0)
		TriggerShatterSmoke(pos->x, pos->y, pos->z);

	dptr = &debris[GetFreeDebris()];
	dptr->On = 2;
	dptr->x = pos->x;
	dptr->y = pos->y;
	dptr->z = pos->z;

	if (DebrisFlags & 1)
	{
		dptr->Dir = GetRandomControl() << 1;
		dptr->Speed = (GetRandomControl() & 0xF) + 16;
		dptr->Yvel = -64 - (GetRandomControl() & 0x7F);
		dptr->Gravity = (GetRandomControl() & 0x1F) + 16;
	}
	else
	{
		dptr->Dir = (short)(phd_atan(Vels[2], Vels[0]));

		if (Vels[0] < 0)
			Vels[0] = -Vels[0];

		if (Vels[2] < 0)
			Vels[2] = -Vels[2];

		dptr->Speed = (short)((Vels[0] + Vels[2]) >> 2);
		dptr->Speed = (short)(phd_sqrt(SQUARE(Vels[0]) + SQUARE(Vels[2])) >> 3);

		if (Vels[1])
		{
			dptr->Yvel = -512 - (GetRandomControl() & 0x1FF);
			dptr->Gravity = (GetRandomControl() & 0x3F) + 64;

			if (Vels[1] == -1)
				dptr->Yvel *= 2;
		}
		else
		{
			dptr->Yvel = 0;
			dptr->Gravity = (GetRandomControl() & 0x1F) + 32;
		}
	}

	dptr->RoomNumber = pos->room_number;
	dptr->XYZOffsets1[0] = Offsets[0];
	dptr->XYZOffsets1[1] = Offsets[1];
	dptr->XYZOffsets1[2] = Offsets[2];
	dptr->XYZOffsets2[0] = Offsets[3];
	dptr->XYZOffsets2[1] = Offsets[4];
	dptr->XYZOffsets2[2] = Offsets[5];
	dptr->XYZOffsets3[0] = Offsets[6];
	dptr->XYZOffsets3[1] = Offsets[7];
	dptr->XYZOffsets3[2] = Offsets[8];

	if (DebrisFlags & 1)
	{
		dptr->YRot = (GetRandomControl() & 0xFF) << 1;
		dptr->XRot = dptr->YRot;
	}
	else
	{
		dptr->YRot = 0;
		dptr->XRot = 0;
	}

	dptr->TextInfo = TextInfo;
	dptr->r = rgb << 3;
	dptr->g = (rgb >> 5) << 3;
	dptr->b = (rgb >> 10) << 3;

	if (DebrisMesh->prelight)
	{
		dptr->color1 = DebrisMesh->prelight[DebrisMeshC1];
		dptr->color2 = DebrisMesh->prelight[DebrisMeshC2];
		dptr->color3 = DebrisMesh->prelight[DebrisMeshC3];
		dptr->ambient = 0;
	}
	else
	{
		dptr->color1 = 0;
		dptr->color2 = 0;
		dptr->color3 = 0;
		dptr->ambient = DebrisMeshAmbient;
	}

	dptr->flags = DebrisMeshFlags;
}

void inject_debris(bool replace)
{
	INJECT(0x0041D210, TriggerDebris, replace);
}
