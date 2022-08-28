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

void insertt(int x)
{
	struct node *temp = new node;
	temp->data = x;
	temp->next = nullptr;
	if(second==nullptr)
	{
		second=last=temp;
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
	if(p==nullptr)
	{
		return ;
	}
	else
	{
		reversinglist(p->next);
		insertt(p->data);
		free(p);
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

	reversinglist(first);

	display(second);



	return 0;
}
