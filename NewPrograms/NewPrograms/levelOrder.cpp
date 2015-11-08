#include<iostream>
#include<conio.h>
#include<stack>
#include<queue>
using namespace std;
struct node {
	int data;
	node* left;
	node* right;
} *head;

void levelorder(node* n);
void printatlevel(node* n, int level);
int height(node* n);
void zigzaglevel(node* root);

node* createnode(int data)
{
	node *n = new node; // not node n; assigning from heap using pointer
	n->data = data;
	n->left = nullptr;
	n->right = nullptr;
	return n;
}
void levelqueue(node*);


void printatlevel_zigzag(node* n, int level)
{
	if (n == nullptr) return;
	if (level == 0)
		cout << n->data << "\t";
	else if (level >0)
	{
		if (level % 2 == 0){
			printatlevel_zigzag(n->left, level - 1);
			printatlevel_zigzag(n->right, level - 1);
		}
		else
		{
			printatlevel_zigzag(n->right, level - 1);
			printatlevel_zigzag(n->left, level - 1);
		}
	}
}


void main()
{
	head = createnode(15);
	head->right = createnode(10);
	head->left = createnode(9);
	head->left->right = createnode(12);
	head->left->left = createnode(7);
	head->right->right = createnode(24);
	head->right->left = createnode(21);
	head->right->left->left = createnode(15);
	head->right->left->right = createnode(51);
	head->right->right->left = createnode(22);
	head->right->right->right = createnode(11);
	head->right->right->left->left = createnode(32);
	head->right->right->right->right = createnode(51);

	//levelorder(head);
	//levelqueue(head);
	cout << "\n Zigzag traversal \n";
	//zigzaglevel(head);
	levelorder(head);
	_getch();
}

void levelqueue(node* n)
{

	node* q[50];
	node* current_node, *element;
	int start = 0, tail = 0;
	q[start] = head;
	cout << "\n";
	do
	{
	//deque
	current_node = q[start];
	start++;
	if (current_node != nullptr)
	{
		cout << current_node->data <<"\t";
		// enque
		if(current_node->left != nullptr) q[++tail] = current_node->left;
		if (current_node->right != nullptr) q[++tail] = current_node->right;
	}

	} while (start <= tail);


	/*q[start] = n;
	cout << n->data;
	q[tail++] = n->left;
	q[tail++] = n->right;*/
	
}


int height(node* n)
{
	if (n == nullptr)
		return 0;
	int l = height(n->left);
	int r = height(n->right);
	if (l > r)return(l + 1);
	else
		return (r + 1);
}

void levelorder(node * n){

	int h = height(n);
	for (int i = 0; i < h; i++)
	{
		cout << "\nLevel: "<<i << "\n";
		//printatlevel(n, i);
		printatlevel_zigzag(n, i);
	}
}

void printatlevel(node* n, int level)
{
	if (n == nullptr) return ;
	if (level == 0)
		cout << n->data <<"\t";
	else if (level >0 )
	{
		printatlevel(n->left, level - 1);
		printatlevel(n->right, level - 1);
	}
}


void zigzaglevel(node* head)
{
	stack<node*> S;
	queue<node*> Q;
	node* n = new node;
	int level = 0;

	if (head == nullptr) return;
	Q.push(head);

	while (!Q.empty() || !S.empty())
	{
		while (!Q.empty())
		{
			n = Q.front();
			Q.pop();
			cout << n->data << "\t";
			if (level == 0)	
			{
				if (n->left != nullptr) S.push(n->left);
				if (n->right != nullptr) S.push(n->right); 
			}
			else if (level == 1){
				if (n->right != nullptr) S.push(n->right);
				if (n->left != nullptr) S.push(n->left);
			}

		}
		level == 0 ? level = 1 : level = 0;
		cout << "\n";
		while (!S.empty())
		{
			n = S.top(); S.pop();
			Q.push(n);
			//if (n->left != nullptr) Q.push(n->left);
			//if (n->right != nullptr) Q.push(n->right);
		}
	}
	free(n);
	return;
}