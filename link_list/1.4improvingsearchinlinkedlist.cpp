#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*first;

void create(int arr[], int size)
{
	first = new node;
	first->data = arr[0];
	first->next = nullptr;
	struct node *last,*temp;
	last = first;

	for(int i = 1 ; i < size ; i++)
	{
		temp = new node;
		temp->data = arr[i];
		temp->next = nullptr;
		last->next = temp;
		last = temp;
	}
}

void display(struct node *p)
{
	while(p!=nullptr)
	{
		cout<<p->data<< " ";
		p = p->next;
	}cout<<endl;
}

node * searchnode(struct node *p, int n)
{
	struct node *last;
	while(p!=nullptr)
	{
		if(p->data!=n)
		{
			last = p;
			p = p->next;
		}
		else
		{
			last->next = p->next;
			p->next = first;
			first = p;
			return p;
		}
	}
	return p;
}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,7};
	int n = sizeof(arr)/sizeof(arr[0]);

	create(arr,n);

	display(first);

	struct node *res = searchnode(first,5);

	display(first);


	return 0;
}
