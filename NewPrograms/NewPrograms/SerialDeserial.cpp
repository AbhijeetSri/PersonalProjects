#include<iostream>
#include<conio.h>
using namespace std;
const int SIZE = 6;
struct node {
	int data;
	node* left;
	node* right;
} *head;

node* createnode(int data)
{
	node *n = new node; // not node n; assigning from heap using pointer
	n->data = data;
	n->left = nullptr;
	n->right = nullptr;
	return n;
}

node* maketree(int arr[], int pos)
{
	if (pos >= SIZE) return nullptr;
	node* n = createnode(arr[pos]);
	if (2 * (pos+1) -1 <= SIZE) n->left = maketree(arr, 2 * (pos + 1) - 1);
	if (2*(pos+1) <= SIZE) n->right = maketree(arr, 2 * (pos + 1));
	return n;
}

int size(node* n)
{
	if (n == nullptr) return 0;
	else
	{
		return(size(n->left) + 1 + size(n->right));
	}
}

void main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };// , 7, 8, 9, 10};
	node*n;
	n = maketree(arr, 0);
	head = n;
	int s = size(head);
	_getch();
}

