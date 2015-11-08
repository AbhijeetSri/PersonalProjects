#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace ::std;

int fibonacci(int, int,int);

int main()
{
	int s,n = 0;
	cout << "Enter the no of terms";
	cin >> n;
	cout << "\n" << "0";
	s = fibonacci(0,1,n);
	_getch();
}

int fibonacci(int curr, int prev,int  n)
{
	if (n ==1 ) return 0;
	cout << "\n"<< curr + prev;
	fibonacci(curr + prev, curr,n-1);

}