#include<iostream>
#include <stdio.h>
#include <string.h>
#include<conio.h>
#include<algorithm>
#include<list>
using namespace std;

const int max_size = 100;
// key pad to phone_num mapping global hash
const char hashT[10][5] =
{ " ", // taking space for 0 and 1 .. 
"  ",
"abc",
"def",
"ghi",
"jkl",
"mno",
"pqrs",
"tuv",
"wxyz" };

// global list to store the string patern
list<string> L;

// recursive function to generate possible words
void  genCombfromHash(int phone_num[], int dig_num, char output[], int n)
{
	// Base case-> 
	//when we reach the length of string,n 
	int i;
	if (dig_num == n)
	{
		//pushing in global list	
		L.push_back(output);
		return;
	}

	//possible combnation
	for (i = 0; i<strlen(hashT[phone_num[dig_num]]); i++)
	{
		// populate the string from hash table
		output[dig_num] = hashT[phone_num[dig_num]][i];
		//call function
		genCombfromHash(phone_num, dig_num + 1, output, n);
		// return for 0 and 1s
		if (phone_num[dig_num] == 0 || phone_num[dig_num] == 1)
			return;
	}
}

// wrapper 
list<string> printCombination(int phone_num[], int n)
{
	char end_output[max_size];
	end_output[n] = '\0';
	genCombfromHash(phone_num, 0, end_output, n);
	for (list<string>::const_iterator i = L.begin(); i != L.end(); ++i)
		printf("%s\n", i->c_str());
	// returning global list
	return L;
	
}

//main
int main()
{
	// main test case
	int phone_num[] = { 2, 3 };

	//Other test cases :
	//int phone_num[] = {0,5,6,4};
	//int phone_num[] = { 0 ,2}; 
	//int phone_num[] = {NULL};
	//int phone_num[] = { -2,12 };

	int n = sizeof(phone_num) / sizeof(phone_num[0]);
	printCombination(phone_num, n);
	_getch();
	return 0;
}