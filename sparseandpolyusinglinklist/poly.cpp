#include<iostream>
using namespace std;

struct node
{
	int coe;
	int exp;
	struct node *next;
}*first,*second,*third;

void display();

void create()
{
	int m,i;
	cout<<" enter the number terms : ";
	cin>>m;
	first = new node;
	cout<<" enter coefficient : ";
	cin>>first->coe;
	cout<<"enter exponent : ";
	cin>>first->exp;
	struct node *last ;
	last = first;
	for(int i = 1 ; i<m ; i++)
	{
		struct node *temp = new node;
		cout<<" enter coefficient : ";
	    cin>>temp->coe;
		cout<<"enter exponent : ";
		cin>>temp->exp;
		temp->next = nullptr;
		last->next = temp;
		last = temp;
	}
}

void display()
{
	struct node *temp = first;

	while(temp!=nullptr)
	{
		cout<<temp->coe<<"*x^"<<temp->exp<<endl;
		temp = temp->next;
	}
}


int main()
{
	create();
	display();

	return 0;
}
