#include "../tomb5/pch.h"
#include "tomb5.h"
#include "../specific/registry.h"
#include "../game/gameflow.h"
#include "../game/lara.h"

tomb5_options tomb5;

void init_tomb5_stuff()
{
	char buf[40];
	bool first;

	OpenRegistry("tomb5");
	first = REG_KeyWasCreated();

	if (first)	//key was created = no settings found, write defaults
	{
		sprintf(buf, "footprints");
		tomb5.footprints = 1;							//footprints on
		REG_WriteBool(buf, tomb5.footprints);

		sprintf(buf, "shadow");
		tomb5.shadow_mode = 3;							//PSX like shadow
		REG_WriteLong(buf, tomb5.shadow_mode);

		sprintf(buf, "climbup");
		tomb5.fix_climb_up_delay = 1;					//no delay
		REG_WriteBool(buf, tomb5.fix_climb_up_delay);

		sprintf(buf, "flex_crawl");
		tomb5.flexible_crawling = 1;					//on
		REG_WriteBool(buf, tomb5.flexible_crawling);

		sprintf(buf, "cutseq_skipper");
		tomb5.cutseq_skipper = 0;						//off
		REG_WriteBool(buf, tomb5.cutseq_skipper);

		sprintf(buf, "cheats");
		tomb5.enable_cheats = 0;						//off
		REG_WriteBool(buf, tomb5.enable_cheats);

		sprintf(buf, "bar_pos");
		tomb5.bars_pos = 1;								//original
		REG_WriteLong(buf, tomb5.bars_pos);

		sprintf(buf, "enemy_bar");
		tomb5.enemy_bars = 0;							//off
		REG_WriteBool(buf, tomb5.enemy_bars);

		sprintf(buf, "ammo_counter");
		tomb5.ammo_counter = 0;							//off
		REG_WriteBool(buf, tomb5.ammo_counter);

		sprintf(buf, "gameover");
		tomb5.gameover = 1;								//on
		REG_WriteBool(buf, tomb5.gameover);

		sprintf(buf, "fog");
		tomb5.fog = 1;									//on
		REG_WriteBool(buf, tomb5.fog);

		sprintf(buf, "barMode");
		tomb5.bar_mode = 3;								//PSX
		REG_WriteLong(buf, tomb5.bar_mode);

		sprintf(buf, "crawltilt");
		tomb5.crawltilt = 1;							//on
		REG_WriteBool(buf, tomb5.crawltilt);

		sprintf(buf, "psxsky");
		tomb5.PSX_skies = 1;							//on
		REG_WriteBool(buf, tomb5.PSX_skies);

		sprintf(buf, "tr4LS");
		tomb5.tr4_loadscreens = 1;						//on
		REG_WriteBool(buf, tomb5.tr4_loadscreens);

		sprintf(buf, "tr4LB");
		tomb5.tr4_loadbar = 1;							//on
		REG_WriteBool(buf, tomb5.tr4_loadbar);

		sprintf(buf, "inv_bgM");
		tomb5.inv_bg_mode = 1;							//original
		REG_WriteLong(buf, tomb5.inv_bg_mode);

		sprintf(buf, "loadtxt");
		tomb5.loadingtxt = 1;							//on
		REG_WriteBool(buf, tomb5.loadingtxt);

		sprintf(buf, "shimmer");
		tomb5.shimmer = 1;								//on
		REG_WriteBool(buf, tomb5.shimmer);

		sprintf(buf, "distance_fog");
		tomb5.distance_fog = 12;						//default on PSX is 12
		REG_WriteLong(buf, tomb5.distance_fog);

		sprintf(buf, "ammotype_hotkeys");
		tomb5.ammotype_hotkeys = 1;						//on
		REG_WriteBool(buf, tomb5.ammotype_hotkeys);

		sprintf(buf, "ltransparency");
		tomb5.look_transparency = 0;					//off
		REG_WriteBool(buf, tomb5.look_transparency);

		sprintf(buf, "static_lighting");
		tomb5.static_lighting = 1;						//on
		REG_WriteBool(buf, tomb5.static_lighting);

		sprintf(buf, "uw_dust");
		tomb5.uw_dust = 2;								//original
		REG_WriteLong(buf, tomb5.uw_dust);

		sprintf(buf, "mmode");
		tomb5.mirrorMode = 0;							//off
		REG_WriteBool(buf, tomb5.mirrorMode);
	}
	else	//Key already exists, settings already written, read them. also falls back to default if a smartass manually deletes a single value
	{
		sprintf(buf, "footprints");
		REG_ReadBool(buf, tomb5.footprints, 1);

		sprintf(buf, "shadow");
		REG_ReadLong(buf, tomb5.shadow_mode, 3);

		sprintf(buf, "climbup");
		REG_ReadBool(buf, tomb5.fix_climb_up_delay, 1);

		sprintf(buf, "flex_crawl");
		REG_ReadBool(buf, tomb5.flexible_crawling, 1);

		sprintf(buf, "cutseq_skipper");
		REG_ReadBool(buf, tomb5.cutseq_skipper, 0);

		sprintf(buf, "cheats");
		REG_ReadBool(buf, tomb5.enable_cheats, 0);

		sprintf(buf, "bar_pos");
		REG_ReadLong(buf, tomb5.bars_pos, 1);

		sprintf(buf, "enemy_bar");
		REG_ReadBool(buf, tomb5.enemy_bars, 0);

		sprintf(buf, "ammo_counter");
		REG_ReadBool(buf, tomb5.ammo_counter, 0);

		sprintf(buf, "gameover");
		REG_ReadBool(buf, tomb5.gameover, 1);

		sprintf(buf, "fog");
		REG_ReadBool(buf, tomb5.fog, 1);

		sprintf(buf, "barMode");
		REG_ReadLong(buf, tomb5.bar_mode, 3);

		sprintf(buf, "crawltilt");
		REG_ReadBool(buf, tomb5.crawltilt, 1);

		sprintf(buf, "psxsky");
		REG_ReadBool(buf, tomb5.PSX_skies, 1);

		sprintf(buf, "tr4LS");
		REG_ReadBool(buf, tomb5.tr4_loadscreens, 1);

		sprintf(buf, "tr4LB");
		REG_ReadBool(buf, tomb5.tr4_loadbar, 1);

		sprintf(buf, "inv_bgM");
		REG_ReadLong(buf, tomb5.inv_bg_mode, 1);

		sprintf(buf, "loadtxt");
		REG_ReadBool(buf, tomb5.loadingtxt, 1);

		sprintf(buf, "shimmer");
		REG_ReadBool(buf, tomb5.shimmer, 1);

		sprintf(buf, "distance_fog");
		REG_ReadLong(buf, tomb5.distance_fog, 12);

		sprintf(buf, "ammotype_hotkeys");
		REG_ReadBool(buf, tomb5.ammotype_hotkeys, 1);

		sprintf(buf, "ltransparency");
		REG_ReadBool(buf, tomb5.look_transparency, 1);

		sprintf(buf, "static_lighting");
		REG_ReadBool(buf, tomb5.static_lighting, 1);

		sprintf(buf, "uw_dust");
		REG_ReadLong(buf, tomb5.uw_dust, 2);

		sprintf(buf, "mmode");
		REG_ReadBool(buf, tomb5.mirrorMode, 0);
	}

	CloseRegistry();
}

