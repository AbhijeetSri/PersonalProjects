#include<iostream>
#include<conio.h>
using namespace ::std;

void set_zero(int A[3][3], int i, int j);
int ROW[3] = { 0, 0, 0 };
int COL[3] = { 0, 0, 0 };
void main()
{
	int row, col;
	cin >> row;
	cin >> col;
	int A[3][3] = { { 1, 2, 0 }, { 0, 5, 6 }, {7, 8, 9} };
	int zeroA[3][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
	int l = 4;

	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < l; j++)
		{
			if (A[i][j] == 0 && !ROW[i] && !COL[j]) {
				set_zero(A, i, j);
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << A[i][j] << "\t";
		}
		cout << "\n";
	}

	_getch();
}

void set_zero(int A[3][3], int i, int j)
{
	ROW[i] = 1;
	COL[j] = 1;
	int a = 0;
	do
	{
		A[i][a] = 0;
		a++;
	} while (a < 3);
	a = 0;
	do
	{
		A[a][j] = 0;
		a++;
	} while (a < 3);
}