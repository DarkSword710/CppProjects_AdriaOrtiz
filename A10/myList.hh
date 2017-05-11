#pragma once
class myList
{
	struct node {
		int value;
		int* next;
		int* before;
	};
private:
	node* list;
	int sizeOfList;
public:
	myList();
	int front();
	int back();
	void push_front(int i);
	void push_back(int i);
	void pop_front();
	void pop_back();
	void insert(int* i, int j);
	void erase(int* i);
	int size();
	~myList();
};

