#include "RPG_Quests.h"
#include "RPG_Engine.h"

cScriptProcessor* cQuest::g_script = nullptr;
RPG_Engine* cQuest::g_engine = nullptr;

#define X(n) g_script->AddCommand(new cCommand_ ## n)

cQuest::cQuest()
{
}

bool cQuest::PopulateDynamics(vector<cDynamic*>& vecDyns, std::string sMap)
{
	return true;
}

bool cQuest::OnInteraction(vector<cDynamic*>& vecDynobs, cDynamic* target, NATURE nature)
{
	return true;
}





bool cQuest_MainQuest::PopulateDynamics(vector<cDynamic*>& vecDyns, std::string sMap)
{
	if (sMap == "coder town")
	{
		cDynamic_Creature* c1 = new cDynamic_Creature("sarah", RPG_Assets::get().GetSprite("purple"));
		c1->px = 6.0f;
		c1->py = 4.0f;
		c1->bFriendly = true;
		vecDyns.push_back(c1);
	}

	if (sMap == "home")
	{
		cDynamic_Creature* c1 = new cDynamic_Creature("bob", RPG_Assets::get().GetSprite("skelly"));
		c1->px = 12.0f;
		c1->py = 4.0f;
		vecDyns.push_back(c1);
	}


	return true;
}

bool cQuest_MainQuest::OnInteraction(vector<cDynamic*>& vecDynobs, cDynamic* target, NATURE nature)
{
	if (target->sName == "sarah")
	{
		//X(ShowDialog({ "[Sarah]", "You have no additional quests" }));
		if (g_engine->HasItem(RPG_Assets::get().GetItem("Health Boost")))
		{
			X(ShowDialog({ "[Sarah]", "Nice Health Boost" }));
		}
		else
		{
			X(ShowDialog({ "[Sarah]", "You need a Boost" }));
		}

	}



	if (target->sName == "bob")
	{
		X(ShowDialog({ "[Bob]", "I need you to do", "something for me" }));
		X(ShowDialog({ "[Bob]", "Predictably, there are", "rats in my basement!" }));
		X(AddQuest(new cQuest_BobsQuest()));
	}

	return false;

}
bool cQuest_BobsQuest::PopulateDynamics(vector<cDynamic*>& vecDyns, std::string sMap)
{
	return true;
}
bool cQuest_BobsQuest::OnInteraction(vector<cDynamic*>& vecDynobs, cDynamic* target, NATURE nature)
{
	if (target->sName == "sarah")
	{
		X(ShowDialog({ "[Sarah]", "You are doing Bob's", "quest!" }));
		return true;
	}

	return false;
}
