#include<iostream>
#include<conio.h>
using namespace::std;
#define CLEAR_BIT(a,pos) (a&= ~(1<<pos))

void inplace_swap(int& a, int& b)
{
	a = a^b;
	b = a^b;
	a = a^b;
	cout << a << "\n" << b;
}

void print_binary(int number)
{
	/*
	LOGIC : 128 is binary with 1 at leftmost postion.
	shift and compare with each postion using & print 1 if match else 0
	*/
	printf("\nBinary of %d is: \n", number);
	for (int i = 128; i >= 1; i >>= 1)
	{
		((number&i) == i) ? printf("%d", 1) : printf("%d", 0);
	}
}

void printdec2hex(int n)
{
	const int	NIBBLE = sizeof(int)*CHAR_BIT / 4; // number of nibbles(4) in an integer
	int i = 0;
	char* hexstring = "0123456789ABCDEF";
	cout << "decimal: " << n << "\n";
	cout << " Hex: ";
	for ( i = NIBBLE - 1; i >=0; i--)
	{
		cout << hexstring[(n >> i * 4) & 0xF];
	}
	cout << "\n reverse: ";
	for (i = 0; i < NIBBLE; i++)
	{
		cout << hexstring[(n >> i * 4) & 0xF];
	}

}

void setbits_pos( int N, int M, int i , int j)
{
	// Clear bits from position i to j in N and put M in it
	
	unsigned int max = ~0; // All 1s
	cout << "\nMax Value:" << max;
	int left = max - ((1 << i) - 1);
	cout << "\nLeft :"; print_binary(left);
	int right = ((1 << j) - 1);
	cout << "\nRight:"; print_binary(right);
	print_binary(left | right);
	cout << "\n Shifted value: ";
	print_binary((left | right) | M << j);
}

int main()
{
	unsigned int dig1 = 10;//0xA;
	int a{ 0 }, b{ 0 };
	//cout << dig1 << "\n"; 	cout << (dig1 << 1)<<"\n";
	//unsigned int max = ~0; 
//	cout << (max>>1) << "\n"; 	cout << max << "\n";
	//cout << "Enter 2 digits to swap in place \n";
	//cin >> a >> b;
	//inplace_swap(a, b);
	//char test = '10';
	//int test = 65;
	//printf("charachter = %c  , decimal = %d , hex = %x",test,test,test);
	// printdec2hex(1000);
	 setbits_pos(14 ,2, 5,2);
	_getch();

}

