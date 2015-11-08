#include<iostream>
#include<conio.h>
using namespace ::std;

void print_arr(int ** A, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << A[i][j] <<"\t";
		}
		cout << "\n";
	}

}

void main()
{
	int r, c;
	cin >> r;
	cin >> c;
	int ** A = new int*[r];
	for (int i = 0; i < r; i++)
	{
		A[i] = new int[c];
		for (int j = 0; j < c; j++)
		{
			A[i][j] = rand();
		}
	}
	print_arr(A, r, c);

	_getch();
}
