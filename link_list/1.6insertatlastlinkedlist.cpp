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
	}
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

int main()
{
	insertlast(4);
	insertlast(6);
	insertlast(8);
	insertlast(10);

	display(first);
	return 0;
}
