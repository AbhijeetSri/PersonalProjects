#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace ::std;

void swap(int* one, int* another);
void shiftbyn(int A[3][3], int x, int y, int n);
void rotate_mat(int m[3][3]);
void cyclic_roll(int &a, int &b, int &c, int &d);

void printmat(int A[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << A[i][j] << "\t";
		}
		cout << "\n";
	}
}

void main()
{
	int A[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	// centre = A[2][2];
	printmat(A);
	cout << "\n";
	rotate_mat(A);
//	shiftbyn(A, 0, 0, 2);
//	printmat(A);
		_getch();

}

void shiftbyn(int A[3][3], int x, int y, int n)
{
	int temp = A[x][y];
	int l = 2;
	while (n > 0)
	{

		for (int i = 0; i < l; i++, y++)
		{
			int temp1 = A[x][y];
			A[x][y] = temp;
			temp = temp1;
		}
		for (int i = 0; i < l; i++, x++)
		{
			int temp1 = A[x][y];
			A[x][y] = temp;
			temp = temp1;
		}
		for (int i = 0; i < l; i++, y--)
		{
			int temp1 = A[x][y];
			A[x][y] = temp;
			temp = temp1;
		}
		for (int i = 0; i < l; i++, x--)
		{
			int temp1 = A[x][y];
			A[x][y] = temp;
			temp = temp1;
		}
		A[x][y] = temp;
		n--;
	}
	}

void rotate_mat( int m[3][3])
{
	int n = 3;
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < (n + 1) / 2; j++)
		{
			cyclic_roll(m[i][j], m[n - 1 - j][i], m[n - 1 - i][n - 1 - j], m[j][n - 1 - i]);
			cout << "\n step: \n";
			printmat(m);
		}
	}
	cout << "\n Final Matrix:\n";
	printmat(m);
}


void cyclic_roll(int &a, int &b, int &c, int &d)
{
	int temp = a;
	a = b;
	b = c;
	c = d;
	d = temp;
}