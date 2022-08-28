#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*first;

void create(int a[], int n)
{
	struct node *last,*temp;
	first = new node;
	first->data = a[0];
	first->next = nullptr;
	last = first;

	for(int i = 1 ; i < n ; i++)
	{
		temp = new node;
		temp->data = a[i];
		temp->next = nullptr;
		last->next = temp;
		last = temp;
	}
}

void display(struct node *p)
{
	while(p!=nullptr)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
}

void countnodes(struct node *p)
{
	int count = 0;
	while(p!=NULL)
	{
		count++;
		p = p->next;
	}
	cout<< "\nNumber of nodes are : "<< count<<endl;
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	create(arr,n);

	display(first);

	countnodes(first);

	return 0;
}
