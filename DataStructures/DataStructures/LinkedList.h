#include "stdafx.h"

using namespace std;



class LinkedList
{
private:
	struct Node
	{
		string name;
		int number;
		struct Node *next;
	};

	Node *head;

public:
	LinkedList()
	{
		head = NULL;
	}
	void addLast(string, int);
	void Insert(string, int);
	void Delete(string);
	void Display() const;
	string find(int);
};
