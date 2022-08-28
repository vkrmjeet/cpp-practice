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

void insertele(int pos,int ele)
{
	struct node *temp = new node;
	temp->data = ele;
	if(pos==0)
	{
		temp->next = first;
		first->prev = temp;
		temp->prev = nullptr;
		first = temp;
	}
	else
	{
		struct node *p = first;
		for(int i = 0 ; i<pos-2 ; i++)
		{
			p = p->next;
		}
		temp->next = p->next;
		p->next->prev = temp;
		p->next = temp;
	}
}

void deleteele(int pos)
{
	struct node *p = first;
	if(pos==0)
	{
		first = first->next;
		first->prev = nullptr;
		free(p);
	}
	else
	{
		for(int i = 0 ; i<pos-1 ; i++)
		{
			p = p->next;
		}
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
	}
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);

	create(arr,n);
	display(first);

	//insert at first position
	insertele(0,4);
	display(first);

	//inserting in between
	insertele(3,5);
	display(first);

	//deleting first element
	deleteele(0);
	display(first);

	//deleting element at an index
	deleteele(4);
	display(first);


	return 0;
}
