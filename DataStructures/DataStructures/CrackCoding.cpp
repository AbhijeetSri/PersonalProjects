#include "stdafx.h"

using namespace std;

void crackCodingMain()
{
	int chapterNo, problemNo, choice, length, i,j, count=0;
	char *charPtr;
	string str;
	cout << "Enter the chapter number: ";
	cin >> chapterNo;
	cout << "Enter the problem number: ";
	cin >> problemNo;
	choice = 100 * chapterNo + problemNo;
	switch (choice)
	{
	case 101:
		cout << "Wait for completion\n";
		break;
	case 104: // replace space by %20
		cout << "Enter the length of string: ";
		//cin >> length;
		scanf("%d",&length);
		charPtr = new char[length + 20];
		cout << "Enter the string with spaces: ";
		//fgets(charPtr, length+20, stdin);
		fflush(stdin);
		scanf("%[^\n]s",charPtr);
		cout << "input = " << charPtr << endl;
		//getline(cin, str);
		// replacing space by %20
		for (i = 0; i < length; i++)
		{
			if (charPtr[i] == ' ')
				count++;
		}
		for (i = length, j = length + 2 * count; i >= 0; i--)
		{
			if (charPtr[i] == ' ')
			{
				charPtr[j--] = '0';
				charPtr[j--] = '2';
				charPtr[j--] = '%';
			}
			else
				charPtr[j--] = charPtr[i];
		}
		cout << "String after replacement: " << charPtr << endl;
		break;
	case 105: // string compression
	default:
			cout << "wrong choice\n";
	}
}