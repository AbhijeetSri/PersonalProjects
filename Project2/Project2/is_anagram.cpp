#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

using namespace::std;

void is_anagram(char*, char*);
int main()
{
	char* str1 = new(char[10]);
	char* str2 = new(char[10]);
	
	printf("\n Enter string");
	cin >> str1;
	cout << "\n Enter String 2: ";
	cin >> str2;
	
	is_anagram(str1, str2);
	
	_getch();
	return 0;
}

void is_anagram(char* str1, char* str2)
{
	int l1, l2 = 0, found = 0;
	l1 = strlen(str1);
	l2 = strlen(str2);
	if (l1 != l2) cout << "\n Not an Anagram . length different\n"; return false;
	int all_character[] = new int[256];
	for (int i = 0; i < l1; i++)
	{
		found = 0;
		for (int j = 0; j < l2; j++)
		{
			if (str1[i] == str2[j]) found = 1;
		}
		if (found == 0) {
				cout << "\n not an anagram";
				break;
			}
	}
	if (found == 1) cout << "\n Is an anagram";
//	return 0;
}