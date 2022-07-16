#include "RPG_Maps.h"
#include <fstream>

cScriptProcessor* cMap::g_script = nullptr;
#define X(n) g_script->AddCommand(new cCommand_ ## n)

cMap::cMap()
{
	pSprite = nullptr;
	nWidth = 0;
	nHeight = 0;
	m_solids = nullptr;
	m_indices = nullptr;
}


cMap::~cMap()
{
	delete[] m_solids;
	delete[] m_indices;
}

int cMap::GetIndex(int x, int y)
{
	if (x >= 0 && x < nWidth && y >= 0 && y < nHeight)
		return m_indices[y * nWidth + x];
	else
		return 0;
}

bool cMap::GetSolid(int x, int y)
{
	if (x >= 0 && x < nWidth && y >= 0 && y < nHeight)
		return m_solids[y * nWidth + x];
	else
		return true;
}

bool cMap::Create(std::string fileData, olc::Sprite* sprite, std::string name)
{
	sName = name;
	pSprite = sprite;
	ifstream data(fileData, ios::in | ios::binary);
	if (data.is_open())
	{
		data >> nWidth >> nHeight;
		m_solids = new bool[nWidth * nHeight];
		m_indices = new int[nWidth * nHeight];
		for (int i = 0; i < nWidth * nHeight; i++)
		{
			data >> m_indices[i];
			data >> m_solids[i];
		}
		return true;
	}

	return false;
}








cMap_Village1::cMap_Village1()
{
	Create("rpgdata/map/village1.lvl", RPG_Assets::get().GetSprite("village"), "coder town");
}

bool cMap_Village1::PopulateDynamics(vector<cDynamic*>& vecDyns)
{
	vecDyns.push_back(new cDynamic_Teleport(12.0f, 6.0f, "home", 5.0f, 12.0f));

	vecDyns.push_back(new cDynamic_Item(10, 10, RPG_Assets::get().GetItem("Small Health")));
	vecDyns.push_back(new cDynamic_Item(12, 10, RPG_Assets::get().GetItem("Health Boost")));


	for (int i = 0; i < 3; i++)
	{
		cDynamic* g1 = new cDynamic_Creature_Skelly();
		vecDyns.push_back(g1);
		g1->px = rand() % 10 + 5.0f;
		g1->py = rand() % 10 + 5.0f;
	}


	return true;
}
bool cMap_Village1::OnInteraction(vector<cDynamic*>& vecDynobs, cDynamic* target, NATURE nature)
{
	if (target->sName == "Teleport")
		g_script->AddCommand(new cCommand_ChangeMap(
			((cDynamic_Teleport*)target)->sMapName,
			((cDynamic_Teleport*)target)->fMapPosX,
			((cDynamic_Teleport*)target)->fMapPosY));
	return false;
}






cMap_Home1::cMap_Home1()
{
	Create("rpgdata/map/home.lvl", RPG_Assets::get().GetSprite("hitech"), "home");
}
bool cMap_Home1::PopulateDynamics(vector<cDynamic*>& vecDyns)
{
	vecDyns.push_back(new cDynamic_Teleport(5.0f, 13.0f, "coder town", 12.0f, 7.0f));
	vecDyns.push_back(new cDynamic_Teleport(4.0f, 13.0f, "coder town", 12.0f, 7.0f));

	/*cDynamic_Creature* c1 = new cDynamic_Creature("bob", RPG_Assets::get().GetSprite("skelly"));
		c1->px = 12.0f;
		c1->py = 4.0f;
		vecDyns.push_back(c1);*/

	return true;
}
bool cMap_Home1::OnInteraction(vector<cDynamic*>& vecDynobs, cDynamic* target, NATURE nature)
{
	if (target->sName == "Teleport")
		g_script->AddCommand(new cCommand_ChangeMap(
			((cDynamic_Teleport*)target)->sMapName,
			((cDynamic_Teleport*)target)->fMapPosX,
			((cDynamic_Teleport*)target)->fMapPosY));


	//	if (target->sName == "bob")
	//	{
	//		X(ShowDialog({ "Hello!", "I'm Bob!" }));
	//	}

	return false;
}

