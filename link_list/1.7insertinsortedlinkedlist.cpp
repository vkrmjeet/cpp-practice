
#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*first,*last;

void display(struct node *p)
{
	while(p!=nullptr)
	{
		cout<<p->data<< " ";
		p = p->next;
	}cout<<endl;
}

void insertlast(int x)
{
	struct node *temp = new node;
	temp->data = x;
	temp->next = nullptr;

	if(first==nullptr)
	{
		first=last=temp;
	}
	else
	{
		last->next = temp;
		last = temp;
	}
}

void insertsortedlinkedlist(int x)
{
	struct node *temp = new node;
	temp->data = x;
	struct node *p = first;
	struct node *last = first;
	while(p!=nullptr)
	{
		if(p->data<x)
		{
			last = p;
			p = p->next;
		}
		else
		{
			last->next = temp;
			temp->next = p;
			return ;
		}
	}
}

int main()
{
	insertlast(4);
	insertlast(6);
	insertlast(8);
	insertlast(10);

	display(first);

	insertsortedlinkedlist(7);

	display(first);
	return 0;
}
