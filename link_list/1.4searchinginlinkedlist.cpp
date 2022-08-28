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
	}
}

node * searchnode(struct node *p, int n)
{
	while(p!=nullptr)
	{
		if(p->data==n)
		{
			return p;
		}
		else
			p=p->next;
	}
	return nullptr;
}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,7};
	int n = sizeof(arr)/sizeof(arr[0]);

	create(arr,n);

	display(first);

	struct node *res = searchnode(first,7);

	if(res)
	{
		cout<<"key in found";
	}
	else
	{
		cout<<"key is not found";
	}

	return 0;
}
