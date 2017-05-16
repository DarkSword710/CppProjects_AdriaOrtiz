#include <list>
#include <queue>
#include <unordered_set>
#include <iostream>
#include "myList.hh"

std::list<int> superMerge(std::list<int> list1, std::list<int> list2) {
	std::priority_queue<int> aux (list1.begin(), list1.end());
	std::list<int> result;
	for (std::list<int>::iterator it = list2.begin(); it != list2.end(); it++) {
		aux.push(*it);
	}
	while (!aux.empty()) {
		result.push_back(aux.top());
		aux.pop();
	}
	return result;
}

void change(std::list<int>& list) {
	int aux = list.back();
	list.pop_back();
	list.push_back(list.front());
	list.pop_front();
	list.push_front(aux);
}

int getElementPos(std::list<int> list, int position) {
	std::list<int>::iterator it = list.begin();
	for (int i = 0; i < position; i++) {
		it++;
	}
	return *it;
}

void removeDuplicates(std::list<int>& list) {
	std::unordered_set<int> aux;
	
	while (!list.empty()) {
		aux.insert(list.front());
		list.pop_front();
	}
	for (auto &x : aux) {
		list.push_back(x);
	}
}

void removeElement(std::list<int>& list, int erased) {
	std::list<int>::iterator it = list.begin();
	while (it != list.end()) {
		if (*it == erased) {
			it = list.erase(it);
		}
		else {
			it++;
		}
	}
}

bool palindrome(std::list<int> list) {
	while (list.size() > 1) {
		if (list.front() != list.back()) {
			return false;
		}
		else {
			list.pop_back();
			list.pop_front();
		}
	}
	return true;
}

void main() {
	//superMerge
	/*std::list<int> list1({ 9,7,4,1 });
	std::list<int> list2 ({8,5,2 });
	std::list<int> merged = superMerge(list1, list2);

	for (std::list<int>::iterator it = merged.begin(); it != merged.end(); it++) {
		std::cout << *it << std::endl;
	}*/

	//change
	/*std::list<int> list({ 9,7,4,1 });
	change(list);
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++) {
		std::cout << *it << std::endl;
	}*/

	//getElementPos
	/*std::list<int> list({ 9,7,4,1 });
	std::cout << getElementPos(list, 1);*/

	//removeDuplicates
	/*std::list<int> list({ 7,7,7,7,7,8,8,9,9,10 });
	removeDuplicates(list);
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++) {
		std::cout << *it << std::endl;
	}*/

	//removeElement
	/*std::list<int> list({ 7,7,7,7,7,8,7,9,7,10 });
	removeElement(list, 7);
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++) {
		std::cout << *it << std::endl;
	}*/

	//palindrome
	/*std::list<int> list({ 8, 6, 5, 6, 8 });
	std::cout << palindrome(list);*/

	myList one;
	one.push_back(1);
	one.push_back(2);
	one.push_back(3);

	myList two(one);

	while (!two.isEmpty()) {
		std::cout << two.front() << std::endl;
		two.pop_front();
	}
}