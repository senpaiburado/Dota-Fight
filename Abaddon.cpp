#include "Abaddon.h"

void Abaddon::getDamage(int pow)
{
	if (!this->isActiveBorrowedTime)
	{
		if (!this->isActiveAphoticShield)
			this->hp -= pow;
		else
		{
			if (pow > this->aphoticShieldDamageCanGet - (this->aphoticShieldDamageCounter + pow))
			{
				this->aphoticShieldDamageCounter += pow;
				this->hp -= pow - (this->aphoticShieldDamageCanGet - this->aphoticShieldDamageCounter);
			}
			else
			{
				this->aphoticShieldDamageCounter += pow;
			}
		}
	}
	else
	{
		this->heal(pow);
	}
}

void Abaddon::drawMenu()
{
	cout << "1 - Attack" << endl;
	if (this->mistCoilCd > 0)
		cout << "2 - Mist Coil (" << this->mistCoilCd << ")[" << this->mistCoilManacost << "]" << endl;
	else
		cout << "2 - Mist Coil [" << this->mistCoilManacost << "]" << endl;

	if (this->aphoticShieldCd > 0)
	{
		if (this->isActiveAphoticShield)
			cout << "3 - Aphotic Shield (" << this->aphoticShieldCd << ")[" << this->aphoticShieldManacost << "]"
				<< "<<<" << this->aphoticShieldDuration - this->aphoticShieldCounter << ">>>" << endl;
		else
			cout << "3 - Aphotic Shield (" << this->aphoticShieldCd << ")[" << this->aphoticShieldManacost << "]" << endl;
	}
	else
	{
		if (!this->isActiveAphoticShield)
			cout << "3 - Aphotic Shield [" << this->aphoticShieldManacost << "]" << endl;
		else
			cout << "3 - Aphotic Shield " << "<<<" << this->aphoticShieldDuration - this->aphoticShieldCounter << ">>>" << endl;
	}

	if (this->borrowedTimeCd > 0)
	{
		if (this->isActiveBorrowedTime)
			cout << "4 - Borrowed Time (" << this->borrowedTimeCd << ")"
				<< "<<<" << this->borrowedTimeDuration - this->borrowedTimeCounter << ">>>" << endl;
		else
			cout << "4 - Borrowed Time (" << this->borrowedTimeCd << ")" << endl;
	}
	else
	{
		if (!this->isActiveBorrowedTime)
			cout << "4 - Borrowed Time" << endl;
		else
			cout << "4 - Borrowed Time " << "<<<" << this->borrowedTimeDuration - this->borrowedTimeCounter << ">>>" << endl;
	}
	if (this->refreshSkillCd > 0)
		cout << "5 - Fortification (" << this->refreshSkillCd << ")" << endl;
	else
		cout << "5 - Fortification" << endl;
}

void Abaddon::skillSelectionMenu(Hero *hero)
{
	if (native)
	{
		bool ___try____ = true;
		while (___try____)
		{
			this->printThisAndEnemy(this, hero);
			cout << endl;
			this->drawMenu();
			char selection;

			if (this->HP() <= this->borrowedTimeMinHPToActivation && this->borrowedTimeCd == 0 && !this->isActiveBorrowedTime)
				selection = '4';
			else
			{
				cout << "Select ability: ";
				cin >> selection;
				cin.get();
			}
			cout << endl;
			switch (selection)
			{
			case '1':
				this->attack(hero);
				___try____ = false;
				break;
			case '2':
				if (!this->isSilenced())
				{
					if (this->mistCoilCd > 0)
					{
						cout << "You can't use this ability now! Countdown is " << this->mistCoilCd << "." << endl;
						_getch();
						system("cls");
					}
					else
					{
						if (this->MP() >= this->mistCoilManacost)
						{
							this->mistCoil(hero);
							___try____ = false;
						}
						else
						{
							cout << "You need more mana! (" << this->MP() - this->mistCoilManacost << ")" << endl;
							_getch();
							system("cls");
						}
					}
				}
				else
				{
					cout << "You are silenced!" << endl;
					_getch();
					system("cls");
				}
				break;
			case '3':
				if (!this->isSilenced())
				{
					if (this->aphoticShieldCd > 0)
					{
						cout << "You can't use this ability now! Countdown is " << this->aphoticShieldCd << "." << endl;
						_getch();
						system("cls");
					}
					else
					{
						if (this->MP() >= this->aphoticShieldManacost)
						{
							this->aphoticShield();
							___try____ = false;
						}
						else
						{
							cout << "You need more mana! (" << this->MP() - this->aphoticShieldManacost << ")" << endl;
							_getch();
							system("cls");
						}
					}
				}
				else
				{
					cout << "You are silenced!" << endl;
					_getch();
					system("cls");
				}
				break;
			case '4':
				if (!this->isSilenced())
				{
					if (this->isActiveBorrowedTime)
					{
						cout << "You have already used this ability!" << endl;
						_getch();
						system("cls");
						break;
					}
					if (this->borrowedTimeCd > 0)
					{
						cout << "You can't use this ability now! Countdown is " << this->borrowedTimeCd << "." << endl;
						_getch();
						system("cls");
					}
					else
					{
						if (this->MP() >= this->borrowedTimeManacost)
						{
							this->borrowedTime();
							___try____ = false;
						}
						else
						{
							cout << "You need more mana! (" << this->MP() - this->borrowedTimeManacost << ")" << endl;
							_getch();
							system("cls");
						}
					}
				}
				else
				{
					cout << "You are silenced!" << endl;
					_getch();
					system("cls");
				}
				break;
				if (!this->isSilenced())
				{
					if (this->refreshSkillCd > 0)
					{
						cout << "You can't use this ability now! Countdown is " << this->refreshSkillCd << "." << endl;
						_getch();
						system("cls");
					}
					else
					{
						this->refreshSkill();
						___try____ = false;
					}
				}
				else
				{
					cout << "You are silenced!" << endl;
					_getch();
					system("csl");
				}
				break;
			case '5':
				if (!this->isSilenced())
				{
					if (this->refreshSkillCd > 0)
					{
						cout << "You can't use this ability now! Countdown is " << this->refreshSkillCd << "." << endl;
						_getch();
						system("cls");
					}
					else
					{
						this->refreshSkill();
						___try____ = false;
					}
				}
				else
				{
					cout << "You are silenced!" << endl;
					_getch();
					system("csl");
				}
				break;
			default:
				system("cls");
				break;
			}
		}
	}
	else
	{
		bool __try__ = true;
		this->printThisAndEnemy(hero, this);
		cout << endl << endl;
		while (__try__)
		{
			int skill;
			skill = rand() % 5 + 1;

			if (this->HP() <= this->borrowedTimeMinHPToActivation && this->borrowedTimeCd == 0 && !this->isActiveBorrowedTime)
				skill = 4;

			switch (skill)
			{
			case 1:
				this->attack(hero);
				__try__ = false;
				break;
			case 2:
				if (!this->isSilenced() && this->mistCoilCd == 0 && this->MP() >= this->mistCoilManacost)
				{
					this->mistCoil(hero);
					__try__ = false;
				}
				break;
			case 3:
				if (!this->isSilenced() && this->aphoticShieldCd == 0 && this->MP() > this->aphoticShieldManacost)
				{
					this->aphoticShield();
					__try__ = false;
				}
				break;
			case 4:
				if (!this->isSilenced() && !this->isActiveBorrowedTime && this->HP() <= this->getMaxHP() / 100 * 70
					&& this->MP() >= this->borrowedTimeManacost && this->borrowedTimeCd == 0)
				{
					this->borrowedTime();
					__try__ = false;
				}
				break;
			case 5:
				if ((this->HP() < (int)(this->getMaxHP() / 100 * 90)) && (this->MP() <
					(int)((this->getMaxMP() / 100 * 90)))
					&& (this->refreshSkillCd == 0) && (!this->isSilenced()))
				{
					this->refreshSkill();
					__try__ = false;
				}
				break;
			}
		}
	}
}

