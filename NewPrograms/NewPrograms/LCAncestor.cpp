#include<iostream>
#include<conio.h>
using namespace std;

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

//Assuming the nodes n1 and n2 are present in the Bin Search tree !
node* LCancestor(node* n, int n1, int n2)
{
	if (n == nullptr) return nullptr;

	if (n->data > n1 & n->data > n2)
	{
		return LCancestor(n->left, n1, n2);
	}
	if (n->data < n1 & n->data < n2)
	{
		return LCancestor(n->right, n1, n2);
	}
	return n;

}

node* LCA_notbin(node* root, int n1, int n2)
{
	if (root == nullptr)return nullptr;
	
	if (root->data == n1 || root->data == n2) return root;

	node* lnode = LCA_notbin(root->left, n1, n2);
	node* rnode = LCA_notbin(root->right, n1, n2);

	if (lnode && rnode) return root;
	return (lnode == nullptr) ? rnode : lnode;

}

void main()
{
	head = createnode(15);
	head->right = createnode(20);
	head->left = createnode(10);
	head->left->right = createnode(12);
	head->left->left = createnode(8);
	head->left->left->right = createnode(9);
	head->right->right = createnode(25);
	head->right->left = createnode(18);
	head->right->right->right = createnode(30);
	
	//node* newn = LCancestor(head, 18, 30);
	node* newn = LCA_notbin(head, 18, 30);
	cout << newn->data;
	_getch();
}