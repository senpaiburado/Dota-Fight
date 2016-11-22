#include <iostream>
#include "account.h"
#include <conio.h>
#include "Game.h"


using namespace std;

int main()
{
	long gameVersion = 0.1l;
	string gameType = "Alpha";

	Account * acc = new Account();
	acc->start();
	acc->endInit();
	Game * game = new Game(acc);

	vector<Hero*> heroes;
	heroes.push_back(new Alchemist("D:\\Dota Fight\\Heroes\\Alchemist.ini", 1));
	heroes.push_back(new Lifestealer("D:\\Dota Fight\\Heroes\\Lifestealer.ini", 2));
	heroes.push_back(new FacelessVoid("D:\\Dota Fight\\Heroes\\Faceless Void.ini", 3));
	heroes.push_back(new Juggernaut("D:\\Dota Fight\\Heroes\\Juggernaut.ini", 4));
	heroes.push_back(new Abaddon("D:\\Dota Fight\\Heroes\\Abaddon.ini", 5));

	acc->fillAccHeroes(heroes);

	game->getHeroList(acc->getHeroes());
	game->getAllHeroList(heroes);
	game->start();

	return 0;
}
