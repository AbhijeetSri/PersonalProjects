#include<iostream>
#include<conio.h>
using namespace std;
const int SIZE = 10;
void main()
{
	int arr[SIZE] = { 2, 43, 23, 5, 12, 54, 2, 4, 5, 23 };
	int temp = 0;
	for (int j = 10; j > 0; j--)
	{
		int i = 0;
		while (i < j)
		{
			if (arr[i] < arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
			i++;
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "\t";
	}
	_getch();
}