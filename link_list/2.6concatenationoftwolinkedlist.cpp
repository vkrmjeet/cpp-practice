#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*first,*second,*last1,*last2,*third;

void insertlast(int daata)
{
	struct node *temp = new node;
	temp->data = daata;
	temp->next = nullptr;

	if(first==NULL)
	{
		first = temp;
		last1 = first;
	}
	else
	{
		last1->next = temp;
		last1 = temp;
	}
}
void insertlastt(int daata)
{
	struct node *temp = new node;
	temp->data = daata;
	temp->next = nullptr;

	if(second==NULL)
	{
		second = temp;
		last2 = second;
	}
	else
	{
		last2->next = temp;
		last2 = temp;
	}
}

void display(struct node *p)
{
	while(p!=nullptr)
	{
		cout<<p->data<<" ";
		p = p->next;
	}cout<<endl;
}

void mergel(struct node *f,struct node *s)
{
	third = f;
	while(f->next!=nullptr)
	{
		f = f->next;
	}
	f->next = s;
	display(third);
}

int main()
{
	insertlast(2);
	insertlast(5);
	insertlast(7);
	insertlast(9);

	display(first);

	insertlastt(1);
	insertlastt(3);
	insertlastt(6);

	display(second);

	mergel(first,second);


	return 0;
}
