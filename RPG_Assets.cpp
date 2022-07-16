#include "RPG_Assets.h"
#include "RPG_Maps.h"
#include "RPG_Items.h"


RPG_Assets::RPG_Assets()
{
}


RPG_Assets::~RPG_Assets()
{
}

void RPG_Assets::LoadSprites()
{
	auto load = [&](std::string sName, std::string sFileName)
	{
		olc::Sprite* s = new olc::Sprite(sFileName);
		m_mapSprites[sName] = s;
	};

	load("village", "rpgdata/gfx/toml_spritesheetdark.spr");

	load("skelly", "rpgdata/gfx/toml_Char001.png.spr");
	load("player", "rpgdata/gfx/toml_CharacterSprites.spr");
	load("font", "rpgdata/gfx/javidx9_nesfont8x8.spr");
	load("worldmap", "rpgdata/gfx/worldmap1.png.spr");
	load("skymap", "rpgdata/gfx/sky1.png.spr");
	load("title", "rpgdata/gfx/title3.png.spr");
	load("balloon", "rpgdata/gfx/balloon1.png.spr");
	load("sword", "rpgdata/gfx/Sword.spr");
	load("hitech", "rpgdata/gfx/toml_modernish.spr");

	load("purple", "rpgdata/gfx/toml_purple.spr");

	load("health", "rpgdata/gfx/item_health.spr");
	load("healthboost", "rpgdata/gfx/item_healthboost.spr");

	load("Basic Sword", "rpgdata/gfx/weapon_basic_sword.spr");
}

void RPG_Assets::LoadMaps()
{
	auto load = [&](cMap* m)
	{
		m_mapMaps[m->sName] = m;
	};

	load(new cMap_Village1());
	load(new cMap_Home1());

}
void RPG_Assets::LoadItems()
{
	auto load = [&](cItem* i)
	{
		m_mapItems[i->sName] = i;
	};

	load(new cItem_Health());
	load(new cItem_HealthBoost());
	load(new cWeapon_Sword());
}