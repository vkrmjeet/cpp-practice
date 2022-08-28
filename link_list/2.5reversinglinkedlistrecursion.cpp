#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*first,*last;


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

void reversinglist(struct node *q,struct node *p)
{
		if(p!=nullptr)
		{
			reversinglist(p,p->next);
			p->next = q;
		}
		else
		{
			first = q;
		}

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

	reversinglist(nullptr,first);

	display(first);



	return 0;
}
