#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node *next;
};

class ll
{
public:
	ll(int arr[],int n);
    node *head = new node;
    node *tail;
	void create(int arr[],int n);
	void display();
	void inserte(int ele,int pos);
	void deletee(int pos);
	int count();

};

int ll::count()
{
	int count = 0;
	node *p = head;
	while(p)
	{
		count++;
		p = p->next;
	}
	return count;
}

void ll::deletee(int pos)
{
	node *temp = head;
	if(pos==0)
	{
		head = head->next;
		free(temp);
	}
	else
	{
		node *p = head;
		for(int i = 0 ; i < pos-2 ; i++)
		{
			p = p->next;
		}
		temp = p->next;
		p->next = p->next->next;
		free(temp);
	}
}

void ll::inserte(int ele,int pos)
{
	node *temp = new node;
	temp->data = ele;
	if(pos==0)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		node *p = head;
		for(int i = 0 ; i < pos-2 ; i++)
		{
			p = p->next;
		}
		temp->next = p->next;
		p->next = temp;
	}
}

void ll::create(int arr[],int n)
{
	node *temp;
	head->data = arr[0];
	head->next = nullptr;
	tail = head;
	for(int i = 1 ; i < n ; i++)
	{
		temp = new node;
		temp->data = arr[i];
		temp->next = nullptr;
		tail->next = temp;
		tail = temp;
	}
}

ll::ll(int arr[],int n)
{
	node *temp;
	head->data = arr[0];
	head->next = nullptr;
	tail = head;
	for(int i = 1 ; i < n ; i++)
	{
		temp = new node;
		temp->data = arr[i];
		temp->next = nullptr;
		tail->next = temp;
		tail = temp;
	}
}

void ll::display()
{
	node *p = head;
	while(p)
	{
		cout<<p->data<<" ";
		p =p->next;
	}cout<<endl;
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);

	int ar[] = {7,6,5,4,3,2,1};
	int m = sizeof(arr)/sizeof(arr[0]);

	ll l(arr,n);
	l.display();
	l.inserte(11,3);
	l.display();
	l.deletee(5);
	l.display();

	cout<<"size of linked list : "<<l.count()<<endl;

	ll k(ar,m);
	k.create(ar,m);
	//k.display();
}
