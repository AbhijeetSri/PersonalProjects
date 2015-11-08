#include<iostream>
#include<conio.h>
using namespace ::std;
class node
{
private:
	int key;
	node * left;
	node * right;

public:
	node(){ key = -1; left = NULL; right = NULL; }
	void addkey(int akey){ key = akey; }
	void addleft(node* aleft){ left = aleft; }
	void addright(node* aright){ right = aright; }
	int Key(){ return key; }
	node* Left(){ return left; }
	node* Right(){ return right; }
};

class tree
{
	node* root;
public:


	node* root(){ return root; }
	void addnode(int key);
	void inorder(node* n);

private:
	void addnode(int key, node* leaf);

};
int main()