#pragma once

#include "olcPixelGameEngine.h"
#include <map>

class cMap;
class cItem;

class RPG_Assets
{
public:
	static RPG_Assets& get()
	{
		static RPG_Assets me;
		return me;
	}

	RPG_Assets(RPG_Assets const&) = delete;
	void operator=(RPG_Assets const&) = delete;

	olc::Sprite* GetSprite(std::string name)
	{
		return m_mapSprites[name];
	}

	cMap* GetMap(std::string name)
	{
		return m_mapMaps[name];
	}
	cItem* GetItem(std::string name)
	{
		return m_mapItems[name];
	}



	void LoadSprites();
	void LoadMaps();
	void LoadItems();



private:
	RPG_Assets();
	~RPG_Assets();

	map<std::string, olc::Sprite*> m_mapSprites;
	map<std::string, cMap*> m_mapMaps;
	map<std::string, cItem*> m_mapItems;

};

