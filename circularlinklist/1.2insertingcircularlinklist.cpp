#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*head;

void create(int arr[],int size)
{
	head = new node;
	head->data = arr[0];
	head->next = head;
	struct node *last = head;

	for(int i = 1 ; i<size ; i++)
	{
		struct node *temp = new node;
		temp->data = arr[i];
		temp->next = head;
		last->next = temp;
		last = temp;
	}
}

void display(struct node *p)
{
	do{
		cout<<p->data<<" ";
		p = p->next;
	}while(p!=head);cout<<endl;
}

void rdisplay(struct node *p)
{
	static int flag = 0;
	if(p!=head || flag==0)
	{
		flag=1;
		cout<<p->data<<" ";
		rdisplay(p->next);
	}cout<<endl;
	flag=0;
}

void insertathead(int x)
{
	struct node *p = head;
	struct node *temp = new node;
	temp->data = p->data;
	temp->next = p->next;
	p->data = x;
	p->next = temp;
}

void insertatposition(int x,int pos)
{
	struct node *p = head;
	struct node *temp ;
	for(int i = 0 ; i<pos-2 ; i++)
	{
		p=p->next;
	}
	temp = new node;
	temp->data = x;
	temp->next = p->next;
	p->next = temp;
}

void deleteele(int x)
{

}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,6,8};
	int n = sizeof(arr)/sizeof(arr[0]);

	create(arr,n);

	display(head);

	insertatposition(22,3);

	display(head);

	insertathead(12);

	rdisplay(head);
}
