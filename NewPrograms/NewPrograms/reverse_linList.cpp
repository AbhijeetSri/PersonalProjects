#include<iostream>
#include<conio.h>
using namespace std;

struct node{
	int data;
	node* next;
} *head;

node* reverse(node* curr, node* prev)
{
	if (curr->next == nullptr)
	{
		curr->next = prev;
		return curr;
	}
	node* n = reverse(curr->next, curr);
	curr->next = prev;
	//n->next = prev;
	return n;
}

node* reverse_list(node* head)
{
	node * head1 = reverse(head->next, head);
	head->next = nullptr;
	return head1;
}


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

void main()
{
	// populate list
	node* head = createnode(1);
	appendtolist(23, head);
	appendtolist(26, head);
	appendtolist(12, head);
	appendtolist(32, head);
	appendtolist(10, head);
	head = reverse_list(head);
	_getch();

}