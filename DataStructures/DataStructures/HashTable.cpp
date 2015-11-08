#include "stdafx.h"
#include "HashTable.h"
using namespace std;

int HashTable::hashFunction(int rollnumber) // returns a key (index of array)
{
	return (rollnumber % SIZE_OF_HASH_TABLE);
}

void HashTable::addEntry(int rollnumber, string name)
{
	int key = hashFunction(rollnumber);
	LinkedList *list;
	if (hash[key] == 0) // linked list needs to be created
	{
		list = new LinkedList;
		list->addLast(name, rollnumber);
		hash[key] = list;
	}
	else
	{
		list = hash[key];
		list->addLast(name, rollnumber);
	}
}

string HashTable::getEntry(int rollnumber)
{
	int key = hashFunction(rollnumber);
	LinkedList *list = hash[key];
	if (list == 0)
		return NULL;
	else
	{
		return list->find(rollnumber);
	}
}

void HashTable::deleteEntry()
{

}

int HashTable::sizeOfContent()
{
	return count;
}

bool HashTable::isEmpty()
{
	if (count > 0)
		return false;
	else
		return true;
}