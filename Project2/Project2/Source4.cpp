// multiple inheritance
#include <iostream>
#include<conio.h>
#include<math.h>
using namespace std;

void decTobinary(int);

int main()
{
	int binary =0;
	int dec;
	cout << "\n Enter decimal ";
	cin >> dec;
	decTobinary(dec);
	//cout << "\n " << binary;
	_getch();
}

void decTobinary(int dec)
{
	int i, remainder = 0, binary = 0, count =0;
	while(scnaf('x', %i)!= ferror);
	while (dec > 0)
	{
		remainder = dec % 2;
		count++;
		//cout << remainder;
		if (binary == 0 && remainder == 0) 
		{ binary = 10; }
		else 
		{ binary = binary * 10 + remainder; }
		
		dec = dec / 2;
	}
	binary = pow(10,count) - binary;
	cout << "\n" << binary;
	binary << 1;// << 1;
	cout << "\n" << binary;

}
