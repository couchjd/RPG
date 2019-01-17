#pragma once
#include "Skill.h"
#include <vector>
#include "Languages.h"
#include "Tools.h"

enum BackgroundEnum {
	ACOLYTE,
	CHARLATAN,
	CITY_WATCH,
	CLAN_CRAFTER,
	CLOISTERED_SCHOLAR,
	COURTIER,
	CRIMINAL,
	FACTION_AGENT,
	FAR_TRAVELER,
	FOLK_HERO,
	GLADIATOR,
	GUILD_ARTISAN,
	GUILD_MERCHANT,
	HERMIT,
	INHERITOR,
	INVESTIGATOR,
	KNIGHT,
	KNIGHT_OF_THE_ORDER,
	MERCENARY_VETERAN,
	NOBLE,
	OUTLANDER,
	PIRATE,
	SAGE,
	SAILOR,
	SOLDIER,
	SPY,
	URBAN_BOUNTY_HUNTER,
	URCHIN,
	UTHGARDT_TRIBE_MEMBER,
	WATERDHAVIAN_NOBLE
};

class Background {
public:
	std::vector<Skills> skills;
	std::vector<Languages> languages;
	//std::vector<Tools> tools;
	Background(BackgroundEnum bg);
	~Background();

private:
};