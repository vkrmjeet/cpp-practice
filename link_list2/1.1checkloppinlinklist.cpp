#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*first,*last,*loopstart;

void insertlast(int x)
{
	struct node *temp;
	temp = new node;
	temp->data = x;
	temp->next = nullptr;
	if(first==nullptr)
	{
		first = temp;
		last = first;
	}
	else
	{
		last ->next = temp;
		last = temp;
		last->next = loopstart;
	}
}

void insertloopstart(int x)
{
	struct node *temp;
	temp = new node;
	temp->data = x;
	temp->next = nullptr;
	last->next = temp;
	last = temp;

	loopstart = last;
}

void display(struct node *p)
{
	while(p!=nullptr)
	{
		cout<<p->data<<" ";
		p = p->next;
	}cout<<endl;
}

bool checkloop(struct node *p)
{
	bool res = false;
	struct node *q = first;
	while(p && q)
	{
		p = p->next;
		q = q!=nullptr ? q=q->next : q=nullptr ;
		q = q->next;
		if(p==q)
		{
			return false;
		}
	}return true;
}

int main()
{
	insertlast(3);
	insertloopstart(5);
	insertlast(8);
	insertlast(9);
	insertlast(11);
	insertlast(14);

	//one more method to make a loop is storing nodes in pointers t1 = first->next->next; t2 = first->next->next->next->next->next->next; t2->next = t1;

	bool isloop = checkloop(first);

	isloop==false ? cout<< "there is a loop in the link list" : cout<<"there is no loop in the link list " ;


	return 0;
}
