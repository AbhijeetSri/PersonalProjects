#include<iostream>
#include<conio.h>
using namespace ::std;
void quick_sort(int numbers[10]);
void swap(int A[], int a, int b);

int partition(int A[], int start, int end)
{
	int pIndex = start, pivot, i = 0;
	pivot = A[end];
	//cout << "pivot =" << pivot << endl;
	for (i = start; i < end; i++)
	{
		if (A[i] <= pivot)
		{
			swap(A, i, pIndex);// &A[i], &A[pIndex]);
			pIndex++;
		}
	}
	swap(A, pIndex, end);// &A[pIndex], &A[end]);
	return pIndex;
}

void swap(int A[], int a, int b)
{
	int temp = 0;
	temp = A[a];
	A[a] = A[b];
	A[b] = temp;

}

int* quickSort(int A[], int start, int end)
{
	int pIndex = 0;

	if (start < end) // Recursion base condition
	{
		pIndex = partition(A, start, end);
		quickSort(A, start, pIndex - 1);
		quickSort(A, pIndex + 1, end);
	}
	
	return A;
}

int main()
{
	return 0;
}