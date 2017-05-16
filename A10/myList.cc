#include "myList.hh"



myList::myList() : first{ nullptr }, last{ nullptr }, sizeOfList{ 0 }
{

}

myList::myList(myList& ml) : first{ new node({ml.front(), nullptr, nullptr}) }, last{ first }, sizeOfList{ 1 }
{
	ml.pop_front();
	while (!ml.isEmpty())
	{
		push_back(ml.front());
		ml.pop_front();
	}
}

int myList::front()
{
	return first->value;
}

int myList::back()
{
	return last->value;
}

void myList::push_front(int i)
{
	if(first == nullptr) {
		first = new node({ i, nullptr, nullptr });
		last = first;
	}
	else {
		first->before = new node({ i, first, nullptr });
		first = first->before;
	}
	sizeOfList++;
}

void myList::push_back(int i)
{
	if (last == nullptr) {
		last = new node({ i, nullptr, nullptr });
		first = last;
	}
	else {
		last->next = new node({ i, nullptr, last });
		last = last->next;
	}
	sizeOfList++;
}

void myList::pop_front()
{
	if (first->next == nullptr) {
		delete first;
		first = nullptr;
		last = nullptr;
	}
	else {
		first = first->next;
		delete first->before;
		first->before = nullptr;
	}
	sizeOfList--;
}

void myList::pop_back()
{
	if (last->before == nullptr) {
		delete last;
		last = nullptr;
		first = nullptr;
	}
	else {
		last = last->before;
		delete last->next;
		last->next = nullptr;
	}
	sizeOfList--;
}

void myList::insert(int i, int j)
{
	node* aux = first;
	for (int it = 0; it < i; i++) {
		aux = first->next;
	}
	aux = new node({ j, aux, aux->before });
	aux->before->next = aux;
	aux->next->before = aux;
	sizeOfList++;
}

void myList::erase(int i)
{
	node* aux = first;
	for (int it = 0; it < i; i++) {
		aux = first->next;
	}
	aux->before->next = aux->next;
	aux->next->before = aux->before;
	delete aux;
	sizeOfList--;
}

int myList::size()
{
	return sizeOfList;
}

bool myList::isEmpty()
{
	if (first == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

myList::~myList()
{
	while (!isEmpty())
	{
		pop_front();
	}
}
