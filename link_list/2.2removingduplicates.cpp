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

void removingduplicates(struct node *p)
{
	int x = -31221;
	struct node *temp = p ;
	temp = temp->next;
	while(temp!=nullptr)
	{
		if(p->data != temp->data)
		{
			p = temp;
			temp = temp->next;
		}
		else
		{
			p->next = temp->next;
			free(temp);
			temp = p->next;
		}
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

	removingduplicates(first);

	display(first);



	return 0;
}
