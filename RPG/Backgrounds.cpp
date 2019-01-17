#include "Backgrounds.h"

Background::Background(BackgroundEnum bg) {
	switch(bg) {
		case ACOLYTE:
			skills = {INSIGHT, RELIGION};
			break;
		case CHARLATAN:
			skills = {DECEPTION, SLEIGHT_OF_HAND};
			break;
		case CITY_WATCH:
			skills = {ATHLETICS, INSIGHT};
			break;
		case CLAN_CRAFTER:
			skills = {HISTORY, INSIGHT};
			break;
		case CLOISTERED_SCHOLAR:
			skills = {HISTORY}; //CHOOSE ONE MORE FROM: ARCANA, NATURE, RELIGION
			break;
		case COURTIER:
			skills = {INSIGHT, PERSUASION};
			break;
		case CRIMINAL:
			skills = {DECEPTION, STEALTH};
			break;
		case FACTION_AGENT:
			skills = {INSIGHT}; //CHOOSE ONE: INT, WIS, OR CHA SKILL
			break;
		case FAR_TRAVELER:
			skills = {INSIGHT, PERCEPTION};
			break;
		case FOLK_HERO:
			skills = {ANIMAL_HANDLING, SURVIVAL};
			break;
		case GLADIATOR:
			skills = {ACROBATICS, PERFORMANCE};
			break;
		case GUILD_ARTISAN:
			skills = {INSIGHT, PERCEPTION};
			break;
		case GUILD_MERCHANT:
			skills = {INSIGHT, PERSUASION};
			break;
		case HERMIT:
			skills = {MEDICINE, RELIGION};
			break;
		case INHERITOR:
			skills = {SURVIVAL}; //CHOOSE ONE OF: ARCANA, HISTORY, RELIGION
			break;
		case INVESTIGATOR:
			skills = {INSIGHT, INVESTIGATION};
			break;
		case KNIGHT:
			skills = {HISTORY, PERSUASION};
			break;
		case KNIGHT_OF_THE_ORDER:
			skills = {PERSUASION}; //CHOOSE ONE OF: ARCANA, HISTORY, NATURE, RELIGION
			break;
		case MERCENARY_VETERAN:
			skills = {ATHLETICS, PERSUASION};
			break;
		case NOBLE:
			skills = {HISTORY, PERSUASION};
			break;
		case OUTLANDER:
			skills = {ATHLETICS, SURVIVAL};
			break;
		case PIRATE:
			skills = {ATHLETICS, PERCEPTION};
			break;
		case SAGE:
			skills = {ARCANA, HISTORY};
			break;
		case SAILOR:
			skills = {ATHLETICS, PERCEPTION};
			break;
		case SOLDIER:
			skills = {ATHLETICS, INTIMIDATION};
			break;
		case SPY:
			skills = {DECEPTION, STEALTH};
			break;
		case URBAN_BOUNTY_HUNTER:
			skills = {}; //CHOOSE 2: DECEPTION, INSIGHT, PERSUASION, STEALTH
			break;
		case URCHIN:
			skills = {SLEIGHT_OF_HAND, STEALTH};
			break;
		case UTHGARDT_TRIBE_MEMBER:
			skills = {ATHLETICS, SURVIVAL};
			break;
		case WATERDHAVIAN_NOBLE:
			skills = {HISTORY, PERSUASION};
			break;
	}
}

Background::~Background() {
}
