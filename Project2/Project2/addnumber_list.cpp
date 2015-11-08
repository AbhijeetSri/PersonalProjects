#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

struct node{
	int data;
	node* next;
};

struct list{
	node * headnode;
	int size = 0;
};

int main()
{
	
	list l1, l2, sum;

	node n1, n2 ,n3;
	n1.data = 2;
	n2.data = 3;
	n3.data = 4;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = nullptr;
	l1.headnode = &n1; l1.size = 3;

	node a1, a2, a3;
	a1.data = 5;
	a2.data = 9;
	a3.data = 8;
	a1.next = &a2;
	a2.next = &a3;
	a3.next = nullptr;
	l2.headnode = &a1;


	
	node* iterator;
	iterator = l1.headnode;
	cout << "List 1 \n";
	while (iterator != nullptr)
	{
		cout << iterator->data;
		iterator = iterator->next;
	}

	cout << "\nList 2 \n";
	iterator = l2.headnode;
	while (iterator != nullptr)
	{
		cout << iterator->data;
		iterator = iterator->next;
	}

	node* iterator1, *iterator2;
	int carry = 0, s = 0;
//	list sum;
	
	iterator1 = l1.headnode;
	iterator2 = l2.headnode;
	cout << "\n Sum";
	while (iterator1 != nullptr)
	{
		s = iterator1->data + iterator2->data + carry;
		carry = 0;
		if(s > 9)
		{
			carry = s / 10;
		}
		cout << s % 10;
		iterator1 = iterator1->next;
		iterator2 = iterator2->next;
	} cout << carry;
	_getch();
	return 0;
}