#include <iostream>
#include <string>
#include <ctime>

enum class Weapon {
	FISTS,
	GUN,
	SHOTGUN,
	REVOLVER,
	SNIPER,
	MACHINE_GUN,
	MAX
};

std::ostream& operator<< (std::ostream &os, const Weapon &weapon) {
	switch (weapon) {
	case Weapon::GUN:
		return os << "gun";
	case Weapon::SHOTGUN:
		return os << "shotgun";
	case Weapon::REVOLVER:
		return os << "revolver";
	case Weapon::SNIPER:
		return os << "sniper";
	case Weapon::MACHINE_GUN:
		return os << "machine gun";
	default:
		return os << "fists";
	}
}

class Zombie;

class Player {
public:
	Weapon weapon;
	float precision;
	int life;
	
	Player(): weapon{ static_cast <Weapon>(rand() % static_cast <int> (Weapon::MAX))}, precision{ (rand() % 10) / 10.f }, life{ 100 } {
	};
	Player(Weapon t_weapon, float t_precision, int t_life) : weapon{t_weapon}, precision{t_precision}, life{t_life} {
	};

	void attack(Zombie &);
	bool isAlive() {
		return life > 0;
	}
};

class Zombie {
public:
	int distanceToPlayer;
	float speed;
	float damage;
	int life;

	Zombie() : distanceToPlayer{ (rand() % 181) + 20 }, speed{ (rand() % 200) / 10.f }, damage{ (rand() % 200) / 10.f }, life { 100 } { //.f = float, .u = unsigned
	};
	Zombie(int t_distanceToPlayer, float t_speed, float t_damage, int t_life) : distanceToPlayer{ t_distanceToPlayer }, speed{ t_speed }, damage{ t_damage }, life{ t_life } {
	};

	void attack(Player &p) {
		if (distanceToPlayer <= 0) {
			p.life -= damage;
		}
		else {
			distanceToPlayer--;
		}
	};
	bool isAlive() {
		return life > 0;
	}
};

void Player::attack(Zombie &z) {
	z.life -= static_cast <int>(weapon) * precision;
}

int main() {
	srand(static_cast <unsigned>(time(nullptr)));
	Player player;
	const int zombieNum = 10;
	Zombie zombies[zombieNum];
	bool zombiesAreAlive;
	do
	{
		zombiesAreAlive = false;
		std::cout << "Player\n	life: " << player.life << ", weapon" << player.weapon << ", precision: " << player.precision << "\n";
		for (int i = 0; i < zombieNum; i++) {
			if (zombies[i].isAlive()) {
				player.attack(zombies[i]);
				std::cout << "Zombie[" << i << "]\n	life: " << zombies[i].life << ", distance: " << zombies[i].distanceToPlayer << ", speed: " << zombies[i].speed << ", damage:" << zombies[i].damage << "\n";
				if (zombies[i].isAlive()) {
					zombies[i].attack(player);
					zombiesAreAlive = true;
				}
			}
		}
		std::cout << "------------------------------------------------------------\n";
	} while (player.isAlive() && zombiesAreAlive);
	if (zombiesAreAlive) {
		std::cout << "GAME OVER: Zombies ate the player's brain!";
	}
	else {
		std::cout << "GAME OVER: Player killed all the zombies!";
	}
	return 0;
}