void Abaddon::updateCountdowns()
{
	if (this->mistCoilCd > 0)
		this->mistCoilCd--;
	if (this->aphoticShieldCd > 0)
		this->aphoticShieldCd--;
	if (this->borrowedTimeCd > 0)
		this->borrowedTimeCd--;
}

void Abaddon::refreshCds()
{
	this->mistCoilCd = 0;
	this->aphoticShieldCd = 0;
	this->borrowedTimeCd = 0;
}

void Abaddon::updateOwnChars()
{
	this->updateAphoticShield();
	this->updateCurseOfAvernus();
	this->updateBorrowedTime();
}

void Abaddon::mistCoil(Hero *hero)
{
	this->getDamage(this->mistCoilDamageToYourself);
	hero->getDamage(this->mistCoilDamageToEnemy);

	this->payMana(this->mistCoilManacost);
	this->mistCoilCd = this->mistCoilCdDefault;

	if (native)
		cout << "You have used Mist Coil to enemy!" << endl;
	else
		cout << this->Name() << " has used Mist Coil to you!" << endl;
}

void Abaddon::aphoticShield()
{
	this->isActiveAphoticShield = true;
	this->aphoticShieldCd = this->aphoticShieldCdDefault;
	this->payMana(this->aphoticShieldManacost);

	if (native)
		cout << "You have used Aphotic Shield!" << endl;
	else
		cout << this->Name() << " has used Aphotic Shield" << endl;
}

void Abaddon::updateAphoticShield()
{
	if (this->aphoticShieldCounter < this->aphoticShieldDuration && this->isActiveAphoticShield && 
		this->aphoticShieldDamageCounter <= this->aphoticShieldDamageCanGet)
			this->aphoticShieldCounter++;
	else
	{
		if (this->isActiveAphoticShield)
		{
			this->isActiveAphoticShield = false;
			this->aphoticShieldCounter = 0;
			this->heal(this->aphoticShieldDamage);
		}
	}
}

void Abaddon::updateCurseOfAvernus()
{
	if (this->curseOfAvernusCounter < this->curseOfAvernusMaxPoint)
		this->curseOfAvernusCounter++;
	else
		this->isActiveCurseOfAvernus = true;

	if (this->isActiveCurseOfAvernus)
	{
		this->isActiveCurseOfAvernus = false;
		this->curseOfAvernusCounter = 0;
		this->improveDPS(this->curseOfAvernusAddDamage);
	}
}

void Abaddon::borrowedTime()
{
	this->isActiveBorrowedTime = true;
	this->borrowedTimeCd = this->borrowedTimeCdDefault;
	this->payMana(this->borrowedTimeManacost);

	if (native)
		cout << "You have used Borrowed Time!" << endl;
	else
		cout << this->Name() << " has used Borrowed Time!" << endl;
}

void Abaddon::updateBorrowedTime()
{
	if (this->borrowedTimeCounter < this->borrowedTimeDuration && this->isActiveBorrowedTime)
		this->borrowedTimeCounter++;
	else
	{
		if (this->isActiveBorrowedTime)
		{
			this->isActiveBorrowedTime = false;
			this->borrowedTimeCounter = 0;
		}
	}
}