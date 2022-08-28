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

int count(struct node *p)
{
	int count = 0;
	while(p!=nullptr)
	{
		count++;
		p = p->next;
	}
	return count;
}

bool issorted(struct node *p)
{
	int x = -23020;
	while(p!=nullptr)
	{
		if(x>p->data)
			return false;
		x = p->data;
		p = p->next;
	}
	return true;
}

int main()
{
	insertlast(3);
	insertlast(4);
	insertlast(5);
	insertlast(2);
	insertlast(9);

	display(first);

	bool issort = issorted(first);

	issort ? cout<< "link list is sorted" : cout<< "link list is not sorted";

	return 0;
}
