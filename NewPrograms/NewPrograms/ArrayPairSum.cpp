#include<algorithm>
#include<iostream>
#include<conio.h>
#include<map>

using namespace std;

const int SIZE = 10;
const int SUM = 9;
void main()
{
	int arr[SIZE] = { 5, 7, 5, 4, 5, 3, 1, 8, 6, 8 };
	// Given a sorted array : find the pair which equal to the given sum
	sort(arr, arr + SIZE);
	for (int i = 0; i < 10; i++) cout << arr[i]<<"\t";
	// Sorting nlogn
	// start from left and right .. 
	int* left = arr;
	int * right = arr+SIZE-1;
	while (*left <= *right)
	{
		if (*left + *right == SUM)
		{
			cout << "\nPair: " << *left << "\t" << *right;
			left++;
		}
		else if (*left + *right < SUM) left++;
		else if (*left + *right > SUM) right--;
	}
	
	cout << "\n Method 2 using hash maps:\n";
	// Method 2 Using Hash Maps , linear time
// scan each item and see if SUM- arr[i] is in map , else add the element to hash map
	map<int, int> mymap;
	for (int i = 0; i < 10; i++)
	{
		if (mymap[SUM - arr[i]] + arr[i] == SUM)
		{
			cout << "\nPair: " << mymap[SUM - arr[i]] << "\t" << arr[i];
		}
		else
		{
			mymap[arr[i]] = arr[i];
		}
	}

	_getch();
}