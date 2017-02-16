// RandomEnemyGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>

enum class EnemyType {zombie, vampire, ghost, witch};
struct Enemy {
	EnemyType type;
	std::string name;
	int health;
};

Enemy CreateRandomEnemy() {
	srand(time(NULL)); //Altera la seed
	Enemy evil;
	evil.type = EnemyType(rand() % 4);
	evil.health = (rand() % 501) + 100;
	switch (rand() % 8)
	{
	case 0:
		evil.name = "Hipolito";
		break;
	case 1:
		evil.name = "Fulgencia";
		break;
	case 2:
		evil.name = "Pancracia";
		break;
	case 3:
		evil.name = "Eustaquio";
		break;
	case 4:
		evil.name = "Pocahonto";
		break;
	case 5:
		evil.name = "Ambrosio";
		break;
	case 6:
		evil.name = "Radev";
		break;
	case 7:
		evil.name = "Willy";
		break;
	default:
		break;
	}
}

bool Operador(Enemy evil1, Enemy evil2) {
	if (evil1)
}

int main()
{

    return 0;
}

