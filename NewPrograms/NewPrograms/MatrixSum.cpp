#include<iostream>
#include<map>
#include<conio.h>
using namespace std;

const int no_row = 3;
const int no_col = 3;

int sum_matrix(int mat[no_row][no_col],int row1, int col1, int row2, int col2)
{
	int sum = 0;
	for (int i = 0; i < no_row; i++)
	{
		for (int j = 0; j < no_col; j++)
		{
			sum = sum + mat[i][j];
		}
	}
	return sum;
}

struct mykey{
	int r1;
	int c1;
	int r2;
	int c2;
};


void main()
{

	map <string, int> mymap;
	int sum = 0;
	string k;// = NULL;
	int mat[no_row][no_col] = { 1, 2, 3, 4, 5, 6, 7, 6, 5 };
	for (int I = 0; I < no_row; I++)
	{
		for (int J = 0; J < no_row; J++)
		{
			for (int i = 0; i < no_row; i++)
			{
				for (int j = 0; j < no_col; j++)
				{
					//mykey* k = new mykey;
					k = I + "," + J;// +"," + i + "," + j;

				/*	k->r1 = I;
					k->c1 = J;
					k->r2 = i;
					k->c2 = j;*/
					sum = sum_matrix(mat, I, J, i, j);
					mymap[k] = sum;

					delete(k);

				}
			}
		}
	}
	_getch();
}