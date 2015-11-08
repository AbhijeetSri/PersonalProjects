#include<iostream>
#include<string.h>
#include<conio.h>
using namespace ::std;

int isUnique(char* str);


int main()
{
	int res = isUnique("qwertyuiop");
	if (res == 1)cout << "Non Unique found\n";
	else cout << "Uniques charachters\n";
	_getch();
	return 0;
}

int isUnique(char * str)
{
	//int* char_set = new int[256];
	int* char_set = (int*)malloc(10);
	int* temp;
	int t = 0, res = 0;
	free(char_set);
	temp = char_set;
	for (int i = 0; i < 256; i++)
	{
		*temp = 0;
		temp++;
	}
	for (int i = 0; *str != '\0';i++)
	{
		t = *str;
		if (char_set[t] >= t) {
			res = 1; break;
		}
		char_set[t] = char_set[t] + t;
		str++;
	}
	return res;
}