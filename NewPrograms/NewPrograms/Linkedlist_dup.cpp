#include<iostream>
#include<conio.h>
#include<map>
using namespace std;

struct node{
	int data;
	node* next;
} *head;

node* createnode(int data)
{
	node* n = new node;
	n->data = data;
	n->next = nullptr;
	return n;
}

void appendtolist(int data, node* head)
{
	node* it = head;
	while (it->next != nullptr)
	{
		it = it->next;
	}
	//n = createnode(data);
	it->next = createnode(data);

}

void dup_linklist(node* head)
{
	node* it = head;
	map <int, int> mymap;

	while (it != nullptr)
	{
		// insert in map .. node value, 1
		//mymap[it->data]
		//auto i = mymap.find(it->data);
		if (mymap.find(it->data) == mymap.end())
			//mymap.insert(std::pair<int,int>(it->data,1));
			mymap[it->data] = 1;
		else
		{
			cout << "dup found for " << it->data;
		}
		// if key found return value
		it = it->next;

	}
}


void main()
{
	// populate list
	node* head = createnode(1);
	appendtolist(23, head);
	appendtolist(10, head);
	appendtolist(12, head);
	appendtolist(32, head);
	appendtolist(10, head);
	dup_linklist(head);
	_getch();

}