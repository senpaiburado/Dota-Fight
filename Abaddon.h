#ifndef ABADDON_H
#define ABADDON_H

#include "Hero.h"

class Abaddon : public Hero
{
public:
	Abaddon(string path, int id) : Hero(path, id)
	{
		this->mistCoilCd = 0;
		this->mistCoilCdDefault = 7;
		this->mistCoilDamageToEnemy = 180;
		this->mistCoilDamageToYourself = 85;
		this->mistCoilManacost = 60;

		this->aphoticShieldCd = 0;
		this->aphoticShieldCdDefault = 30;
		this->aphoticShieldDamage = 250;
		this->aphoticShieldDamageCanGet = 230;
		this->aphoticShieldDuration = 15;
		this->aphoticShieldCounter = 0;
		this->aphoticShieldDamageCounter = 0;
		this->aphoticShieldManacost = 110;
		this->isActiveAphoticShield = false;

		this->curseOfAvernusAddDamage = 20;
		this->curseOfAvernusMaxPoint = 5;
		this->curseOfAvernusCounter = 0;
		this->isActiveCurseOfAvernus = false;

		this->borrowedTimeCd = 0;
		this->borrowedTimeCdDefault = 65;
		this->borrowedTimeDuration = 7;
		this->borrowedTimeCounter = 0;
		this->borrowedTimeManacost = 0;
		this->borrowedTimeMinHPToActivation = 400;
		this->isActiveBorrowedTime = false;

		this->enemy_pointer = nullptr;
	}

	void drawMenu() override;
	void skillSelectionMenu(Hero *hero) override;
	void refreshCds() override;
	void getDamage(int pow) override;
	void updateOwnChars() override;
	void updateCountdowns() override;

	void mistCoil(Hero *hero);

	void aphoticShield();
	void updateAphoticShield();

	void updateCurseOfAvernus();

	void borrowedTime();
	void updateBorrowedTime();

private:
	// active
	int mistCoilCd;
	int mistCoilCdDefault;
	int mistCoilDamageToEnemy;
	int mistCoilDamageToYourself;
	int mistCoilManacost;

	// active
	int aphoticShieldCd;
	int aphoticShieldCdDefault;
	int aphoticShieldDamage;
	int aphoticShieldDamageCanGet;
	int aphoticShieldDuration;
	int aphoticShieldCounter;
	int aphoticShieldDamageCounter;
	int aphoticShieldManacost;
	bool isActiveAphoticShield;

	// passive
	int curseOfAvernusAddDamage;
	int curseOfAvernusCounter;
	int curseOfAvernusMaxPoint;
	bool isActiveCurseOfAvernus;

	// active
	int borrowedTimeCd;
	int borrowedTimeCdDefault;
	int borrowedTimeDuration;
	int borrowedTimeCounter;
	int borrowedTimeManacost;
	int borrowedTimeMinHPToActivation;
	bool isActiveBorrowedTime;

	// other
	Hero *enemy_pointer;
};

#endif // ABADDON_H
