#include "stdafx.h"

#define INITIAL_CAPACITY 10
#define INCREMENT 10

class DynamicArray
{
private:
	int *ptr;
	unsigned int size;
	unsigned int capacity;
	unsigned int increment;


public:
	DynamicArray()
	{
		capacity = INITIAL_CAPACITY;
		increment = INCREMENT;
		size = 0;
		ptr = (int *)malloc(capacity);
	}
	void add(int data);
	int* getArray();
	int getSize();
	~DynamicArray()
	{
		//if (ptr != NULL)
		//	free(ptr);
	}
};