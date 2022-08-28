#include<iostream>
using namespace std;

class node
{
	int data;
	node *next;
};

class linkedlist
{
private:
	node *first;
public:
	linkedlist()
	{
		first = nullptr;
	}
	linkedlist(int arr[],int n);
	~linkedlist();

	void display();
	int inserte(int index,int x);

	int delete(int index);
	int length();
};

linkedlist::linkedlist(int arr[],int n)
{
	node *last,*t;
	first = new node;
	first->data = arr[0];
	first->next = nullptr;
	last = first;

	for(int i = 1 ; i<n ; i++)
	{
		t = new node;
		t->data = arr[i];
		t->next = nullptr;

		last->next = t;
		last = t;
	}
}

int linkedlist::length()
{
	int count = 0;
	node *p = first;
	while(p)
	{
		count++;
		p = p->next;
	}
	return count;
}

linkedlist::inserte(int index,int x)
{
	if(index<0 || index>length())
	{
		return ;
	}
	node *temp=new node;
	temp->data = x;
	if(index==0)
	{
		temp->next = first;
		first = temp;
	}
	else
	{
		node *laste,*inde = new node;
		laste = inde = first;
		for(int i = 1; i<index-2 ; i++)
		{
			laste = laste->next;
		}
		inde = laste;
		inde = inde->next;
		laste->next = temp;
		temp->next = inde;
	}
}

linkedlist::display()
{
	node *p = first;
	while(p!=nullptr)
	{
		cout<<p->data<<" ";
		p = p->next;
	}cout<<endl;
}

linkedlist::~linkedlist()
{
	node *p = first;
	while(first)
	{
		first = first->next;
		free(p);
		p = first;
	}
}

int main()
{
	int arr[] = {1,2,4,6,7,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	linkedlist ll(arr,n);

	ll.display();


	return 0;
}
