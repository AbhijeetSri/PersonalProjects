#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace ::std;
int main()
{
	int i, res =0;
	fflush(stdin);
	res= scanf_s("%x",&i);
	fflush(stdin);
	cout << "\n"<<res;
	cout << "\n"<<i;
	_getch();
}