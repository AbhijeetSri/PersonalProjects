#include<iostream>
#include<conio.h>
using namespace std;

class node 
{
private:
	int data;
	node *nextnode;

public:
	node()
	{	data = 0;
		nextnode = nullptr;
	}
	node(int n)
	{
		data = n;
		nextnode = nullptr;
	}
	int getdata()
	{
		return data;
	}
	void setdata(int d)
	{
		data = d;
	}

	node* getnext()
	{
		if (nextnode == nullptr)
			return nullptr;
		return nextnode;
	}
	void setnext(node* t)
	{
		nextnode = t;
	}
};
class list
{
	node* Head;
	int size;
public:
	list(){
		Head = nullptr;
		size = 0;
	}
	void showlist()
	{
		node * iterator = Head;
		cout << "List Size: " << size << "\n";
		if (iterator == nullptr)return;
		while (iterator->getnext() != nullptr)
		{
			cout << iterator->getdata()<<"\t";
			iterator = iterator->getnext();
		}
		cout << iterator->getdata() << "\t";
		cout << "\n";
	}
	void addtoend(int data)
	{
		node *temp = new node(data);
		//node temp;
		
		if (size == 0){
			size = 1;
			Head = temp;
			return;
		}
		node * iterator = Head;
		while (iterator->getnext() != nullptr)
		{
			iterator = iterator->getnext();
		}
		iterator->setnext(temp);
		size++;
	}
	~list(){
		node * temp;
		while (Head != nullptr){
			temp = Head;
			Head = Head->getnext();
			delete temp;
		}
	}
	void deletenode(int d)
	{
		if (Head == nullptr) return;
		node * iterator = Head;
		while (iterator->getnext() != nullptr)
		{
			if (iterator->getnext()->getdata() == d){
				iterator->setnext(iterator->getnext()->getnext());
				size--;
				}
			iterator = iterator->getnext();
		}
	}
	void deletenode(node* n)
	{
		node* iterator = Head;
		if (iterator == nullptr) return;
		while (iterator->getnext() != nullptr)
		{
			if (iterator->getnext() == n)
			{
				iterator->setnext(n->getnext());
				size--;
			}
			iterator = iterator->getnext();
		}
	}
	void remove_dup()
	{
		node* it1 = Head;
		node *it2 = Head;
		if (Head == nullptr) return;
		while (it1->getnext() != nullptr)
		{
			it2 = it1->getnext();
			while (it2->getnext() != nullptr)
			{
				if (it1->getdata() == it2->getdata())
				{
					deletenode(it2);
				}
				it2 = it2->getnext();
			}
			it1 = it1->getnext();
		}
	}

	void nth2last(int n)
	{
		int count = 0;
		if (size < n) {
			cout << "\n Size is less than required"; return;
		}
		node* iterator = Head;
		if (iterator == nullptr)return;
		cout << "\nList Elements: "<<n<<" to last \n";
		while (iterator->getnext() != nullptr)
		{
			count++;
			if (count >= n)
			{
				cout << iterator->getdata() << "\t";
			}
			iterator = iterator->getnext();
		}
		cout << iterator->getdata() << "\t";
	}

	void del_one_node(node* n)
	{
		// delete a node given access to only that node 
		if (n->getnext() == nullptr) { cout << "\n Last node, trouble."; return; }
		n->setnext(n->getnext()->getnext());
		n->setdata(n->getnext()->getdata());	// replace data with that of next node
	}

	void delete_middle()
	{
		node * slow = Head;
		node * fast = Head;
		fast = fast->getnext();
		while (fast->getnext() != nullptr || fast != nullptr)
		{
			slow = slow->getnext();
			fast = fast->getnext()->getnext();
		}
		cout << "\n Reached Middle.. deleting..\n";
		slow->setnext(slow->getnext()->getnext());

		showlist();
	}
	};


	void sum_list(list L1, list L2)
	{
		L1.showlist();
		L2.showlist();

	}

	int	sum_carry(int a, int b, int carry)
	{
		if (a + b > 9)
		{
			return((a + b) % 10);
			//carry = 
		}
	}
int main()
{
	list L,L1, sum;
	for (int i = 1; i <= 5; i += 2)
	{
		L.addtoend(i);
		L1.addtoend(i + 1);
	}
	L.showlist();
	L1.showlist();
	L.delete_middle();
	//L.addtoend(3);
	//L.addtoend(15);
	//L.showlist();
	//L.remove_dup();
	//L.nth2last(3);
	//L.showlist();
	//L.deletenode(3);
	//L.showlist();
	int s = 0;
	//delete_middle(L);
	_getch();
}
