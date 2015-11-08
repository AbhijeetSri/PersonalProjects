// DataStructures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HashTable.h"
#include "StringBuffer.h"
#include "DynamicArray.h"
#include "CrackCoding.h"

using namespace std;

void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << A[i] << ' ';
	}
	cout << endl;
}

char* inputString(int *size)
{
	unsigned int capacity = 128, length = 0;
	char c = EOF;
	char *ptr = (char *)malloc(capacity);
	while ((c = getchar()) != '\n' && c != EOF)
	{
		if (length == capacity)
		{
			capacity = capacity + 128;
			ptr = (char*)realloc(ptr, capacity);
		}
		*(ptr + length) = atoi(&c);
		length = length + 1;
	}
	*size = length - 1;
	return ptr;
}

int* inputArray(int *size)
{
	DynamicArray dynamicArray;
	bool flag = true;
	char buffer[10];
	cout << "Enter the numbers one by one(e to end):";
	while (1)
	{
		fgets(buffer, 10, stdin);
		if (buffer[0] == 'e')
			break;
		if (buffer[0] != '\n')
			dynamicArray.add(atoi(buffer));
	}
	*size = dynamicArray.getSize();
	return dynamicArray.getArray();


	// Old code which required size of string to be input
	/*int size_input;
	cout << "Enter the number of elements :";
	cin >> size_input;
	//int *p = (int*)malloc(size_input*sizeof(int)); // C-language
	int *p = new int[size_input];
	if (p == NULL)
	{
		cout << "Unable to allocate memory";
		return NULL;
	}
	cout << "Enter the elements one by one\n";
	for (int i = 0, value; i < size_input; i++)
	{
		cout << i + 1 << '.';
		cin >> value;
		p[i] = value;
	}
	*size = size_input;
	return p;*/
}

/* returns the index of value if found */
int binarySearch(int A[], int size, int k)
{
	int low = 0, mid = 0;
	int high = size - 1;
	do
	{
		mid = (low + high) / 2;
		if (A[mid] == k)
		{
			return mid+1;
		}
		else if (k < A[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	} while (low <= high);
	return NULL;
}

void swap(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void quickSort(int A[], int size, int debugFlag)
{
	cout << "Under Progress";
	return;
	if (debugFlag)
		printArray(A, size);   /* to print the array after every iteration */

}

void mergeSort(int A[], int size, int debugFlag)
{
	cout << "Under Progress";
	return;

	if (debugFlag)
		printArray(A, size);   /* to print the array after every iteration */
}

void heapSort(int A[], int size, int debugFlag)
{
	cout << "Under Progress";
	return;

	if (debugFlag)
		printArray(A, size);   /* to print the array after every iteration */
}

/* Pick an element and find its correct place and then insert there */
void insertionSort(int A[], int size, int debugFlag)
{
	for (int i = 1; i < size; i++)
	{
		int key = A[i];
		int j = i;
		while (A[j-1] > key && j > 0)
		{
			A[j] = A[j-1];
			j--;
		}
		A[j] = key;
		if (debugFlag)
			printArray(A, size);   /* to print the array after every iteration */
	}

}

/* algo finds the smallest in the unsorted part and swap it with first element in unsorted list */
void selectionSort(int A[], int size, int debugFlag)
{
	int smallestIdx;
	for (int i = 0; i < size - 1; i++)
	{
		smallestIdx = i;
		for (int j = i + 1; j < size; j++)
		{
			if (A[j] < A[smallestIdx])
			{
				smallestIdx = j;
			}
		}
		if (i != smallestIdx)
			swap(&A[i], &A[smallestIdx]);
		if (debugFlag)
			printArray(A, size);   /* to print the array after every iteration */
	}
}

/* Compare the neighbours and swap if required */
void bubbleSort(int A[], int size, int debugFlag)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (A[j] > A[j + 1])
				swap(&A[j], &A[j + 1]);
		}
		if (debugFlag)
			printArray(A, size);   /* to print the array after every iteration */
	}
}

void sort(int A[], int size)
{
	int choice = 0, debugFlag = 0;
	char debug;
	cout << "Choose the type of sorting:\n1. Selection Sort\n2. Insertion Sort\n3. Bubble Sort\n4.Crack coding";
	cout << "4. Merge Sort\n5. Quick Sort\n6. Heap Sort\n";
	cin >> choice;
	cout << "Do you want to see array after each iteration? (y or n): ";
	cin >> debug;
	if (debug == 'y')
		debugFlag = 1;
	switch (choice)
	{
	case 1:
		selectionSort(A, size, debugFlag);
		break;
	case 2:
		insertionSort(A, size, debugFlag);
		break;
	case 3:
		bubbleSort(A, size, debugFlag);
		break;
	case 4:
		mergeSort(A, size, debugFlag);
		break;
	case 5:
		quickSort(A, size, debugFlag);
		break;
	case 6:
		heapSort(A, size, debugFlag);
		break;
	}
	cout << "Sorted Array :\n";
	printArray(A, size);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int choice = 0, *p, key = 0, index = 0, size = 0;
	HashTable hashTable;
	StringBuffer stringBuffer;
	string name;
	cout << "Choose your option:\n1. Binary Search\n2. Sorting\n3. Hash Maps\n4. String Buffer\n100. CrackCoding\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		p = inputArray(&size);
		if (p != NULL)
		{
			insertionSort(p, size, 0);
			printArray(p, size);
			cout << "Enter the number to be searched\n";
			cin >> key;
			index = binarySearch(p, size, key);
			if (index == NULL)
				cout << "Number not found\n";
			else
				cout << "Number found at " << index << endl;
		}
		free(p);
		break;
	case 2:
		p = inputArray(&size);
		if (p != NULL)
		{
			sort(p, size);
		}
		free(p);
		break;
	case 3:
		int count, rollnumber;
		cout << "Enter the number of entries: ";
		cin >> count;
		for (int i = 0; i < count; i++)
		{
			cout << "Enter the rollnumber: ";
			cin >> rollnumber;
			cout << "Enter the name: ";
			cin >> name;//getline(cin,name);
			hashTable.addEntry(rollnumber, name);
		}
		cout << "Enter the roll number to find the entry: ";
		cin >> rollnumber;
		cout << "Name found: " << hashTable.getEntry(rollnumber) << endl;
		break;
	case 4:
		cout << "Enter the number of strings: ";
		cin >> count;
		for (int i = 0; i < count; i++)
		{
			cout << "Enter String" << i+1 << ": ";
			cin >> name;
			stringBuffer.append(name);
		}
		cout << "Final string: " << stringBuffer.toString() << endl;
		stringBuffer.reset();
			break;
	case 100:
		crackCodingMain();
		break;
	default:
		cout << "Wrong choice\n";
	}
	return 0;
}