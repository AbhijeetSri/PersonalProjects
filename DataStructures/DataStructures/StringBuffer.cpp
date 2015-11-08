#include "stdafx.h"
#include "StringBuffer.h"

using namespace std;

void StringBuffer::append(string str)
{
	int size = sizeof(str);
	if (size == 0)
		return;

	/* creating a new node and setting its values */
	Node *newNode = new Node;
	newNode->sPtr = new string(str);
	newNode->next = NULL;
	numStrings++;
	totalLength = sizeof(str);

	if (head == NULL)
	{
		head = newNode;
		return;
	}
	else
	{
		Node *nodePtr = head;
		while (nodePtr->next != NULL)
			nodePtr = nodePtr->next;
		nodePtr->next = newNode;
	}
}

int StringBuffer::length()
{
	return totalLength;
}

int StringBuffer::numOfStrings()
{
	return numStrings;
}

/* delete all nodes and empty the linked list */
void StringBuffer::reset()
{
	Node *nodePtr = head, *nextNode = NULL;
	while (nodePtr != NULL)
	{

		nextNode = nodePtr->next;
		delete(nodePtr);
		nodePtr = nextNode;
	}
	head = NULL;
}

string StringBuffer::toString()
{
	if (head == NULL)
		return NULL;
	char *cPtr = new char[totalLength + 1];
	Node *nodePtr = head;
	int index = 0;
	while (nodePtr != NULL)
	{
		strcpy(cPtr+index, (*(nodePtr->sPtr)).c_str());
		index = index + (*(nodePtr->sPtr)).length();
		nodePtr = nodePtr->next;
	}
	return string(cPtr);
}