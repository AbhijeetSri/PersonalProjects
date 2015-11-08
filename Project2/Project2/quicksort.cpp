#include<iostream>
#include<conio.h>

using namespace ::std;
const int SIZE = 100;

void quicksort(int*, int, int);
int partition(int*, int, int);
void swap(int* A, int a, int b)
{
	int temp = 0;
	temp = A[a];
	A[a] = A[b];
	A[b] = temp;

}
int main()
{
	int A[SIZE], n = 0;
	cout << "\n Enter the number of elements: ";
	cin >> n;
	for (int i = 0; i < n; i++){
		cout << "\n Enter a number: ";
		cin >> A[i];
	}
	cout << "\n Sorting now\n ";
	
	quicksort(A, 0, n-1);
	
	cout << "Sorted Array: ";
	 for (int i = 0; i < n; i++)
	{	cout << " " << A[i];
	}
	 _getch();
	 return 0;
}

 void quicksort(int* A, int start, int end)
{
	int pIndex=0;
	
	if (start < end) // Recursion base condition
	{	pIndex = partition(A, start, end);
		quicksort(A, start, pIndex-1 );
		quicksort(A, pIndex+1, end);
	}
	//return A;
}

int partition(int* A, int start, int end)
{
	int pIndex = start, pivot,i = 0;
	pivot = A[end];
	//cout << "pivot =" << pivot << endl;
	for (i = start; i < end ; i++)
	{
		if (A[i] <= pivot){
			swap(A, i, pIndex);// &A[i], &A[pIndex]);
			pIndex++; }
	}
	swap(A, pIndex, end);// &A[pIndex], &A[end]);
	return pIndex;
}