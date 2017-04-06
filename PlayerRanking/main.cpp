#include <iostream>
#include <string>
#include <vector>
#include <map>

void RankingMap() {

	std::map<std::string, int> ranking;


}

void RankingVector() {

	struct Player {
		std::string name;
		int score;
	};

	std::vector<Player> ranking (4);
	ranking[0] = { "Ayy Lmao", 420 };
	ranking[1] = { "Roast Lord", 10002 };
	ranking[2] = { "Gladio", 3267 };
	ranking[3] = { "IDubbbz", 2 };

	std::string playerName;
	int playerScore;
	bool newName = true;

	std::cout << "Enter your name" << std::endl;
	std::cin >> playerName;
	std::cout << "Enter your score" << std::endl;
	std::cin >> playerScore;

	for (int i = 0; i < ranking.size(); ++i) {
		if (ranking[i].name == playerName) {
			ranking[i].score = playerScore;
			newName = false;
		}
		std::cout << "Name: " << ranking[i].name << " Highest Score: " << ranking[i].score; //NO LOS ESTA ORDENANDO POR PUNTUACION
	}

	if (newName) {
		Player newPlayer{ playerName, playerScore };
		ranking.push_back(newPlayer);
		std::cout << "Name: " << ranking[i].name << " Highest Score: " << ranking[i].score;
	}
}


void main() {



}