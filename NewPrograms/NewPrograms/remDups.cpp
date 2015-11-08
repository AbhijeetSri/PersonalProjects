#include<iostream>
#include<conio.h>
#include<map>
using namespace std;
const int MAX_SIZE = 10;

void rem_dup(int* arr);
void reverse_array(int * arr);
int is_present(int* arr, int val);
int main()
{
	int arr[] = { 1, 2, 3, 2, 3, 1, 4, 5, 6, 3 };
	//rem_dup(arr);
	reverse_array(arr);
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << arr[i];
	}
	_getch();
	return 0;
}

void reverse_array(int * arr)
{

	int* tarr = arr;
	int left =0 , right = MAX_SIZE-1;
	int temp = 0;
	while (left <= right)
	{
		temp = tarr[left];
		tarr[left] = tarr[right];
		tarr[right] = temp;

		left++; right--;
	}

}







void rem_dup(int* arr)
{
	int new_arr[MAX_SIZE];
	//map<int,int>  mymap;
	//map<int, int>::iterator it;
	int count = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << arr[i];
		if (is_present(new_arr, arr[i]) == 0)
		{
			new_arr[count] = arr[i]; count++;
		}
	}
		//it = mymap.find(arr[i]);
		//mymap.insert(arr[i],1);
		/*if (mymap.count(arr[i]) != 0)
		{
			mymap.insert(arr[i], 1);
		}*/
	cout << "\n Duplicates removed:";
	for (int i = 0; i < count; i++)
	{
		cout << new_arr[i];
	}

	
}

int is_present(int* arr, int val)
{
	
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (arr[i] == val) return 1;
	}
	return 0;
}