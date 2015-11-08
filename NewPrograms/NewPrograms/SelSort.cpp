#include<iostream>
#include<conio.h>
using namespace std;
const int MAX_SIZE = 10;
void main()
{

	int arr[MAX_SIZE] = { 3, 43, 2, 4, 5, 12, 5, 6, 12, 6 };
	cout << "Original Array \n";
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << arr[i] << "\t";
	}
	int small = 0, temp = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		small = i;
		for (int j = i; j < MAX_SIZE; j++)
		{
			if (arr[j] < arr[small])
			{
				small = j;
			}
		}
		temp = arr[small];
		arr[small] = arr[i];
		arr[i] = temp;
	}
	cout << "Sorted Array \n";
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << arr[i] <<"\t";
	}

	_getch();
}

