#include<iostream>
#include<algorithm>
#include<map>
#include<conio.h>
using namespace std;

void main()
{
	map<int, int> mymap;
	int arr[5] = { 1, 1, 3, 2, 2 };
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << "\t" << mymap[arr[i]] << "\n";
		mymap[arr[i]] = mymap[arr[i]] + 1;
	}
	for (int i = 0; i < 4; i++)
	{
		if (mymap[arr[i]] % 2 == 0) {
			cout << arr[i]; break;
		}
	}
	_getch();
}