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

int countnodes(struct node *p)
{
	int count = 0;
	while(p!=nullptr)
	{
		count++;
		p = p->next;
	}
	return count;
}

void insertnode(struct node *p,int position,int element)
{
	struct node *temp;
	temp = new node;
	temp->data = element;

	if(position==0)
	{
		temp->next = first;
		first = temp;
		return;
	}
	else if(p>0)
	{
		for(int i = 1 ; i<position-1 && p ; i++)
		{
			p=p->next;
		}
		if(p)
		{
			temp->next=p->next;
			p->next = temp;
			return;
		}
	}
}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,7};
	int n = sizeof(arr)/sizeof(arr[0]);

	create(arr,n);

	display(first);
	int count = 0,pos =0 , ele = 0;
	count = countnodes(first);
	cout<< " total number of nodes "<<count<<endl;
	cout<< "Enter a position to insert new node : ";
	cin>>pos;
	cout<< "enter the value of the node : ";
	cin>>ele;

	insertnode(first,pos,ele);

	display(first);
	return 0;
}
