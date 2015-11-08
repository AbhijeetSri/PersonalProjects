#include<iostream>
#include<conio.h>
using namespace std;
  
struct node{
	node* left;
	node* right;
	int data;
};


node* createnode(int data)
{
	node* n = new node;
	n->data = data;
	n->left = nullptr;
	n->right = nullptr;
	
	return n;

}

void insert_node(node** n, int data)
{
	if (*n == nullptr)
	{
		/*node new_node;
		new_node.data = data;
		new_node.right = nullptr;
		new_node.right = nullptr;*/
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


void main()
{
	node* root = createnode(3);
	 insert_node(&root, 4);
	 insert_node(&root, 1);
	insert_node(&root, 2);



}