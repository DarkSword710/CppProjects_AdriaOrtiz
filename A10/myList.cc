#include "myList.hh"



myList::myList() : list{ nullptr }, sizeOfList{ 0 }
{

}

int myList::front()
{
	return list[0];
}

int myList::back()
{
	return list[sizeOfList];
}

void myList::push_front(int i)
{
	int aux[sizeOfList] = ();
	list = new int[sizeOfList + 1] ;
}

void myList::push_back(int i)
{

}

void myList::pop_front()
{

}

void myList::pop_back()
{

}

void myList::insert(int* i, int j)
{

}

void myList::erase(int* i)
{

}

int myList::size()
{
	return sizeOfList;
}

myList::~myList()
{
}
