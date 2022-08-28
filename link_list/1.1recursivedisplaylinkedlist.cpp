#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*first;

void create(int arr[],int n)
{
	struct node *last,*temp;
	first = new node;
	first->data = arr[0];
	first->next = NULL;
	last = first;

	for(int i = 1 ; i<n ; i++)
	{
		temp = new node;
		temp->data = arr[i];
		temp->next = NULL ;
		last->next = temp;
		last = temp;
	}
}

void display(struct node *p)
{
	if(p!=NULL)
	{
		display(p->next);
	    cout<<p->data;
	}
}

int main()
{
	int arr[] = {1,3,2,4,2,3,4,2,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	create(arr,n);

	display(first);
}
