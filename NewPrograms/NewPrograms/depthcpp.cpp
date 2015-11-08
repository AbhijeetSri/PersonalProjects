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

void insert_node(node** n, int data)
{
	if (*n == nullptr)
	{
		*n = createnode(data);
	}
	else
	{
		if ((*n)->data <= data)
		{
			insert_node(&((*n)->right), data);
			//			return 
		}
		if ((*n)->data > data)
		{
			insert_node(&(*n)->left, data);
		}

	}

}

int min_value(node* root)
{
	int min = -1;
	while (root != nullptr)
	{
		min = root->data;
		root = root->left;
	}
	return min;
}

int max_depth(node* root)
{
	if (root == nullptr) return 0;

	int ld = max_depth(root->left);
	int rd = max_depth(root->right);
		//if (max_depth(root->left) > max_depth(root->right) return
	if (ld > rd) return ld + 1;
	else return rd + 1;

}

void inorder(node* root)
{
	if (root == nullptr) return;
	inorder(root->left);
	cout << root->data << "\t";;
	inorder(root->right);
}


void printPostorder(node* root)
{
	if (root == nullptr) return;
	printPostorder(root->left);
	printPostorder(root->right);
	cout <<root->data<<"\t";
}

// return true if any node to leaf path sum is equal to the given sum
int hasPathSum(node* root, int sum)
{
	if (root == nullptr) return (sum == 0); // at the leaf check if sum is zero
	if (sum < 0) return 0;
	int subsum = sum - root->data;
	return(hasPathSum(root->left, subsum) || hasPathSum(root->right, subsum));
}


void printarray(int* path, int pathlen)
{
	for (int i = 0; i < pathlen; i++)
	{
		cout << "\t" << path[i];
	}
}

void printp(node* root, int* path ,int pathlen )
{
	if (root == nullptr) return;
	path[pathlen] = root->data;
	pathlen++;
	if (root->right == nullptr && root->left == nullptr)
	{
		cout << "\n";
		printarray(path, pathlen);
	}
	else
	{
		printp(root->left, path, pathlen);
		printp(root->right, path, pathlen);
	}
}

void printPaths(node* root)
{
	int pathlen = 0;
	int path[100];
	printp(root, path, pathlen);
}


void mirror(node* root)
{
	if (root == nullptr) return;
	// swap left - right
	node* temp = root->left;
	root->left = root->right;
	root->right = temp;
	//Recur
	mirror(root->left);
	mirror(root->right);
}

void main()
{
	int arr[] = { 5, 2, 4, 1, 6, 3, 4, 8, 9 ,21};
	for (int i = 0; i < 10; i++)
	{ //binary tree
		insert_node(&head, arr[i]);
	}

	int d = max_depth(head);
	int m = min_value(head);
	cout << "\nInorder traversal\n";
	inorder(head);
	cout << "\nPostorder traversal\n";
	printPostorder(head);
	
	int flag = hasPathSum(head, 5);

	//print all path of tree
	printPaths(head);

	mirror(head);
	cout << "\nInorder traversal\n";
	inorder(head);
	cout << "\nPostorder traversal of new tree\n";
	printPostorder(head);	_getch();
}