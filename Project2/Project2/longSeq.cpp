#include<iostream>
#include<conio.h>
using namespace std;

int ret_long_sq(int * arr, int len);
const int MAX_SIZE = 5;

int main()
{
	int arr[] = { 1,1,1,0,0,2,1};
	/*
	int res = 0;
	arr = new int[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i+)+
	{
		cout << "\n Enter digit";
		cin >> arr[i];
	}
	*/
	int res = ret_long_sq(arr,sizeof(arr)/sizeof(int));
	cout << "\n longest seq : " << res+1;
	_getch();
	return 0;
	
}

int ret_long_sq(int * arr, int len)
{
	int long_seq = 0, s= 0, seq =0;
	for (int i = 0; i < len; i++)
	{
//		s = arr[i + 1] - arr[i];
		if (arr[i + 1] - arr[i] >= s)
		{
			s = arr[i + 1] - arr[i];
			seq++;
			if(seq > long_seq) long_seq = seq;
		}
	else {
			s = 0; seq = 0;
		}
	}
	return long_seq;

}