#include<iostream>
using namespace std;

struct node
{
	struct node *prev;
	int data;
	struct node *next;
}*first;

void create(int a[],int n)
{
	struct node *temp,*last;
	first = new node;
	first->prev = nullptr;
	first->data = a[0];
	first->next = nullptr;
	last = first;
	for(int i = 1 ; i < n  ; i++)
	{
		temp = new node;
		temp->prev = last;
		temp->data = a[i];
		temp->next = nullptr;
		last->next = temp;
		last = temp;
	}
}

void display(struct node *p)
{
	while(p)
	{
		cout<<p->data<<" ";
		p = p->next;
	}cout<<endl;
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);

	create(arr,n);
	display(first);
}
