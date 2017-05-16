#pragma once
class myList
{
	struct node {
		int value;
		node* next;
		node* before;
	};
private:
	node* first;
	node* last;
	int sizeOfList;
public:
	myList();
	myList(myList& ml);
	int front();
	int back();
	void push_front(int i);
	void push_back(int i);
	void pop_front();
	void pop_back();
	void insert(int i, int j);
	void erase(int i);
	int size();
	bool isEmpty();
	~myList();
};

