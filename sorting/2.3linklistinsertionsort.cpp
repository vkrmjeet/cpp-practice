#include<iostream>
using namespace std;

struct node
{
	struct node *prev;
	int data;
	struct node *next;
}*first,*last;

void display(struct node *t);

void insertionsort(struct node *t)
{
	t = t->next;
	struct node *temp;
	int x;
	while(t)
	{
		cout<<"working"<<t->data<<endl;
		x = t->data;
		temp = t->prev;
		while(temp !=nullptr && temp->data > x)
		{
			cout<<"innerloopworking"<<temp->data<<endl;
			temp->next->data = temp->data;
			if(temp->prev!=nullptr)
			{
				temp = temp->prev;
			}
			else
			{
				break;
			}
		}
		cout<<"endofloop ";display(first);
		temp->data = x;
		t = t->next;
	}

}

void create(int x)
{
	struct node *temp ;
	temp = new node;
	temp->data = x;
	temp->next = temp->prev =  nullptr;
	if(first!=nullptr)
	{
		last->next = temp;
		temp->prev = last;
		last = temp;
	}
	else
	{
		first = last = temp;
	}
}

void display(struct node *t)
{
	while(t)
	{
		cout<<t->data<<" ";
		t = t->next;
	}cout<<endl;
}

int main()
{
	create(8);
	create(7);
	create(5);
	create(3);
	create(2);

	display(first);

	insertionsort(first);

	display(first);


	return 0;
}