void save_new_tomb5_settings()
{
	char buf[40];
	OpenRegistry("tomb5");

	sprintf(buf, "footprints");
	REG_WriteBool(buf, tomb5.footprints);

	sprintf(buf, "shadow");
	REG_WriteLong(buf, tomb5.shadow_mode);

	sprintf(buf, "climbup");
	REG_WriteBool(buf, tomb5.fix_climb_up_delay);

	sprintf(buf, "flex_crawl");
	REG_WriteBool(buf, tomb5.flexible_crawling);

	sprintf(buf, "cutseq_skipper");
	REG_WriteBool(buf, tomb5.cutseq_skipper);

	sprintf(buf, "cheats");
	REG_WriteBool(buf, tomb5.enable_cheats);

	sprintf(buf, "bar_pos");
	REG_WriteLong(buf, tomb5.bars_pos);

	sprintf(buf, "enemy_bar");
	REG_WriteBool(buf, tomb5.enemy_bars);

	sprintf(buf, "ammo_counter");
	REG_WriteBool(buf, tomb5.ammo_counter);

	sprintf(buf, "gameover");
	REG_WriteBool(buf, tomb5.gameover);

	sprintf(buf, "fog");
	REG_WriteBool(buf, tomb5.fog);

	sprintf(buf, "barMode");
	REG_WriteLong(buf, tomb5.bar_mode);

	sprintf(buf, "crawltilt");
	REG_WriteBool(buf, tomb5.crawltilt);

	sprintf(buf, "psxsky");
	REG_WriteBool(buf, tomb5.PSX_skies);

	sprintf(buf, "tr4LS");
	REG_WriteBool(buf, tomb5.tr4_loadscreens);

	sprintf(buf, "tr4LB");
	REG_WriteBool(buf, tomb5.tr4_loadbar);

	sprintf(buf, "inv_bgM");
	REG_WriteLong(buf, tomb5.inv_bg_mode);

	sprintf(buf, "loadtxt");
	REG_WriteBool(buf, tomb5.loadingtxt);

	sprintf(buf, "shimmer");
	REG_WriteBool(buf, tomb5.shimmer);

	sprintf(buf, "distance_fog");
	REG_WriteLong(buf, tomb5.distance_fog);

	sprintf(buf, "ammotype_hotkeys");
	REG_WriteBool(buf, tomb5.ammotype_hotkeys);

	sprintf(buf, "ltransparency");
	REG_WriteBool(buf, tomb5.look_transparency);

	sprintf(buf, "static_lighting");
	REG_WriteBool(buf, tomb5.static_lighting);

	sprintf(buf, "uw_dust");
	REG_WriteLong(buf, tomb5.uw_dust);

	sprintf(buf, "mmode");
	REG_WriteBool(buf, tomb5.mirrorMode);

	CloseRegistry();
}

