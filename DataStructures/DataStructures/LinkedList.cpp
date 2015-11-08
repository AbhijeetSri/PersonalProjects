#include "stdafx.h"
#include "LinkedList.h"
using namespace std;

void LinkedList::addLast(string data1, int data2)
{
	Node *newNode;
	Node *nodePtr;

	newNode = new Node;
	newNode->name = data1;
	newNode->next = NULL;
	newNode->number = data2;

	if (head == NULL)
		head = newNode;
	else
	{
		nodePtr = head;
		while (nodePtr->next != NULL)
			nodePtr = nodePtr->next;
		nodePtr->next = newNode;
	}
}

void LinkedList::Delete(string data1)
{
	Node *nodePtr;
	Node *prevNode;

	if (head == NULL)
		return;

	nodePtr = head;

	if ((nodePtr->name.compare(data1) == 0)) //&& nodePtr->number == data2) // first node needs to be deleted
	{
		head = head->next;
		delete nodePtr;
		// code to delete nodePtr node i.e. to free its memory
	}
	else
	{
		prevNode = nodePtr;
		nodePtr = nodePtr->next;
		while (nodePtr != NULL)
		{
			if (nodePtr->name.compare(data1) == 0)// && nodePtr->number == data2)
			{
				prevNode->next = nodePtr->next;
				delete nodePtr;  	// code to delete node i.e. to free its memory
			}
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}
	}
}

void LinkedList::Display() const
{
	Node *nodePtr;
	nodePtr = head;

	if (head == NULL)
		cout << "List is empty." << endl;

	while (nodePtr != NULL)
	{
		if (nodePtr != head)
			cout << " --> ";
		cout << nodePtr->name << "," << nodePtr->number;
		nodePtr = nodePtr->next;
	}
	if (head != NULL)
		cout << endl;
}


string LinkedList::find(int data)
{
	Node *nodePtr;
	nodePtr = head;

	if (head == NULL)
		cout << "List is empty." << endl;

	while (nodePtr != NULL)
	{
		if (nodePtr->number == data)
			return nodePtr->name;
		nodePtr = nodePtr->next;
	}
	return NULL;
}