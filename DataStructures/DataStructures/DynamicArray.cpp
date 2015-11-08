#include "stdafx.h"
#include "DynamicArray.h"

using namespace std;

void DynamicArray::add(int data)
{
	if (size == capacity)
	{
		capacity = capacity + increment;
		ptr = (int *)realloc(ptr,capacity);
	}
	*(ptr+size) = data;
	size = size + 1;
}

int* DynamicArray::getArray()
{
	return ptr;
}

int DynamicArray::getSize()
{
	return size;
}