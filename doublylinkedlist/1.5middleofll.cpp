#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*first;

void create(struct node *p,int a[],int n)
{
	struct node *last,*temp;
	p = new node;
	p->data = a[0];
	p->next = nullptr;
	last=first = p;
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
		cout<<p->data<< " ";
		p = p->next;
	}cout<<endl;
}

void middleofll(struct node *p)
{
	struct node *q = p;
	while(p->next!=nullptr)
	{
		p = p->next->next;
		q = q->next;
		if(p->next==nullptr)
		{
			cout<<"middle of link list is : "<<q->data;
		}
	}
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);

	create(first,arr,n);
	display(first);

	cout<<endl;
	cout<<endl;

	middleofll(first);

	return 0;
}
