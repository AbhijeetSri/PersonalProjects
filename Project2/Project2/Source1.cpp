#include<iostream>
#include<conio.h>
#include<stdio.h>

int main()
{
	char arr[] = { "1,2,3,4" };

	char* curr; char* tail;
	curr = tail = arr;
	while (*tail != '\0'){
		if (*tail != ',')
		{
			*curr = *tail;
			curr++; tail++;
		}
		tail++;
	}
	*curr = '\0';
}