#include<iostream>
#include<conio.h>
using namespace ::std;


char* rev_str(char *);
char * n_rev(char*);
void main()
{
	char*s = new char[100];
	cin >> s;
	//	char* str_rev = rev_str("abcd");
	char* str_rev = n_rev(s);

}

char* rev_str(char* o_str)
{
	char* r_str = new char[strlen(o_str) + 1];// = { ' ' };
	int l = strlen(o_str);
	*(r_str + l) = 0;
	for (int i = 1; *o_str != '\0'; i++)
	{
		*(r_str + l - i) = *o_str;
		o_str++;
	}
	return r_str;
}

char* n_rev(char* t_str)
{
	char * o_str = new char [sizeof(strlen(t_str))+1];
	o_str = t_str;
	char temp;
	char* end = o_str;
	
	if (o_str)
	{
		while (*end)
		{
			end++;
		}
		end--;
	}
	while (o_str < end)
	{
		temp = *o_str;
//		*o_str++ = *end;
		*o_str = *end;
		o_str++;
		*end-- = temp;
		//end--;
		//o_str++;
	}
	return end;
}