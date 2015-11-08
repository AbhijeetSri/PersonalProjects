#include<iostream>
using namespace std;


/*test cases
1. arr=nullptr
2. size = 1
3. size < 0 return
4. average case*/


void swap(int *a, int i, int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


void heapify(int * arr, int size){
	if (size <= 0)return;
	if (size == 1)return;
	int  c = 0, p = 0;
	for (int i = size - 1; i >= 0; i--){
		c = arr[i];
		p = arr[i / 2];
		if (p>c)
			swap(arr,i,i/2);
	}
}

void main(){
	int a[9] = {};
	int b[1] = { 12 };
	int c[8] = { 12, 5, 23, 11, 56, 7, 43, 2 };
	heapify(c, 8);
	int temp = c[0];
	c[1] = c[8-1];
	for (int i = 8 - 1; i > 1; i--)
	{
		heapify(c, i);
	}
	heapify(b, 1);
}