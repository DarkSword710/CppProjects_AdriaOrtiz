#include <vector>

std::vector<int>v1(5);
std::vector<int>v2(10,0);
std::vector<int>v3({10,9,8,7,6,5,4,3,2,1});
std::vector<std::string>v4({"Gertrudiz","Pancracia","Anacleto","Hipolito","Eustaquio","Fulgencia"});
std::vector<int>v5(v3);

std::vector<int> AddVectors(std::vector<int> vOne, std::vector<int> vTwo) {
	std::vector<int>vSuma(vOne);
	for (int i = 0; i != vOne.size(); ++i) {
		vSuma[i] += vTwo[i];
	}
	return vSuma;
};

void ConcatVectors(std::vector<int> vOne, std::vector<int> vTwo) {
	
};