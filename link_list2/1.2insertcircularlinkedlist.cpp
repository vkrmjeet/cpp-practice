#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*first;

void create(int a[],int n)
{
	struct node *temp,*last;
	first = new node;
	first->data = a[0];
	first->next = first;
	last = first;
	for(int i = 1 ; i<n ; i++)
	{
		temp = new node;
		temp->data = a[i];
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
}

void display(struct node *p)
{
	do
	{
		cout<<p->data<<" ";
		p = p->next;
	}while(p!=first);
	cout<<endl;
}

void insertele(int ele , int pos)
{
	struct node *temp,*last;
	temp = new node;
	temp->data = ele;
	if(pos==0)
	{
		temp->data = first->data;
		temp->next = first->next;
		first->data = ele;
		first->next = temp;
	}
	else
	{
		last = first;
		for(int i = 0 ; i<pos-2; i++)
		{
			last = last->next;
		}
		temp->next = last->next;
		last->next = temp;
		display(first);
	}
}

void deleteele(int pos)
{
	struct node *temp;
	if(pos==0)
	{
		first->data = first->next->data;
		temp = first->next;
		first->next = temp->next;
		delete temp;
	}
	else
	{
		struct node *p = first;
		for(int i = 0 ; i<pos-2 ; i++)
		{
			p = p->next;
		}
		temp = p->next;
		p->next = temp->next;
		delete temp;
	}
}

int main()
{
	int arr[] = {2,1,4,3,6,5};
	int n = sizeof(arr)/sizeof(arr[0]);

	create(arr,n);
	display(first);

	insertele(11,0);
	display(first);

	deleteele(3);
	display(first);

}
