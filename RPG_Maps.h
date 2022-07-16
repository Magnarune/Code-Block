#pragma once

#include "olcPixelGameEngine.h"
#include "RPG_Assets.h"
#include "RPG_Dynamics.h"
#include "RPG_Commands.h"
#define X(n) m_script.AddCommand(new cCommand_ ## n)

class cMap
{

public:
	enum NATURE
	{
		TALK,
		WALK
	};
public:
	cMap();
	~cMap();
public:
	int nWidth;
	int nHeight;
	std::string sName;
	olc::Sprite* pSprite;

	int GetIndex(int x, int y);
	bool GetSolid(int x, int y);
	bool Create(std::string fileData, olc::Sprite* sprite, std::string name);

	virtual bool PopulateDynamics(vector<cDynamic*>& vecDyns)
	{
		return false;
	}
	virtual bool OnInteraction(vector<cDynamic*>& vecDynobs, cDynamic* target, NATURE nature)
	{
		return false;
	}

private:
	int* m_indices = nullptr;
	bool* m_solids = nullptr;
public:
	static cScriptProcessor* g_script;
};

class cMap_Village1 : public cMap
{
public:
	cMap_Village1();
	bool PopulateDynamics(vector<cDynamic*>& vecDyns) override;
	bool OnInteraction(vector<cDynamic*>& vecDynobs, cDynamic* target, NATURE nature) override;
};






class cMap_Home1 : public cMap
{
public:
	cMap_Home1();
	bool PopulateDynamics(vector<cDynamic*>& vecDyns) override;
	bool OnInteraction(vector<cDynamic*>& vecDynobs, cDynamic* target, NATURE nature) override;

};

