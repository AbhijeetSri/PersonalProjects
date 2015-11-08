#include<iostream>
#include <conio.h>

using namespace std;
int main()
{
	int arr[10] = { 1, -8, -2, -4, -9, -0, -5, -3, -2, -4 };
	int sum_so_far = 0;
	int sum = 0;
	for (int i = 0; i < 10; i++){
		if (sum + arr[i] < sum)
		{
			sum = 0;
		}
		else{
			sum = sum + arr[i];
		}
		if (sum > sum_so_far) sum_so_far = sum;

	}
	cout << "\n Maximum Sum : " << sum_so_far;
	_getch();
}