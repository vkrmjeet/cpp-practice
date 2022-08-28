#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*first,*last,*second;


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

void display(struct node *p)
{
	while(p!=nullptr)
	{
		cout<<p->data<<" ";
		p=p->next;
	}cout<<endl;
}

void reversinglist(struct node *p)
{
	struct node *q,*r = nullptr;

	while(p!=nullptr)
	{
		q = r;
		r = p;
		p=p->next;
		r->next = q;
	}
	first = r;
}

int main()
{
	insertlast(2);
	insertlast(2);
	insertlast(4);
	insertlast(5);
	insertlast(5);
	insertlast(5);
	insertlast(5);
	insertlast(9);

	display(first);

	reversinglist(first);

	display(first);



	return 0;
}
