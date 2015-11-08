#include "stdafx.h"

using namespace std;

class StringBuffer
{
private:
	struct Node
	{
		Node *next;
		string *sPtr;
	};

	Node *head;
	int totalLength;
	int numStrings;

public:
	StringBuffer()
	{
		head = NULL;
		totalLength = 0;
		numStrings = 0;
	}
	void append(string str);
	string toString();
	int length();
	int numOfStrings();
	void reset();
};