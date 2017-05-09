#include "myStack.h"



myStack::myStack() : first{ nullptr }
{
}

myStack::myStack(myStack* stack) : first { }
{
}

myStack::myStack(int* anArray)
{
}

void myStack::pop()
{
	if (size() > 0)
	{
		node* aux = first->next;
		delete first;
		first = aux;
	}
}

void myStack::push(int value)
{
	first = new node({ value, first });
}

int myStack::front()
{
}

bool myStack::isEmpty()
{
}

int myStack::size()
{
}

myStack::~myStack()
{
	while (!isEmpty) {
		pop
	}
}
