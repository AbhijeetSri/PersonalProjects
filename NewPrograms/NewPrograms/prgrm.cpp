#include<iostream>
#include <stdio.h>
#include <string.h>
#include<conio.h>
#include<algorithm>
#include<list>
using namespace std;

const int max_size = 100;
const char hashTable[10][5] = { "", "", "abc", "def", "ghi", "jkl",
"mno", "pqrs", "tuv", "wxyz" };
list<string> L;

// recursive function to generate possible words
void  printWordsUtil(int number[], int curr_digit, char output[], int n)
{
	// Base case : when we reach the length of string,n 
	int i;
	if (curr_digit == n)
	{
	//pushing in global list	
		L.push_back(output);
		return;
	}

	// Try all 3 possible characters for current digir in number[]
	// and recur for remaining digits
	for (i = 0; i<strlen(hashTable[number[curr_digit]]); i++)
	{
		output[curr_digit] = hashTable[number[curr_digit]][i];
		printWordsUtil(number, curr_digit + 1, output, n);
		if (number[curr_digit] == 0 || number[curr_digit] == 1)
			return;
	}
}

// A wrapper over printWordsUtil().  It creates an output array and
// calls printWordsUtil()
list<string> printWords(int number[], int n)
{
	char result[max_size] ;
	result[n] = '\0';
	printWordsUtil(number, 0, result, n);
	//auto a = L.begin();
	//for (; a != L.end(); a++){
	//	cout<< a;
	//}
	//for (auto a: L)
	for (list<string>::const_iterator i = L.begin(); i != L.end();++i)
		printf("%s\n",i->c_str());
		//cout << a.begin() << endl;
	return L;
	_getch();
}

//Driver program
int main(void)
{
	int number[] = { 2, 3, 4 };
	int n = sizeof(number) / sizeof(number[0]);
	printWords(number, n);
	return 0;
}