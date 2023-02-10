#pragma once
#include "../global/vars.h"

void inject_box(bool replace);

void InitialiseCreature(short item_number);
long CreatureActive(short item_number);
void CreatureAIInfo(ITEM_INFO* item, AI_INFO* info);

#define AlertNearbyGuards	( (void(__cdecl*)(ITEM_INFO*)) 0x0040BB10 )
#define CreatureDie	( (void(__cdecl*)(short, long)) 0x0040A090 )
#define GetAITarget	( (void(__cdecl*)(CREATURE_INFO*)) 0x0040BCC0 )
#define GetCreatureMood	( (void(__cdecl*)(ITEM_INFO*, AI_INFO*, long)) 0x004090A0 )
#define CreatureMood	( (void(__cdecl*)(ITEM_INFO*, AI_INFO*, long)) 0x00409370 )
#define CreatureTurn	( (short(__cdecl*)(ITEM_INFO*, short)) 0x0040AE90 )
#define CreatureTilt	( (void(__cdecl*)(ITEM_INFO*, short)) 0x0040B1B0 )
#define CreatureJoint	( (void(__cdecl*)(ITEM_INFO*, short, short)) 0x0040B240 )
#define CreatureAnimation	( (long(__cdecl*)(short, short, short)) 0x0040A1D0 )
typedef short(__cdecl* generate)(long, long, long, short, short, short);
#define CreatureEffectT	( (short(__cdecl*)(ITEM_INFO*, BITE_INFO*, short, short, generate)) 0x0040B550 )
#define CreatureEffect	( (short(__cdecl*)(ITEM_INFO*, BITE_INFO*, generate)) 0x0040B4D0 )
#define	CreatureUnderwater	( (void(__cdecl*)(ITEM_INFO*, long)) 0x0040B400 )
#define AlertAllGuards	( (void(__cdecl*)(short)) 0x0040BA70 )
#define AIGuard	( (short(__cdecl*)(CREATURE_INFO*)) 0x0040BBE0 )
#define CreatureVault	( (long(__cdecl*)(short, short, long, long)) 0x0040B5D0 )
#define DropBaddyPickups	( (void(__cdecl*)(ITEM_INFO*)) 0x0040C5A0 )
