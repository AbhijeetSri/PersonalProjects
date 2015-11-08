#include "stdafx.h"
#include "LinkedList.h"
using namespace std;

# define SIZE_OF_HASH_TABLE 100

class HashTable
{
private:
	LinkedList *hash[SIZE_OF_HASH_TABLE]; // array of pointers containg head pointer of the linked list
	int hashFunction(int rollnumber); // returns a key (index of array)
	int count;

public:
	HashTable() // constructor settiing all elements of the has table to zero
	{
		memset(hash, 0, sizeof(LinkedList*) * SIZE_OF_HASH_TABLE);
	}
	void addEntry(int rollnumber, string name);
	string getEntry(int rollnumber);
	void deleteEntry();
	int sizeOfContent();
	bool isEmpty();

};