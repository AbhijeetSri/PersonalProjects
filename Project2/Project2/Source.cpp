#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace ::std;

char* RemoveCommas(char *arr) {
	char *curr = arr, *tail = arr;
	while (*curr) {
		if (*curr != ',') {
			if (curr != tail)
				*tail = *curr;
			curr++;
			tail++;
		}
		else
			curr++;
	}
	*tail = '\0';
	return arr;
}
void main()
{
	char arr[] = "1,234,34,54";
  // RemoveCommas(arr);

	int pt[] = { 1, 4, 23, 4};
	char* ctr;
	cout<< *pt<<"\n";
	cout << &pt<<"\n";
	cout << pt+1 << "\n";
	cout << *(pt+1) << "\n";
	cout << *pt << "\n";
	ctr = (char*)pt;
	ctr++;
	cout << *ctr;
	cout << ctr << "\n";
	_getch();

}
	
