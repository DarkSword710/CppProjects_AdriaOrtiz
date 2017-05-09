#pragma once
class myStack
{
	struct node {
		int value;
		node* next;
	};

private:

	node* first;

public:

	myStack();
	myStack(myStack* stack);
	myStack(int* anArray);

	void pop();
	void push(int value);
	int front();
	bool isEmpty();
	int size();

	~myStack();

};

