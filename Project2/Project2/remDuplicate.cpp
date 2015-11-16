#include<iostream>
#include<conio.h>
using namespace ::std;

void rem_dup(char*);

void main()
{
	char* s = new char[100];
	cin >> s;
	rem_dup(s);
}

 void rem_dup(char* s)
{
	char* start = s;
	char* tail = start;
	while (*start)
	{
		tail = start;
		while (*tail)
		{
			if (*start == *++tail)
			{
				*tail = ',';
			}
		}
		start++;
	}
//	return start;
	start = s;
 
 }
