// RandomEnemyGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>

enum class EnemyType {ZOMBIE, VAMPIRE, GHOST, WITCH, MAX};

struct Enemy {
	EnemyType type;
	std::string name;
	int health;

	std::string getEnemyTypeString() {
		switch (type) {
		case EnemyType::ZOMBIE:
			return "zombie";
		case EnemyType::VAMPIRE:
			return "vampire";
		case EnemyType::GHOST:
			return "ghost";
		case EnemyType::WITCH:
			return "witch";
		default:
			return "";
		}
	}
};

bool operator==(const Enemy &a, const Enemy &b) { //Operator == overloaded
	return a.name == b.name && a.type == b.type;
}

static Enemy CreateRandomEnemy() {
	srand(time(NULL)); //Altera la seed
	static const int MAX_LIFE{ 500 }; //Vida maxima de un enemigo
	static const std::string NAMES[]{ "Gertrudis", "Pancracia", "Anacleto", "Hipolito", "Eustaquio", "Fulgencia", "Radev", "Willy", "Pocahonto", "Ambrosio", "Margarita", "Lesinga", "Tito Shen", "Poppy Pintame" }; //Lista de posibles nombres de enemigos
	return Enemy{ //Devuelve un enemigo con atributos aleatorios. {} nos permite construir la variable en su declaración, y sus componentes deben estar ordenados según la declaración del struct
		static_cast<EnemyType>(rand() % static_cast<int>(EnemyType::MAX)),
		NAMES[rand() % (sizeof NAMES / sizeof std::string)],
		rand() % MAX_LIFE
	};
}

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));
	const int MAX_ENEMIES{ 5 };
	Enemy enemies[MAX_ENEMIES];
	int i{ 0 };
	while (i < MAX_ENEMIES) {
		enemies[i] = CreateRandomEnemy();
		int j{ i - 1 };
		while (j >= 0) {
			if (enemies[i] == enemies[j])
			{
				--i;
				break;
			}
			j--;
		}
		++i;
	}

	//Print the array of enemies
	std::cout << "List of enemies:\n";
	for (auto &enemy : enemies) {
		std::cout << enemy.name << " is a " << enemy.getEnemyTypeString() << " whose life is " << enemy.health << std::endl;
	}
    return 0;
}

