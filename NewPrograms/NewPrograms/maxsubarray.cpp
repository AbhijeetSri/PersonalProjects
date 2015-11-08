#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int a[] = { 2, -3, -2, 4, -2, -4, 6, -3, -4,0 };
	int size = 10; int max_so_far = 0; int max_ending_here = 0;

	for (int i = 0; i < size; i++)
	{
	//	max_end_here
		(max_ending_here + a[i] > 0) ? max_ending_here = max_ending_here + a[i] : max_ending_here = 0;
		
			if (max_so_far < max_ending_here) max_so_far = max_ending_here;
	}
	
	_getch();
}