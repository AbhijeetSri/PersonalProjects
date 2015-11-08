#include<iostream>
#include<conio.h>
using namespace std;
const int INF = 99999;
const int MINUSINF = -99998;
struct node{
	int data;
	node* left;
	node* right;
} nhead;

node* createnode(int data)
{
	node *n = new node; // not node n; assigning from heap using pointer
	n-> data = data;
	n-> left = nullptr;
	n->right = nullptr;
	return n;
}

void insert(node ** root, int data)
{
	if (*root == nullptr)
	{
		*root = createnode(data); // for head case
		return;
	}

	if (data < (*root)->data)
	{
		if ((*root)->left == nullptr){
			(*root)->left = createnode(data);
			return;
		}
		else insert(&(*root)->left, data);
	}
	if (data > (*root)->data)
	{
		if ((*root)->right == nullptr){
			(*root)->right = createnode(data);
			return;
		}
		else insert(&(*root)->right, data);
	}
	
}


void inorder(node * n)
{
//	if (n->left == nullptr) return;
//	if (n->right == nullptr) return;
	if (n == nullptr)return;
	inorder(n->left);
	cout << n->data << "\t";
	inorder(n->right);
	//return;
}


void postorder(node* n)
{
	if (n == nullptr)return;
	postorder(n->left);
	postorder(n->right);
	cout << n->data <<"\t";
}

bool check_bst(node* nd)
{
	if (nd == nullptr) return true;

//	int min = nd->left->data == nullptr ? ;
	int min = 0, max = 0;
	nd->left == nullptr ? min = MINUSINF : min = nd->left->data;
	nd->right == nullptr ? max = INF : max = nd->right->data;
	
	//int max = nd->right->data;

	if (nd->data < min || nd->data > max)
	{
		return false;
	}
	else
	{
		return (
			check_bst(nd->left) &&
			check_bst(nd->right));
	}
	
}

void main()
{
	int a[] = { 43, 3, 4, 5, 23, 5, 34, 3 };// int res;
	node* n = nullptr;
	for (int i = 0; i < 8; i++)
	{
			insert(&n, a[i]);
	}
	cout << "Inorder traversel \n";
	inorder(n);
	cout << "\nPostorder traversel \n";
	postorder(n);


	node *nhead = createnode(15);
/*nhead->right = createnode(10);
nhead->left = createnode(10);
nhead->left->right = createnode(12);
nhead->right->right = createnode(24);
nhead->right->right->left = createnode(22);*/
bool res = check_bst(nhead);

_getch();

}