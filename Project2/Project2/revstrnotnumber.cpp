/*reverse characters but not numbers 
input - "this is agent 123abd from location 89xy"
output - "siht si tnega 123dba morf noitacol 89yx"*/

#include<iostream>
#include<conio.h>
using namespace std;

void rev_str(char* s);
void print_rev(char* text, int start, int end);
void main()
{
	char* s = "abc bef21fe ret";
	rev_str(s);
	_getch();
}

void rev_str(char* s)
{
	int i, l = 0;
	int start = 0, end = 0;
	char * t = s;
	while (*t != '\0'){
		l++; t++;
	}
	cout << "length" <<l;

	for (i = 0; i <= l; i++)
	{
		//if (s[i] is number) print it. reset start and end
		if ( (int)s[i] >= 48 && (int)s[i] <= 57)
		{
			print_rev(s, start, end-1);
			cout << s[i];
			start = end ++; //end++;
		}
		if (s[i] != ' ' )
		{
				end++; 

		}
		else 
		{
			// create a strign from strt and end and pass to print rev
			// start = end;
			print_rev(s, start, end);
			start = end + 1;
			end++;
		}
		if (s[i] == '\0'){
			print_rev(s, start, end);
			start = end + 1;
			end++;
		} 
	}

}

void print_rev(char* text, int start, int end)
{
	for (int i = end; i >= start; i--)
	{
		cout << text[i];
	}
}