const char* RPC_GetLevelName()
{
	if (gfCurrentLevel == LVL5_TITLE)
	{
		if (bDoCredits)
			return "In Credits";
		else
			return "In Title";
	}
	else
		return SCRIPT_TEXT(gfLevelNames[gfCurrentLevel]);
}

const char* RPC_GetTimer()
{
	long sec, days, hours, min;
	static char buf[64];

	sec = GameTimer / 30;
	days = sec / 86400;
	hours = (sec % 86400) / 3600;
	min = (sec / 60) % 60;
	sec = (sec % 60);
	sprintf(buf, "Time Taken: %02d:%02d:%02d", (days * 24) + hours, min, sec);
	return buf;
}

const char* RPC_GetLevelPic()
{
	switch (gfCurrentLevel)
	{
	case LVL5_STREETS_OF_ROME:
		return "rome";

	case LVL5_TRAJAN_MARKETS:
		return "streets";

	case LVL5_COLOSSEUM:
		return "colosseum";

	case LVL5_BASE:
		return "base";

	case LVL5_SUBMARINE:
		return "submarine";

	case LVL5_DEEPSEA_DIVE:
		return "deepsea";

	case LVL5_SINKING_SUBMARINE:
		return "sink";

	case LVL5_GALLOWS_TREE:
		return "gallow1";

	case LVL5_LABYRINTH:
		return "laby";

	case LVL5_OLD_MILL:
		return "mill";

	case LVL5_THIRTEENTH_FLOOR:
		return "13th";

	case LVL5_ESCAPE_WITH_THE_IRIS:
		return "iris";

	case LVL5_SECURITY_BREACH:
		return "breach";

	case LVL5_RED_ALERT:
		return "alert";

	default:
		return "default";
	}
	
}

const char* RPC_GetHealthPic()
{
	if (lara_item->hit_points > 666)
		return "green";

	if (lara_item->hit_points > 333)
		return "yellow";

	return "red";
}

const char* RPC_GetHealthPercentage()
{
	static char buf[32];

	sprintf(buf, "Health: %i%%", lara_item->hit_points / 10);
	return buf;
}
