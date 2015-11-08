#include<iostream>
#include<conio.h>
using namespace std;

void rem_vowels(char* str)
{
	int i = 0;
	char* temp = str;
	while (temp[i] != '\0')
	{
		if (temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u')
		{
			int j = i;
			while (temp[j] != '\0')
			{
				temp[j] = temp[j + 1];
				j++;
			}
		}
		else
		{
			i++;
		}
	
	}

}


void main()
{
	char str[] = { "The quick brown fox jumps over a lazy dog" };
	rem_vowels(str);
	int i = 0;
	cout << str;
	_getch();
}