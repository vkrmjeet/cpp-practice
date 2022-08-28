#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*first,*last;


void insertlast(int x)
{
	struct node *temp = new node;
	temp->data = x;
	temp->next = nullptr;
	if(first==nullptr)
	{
		first=last=temp;
	}
	else
	{
		last->next = temp;
		last = temp;
	}
}

void display(struct node *p)
{
	while(p!=nullptr)
	{
		cout<<p->data<<" ";
		p=p->next;
	}cout<<endl;
}

int count(struct node *p)
{
	int count = 0;
	while(p!=nullptr)
	{
		count++;
		p = p->next;
	}
	return count;
}

int deletee(int position)
{
	int x = -1;
	if(position<1 || position>count(first))
	{
		return 0;
	}
	struct node *posi= first;
	if(position==1)
	{
		x = first->data;
		first = first->next;
		delete posi;
	}
	else
	{
		for(int i = 1 ; i <= position - 2 ; i++)
		{
			posi = posi->next;
		}
		struct node *nex = posi;
		nex = nex->next;
		posi->next =  nex->next;
		x = nex->data;
		free(nex);
	}
	return x;
}

int main()

{
	insertlast(3);
	insertlast(4);
	insertlast(5);
	insertlast(7);
	insertlast(9);

	display(first);

	int position = 0;
	cout<< " Enter the position from where to delete the element : ";
	cin>>position;

	int deleted = deletee(position);
	cout<<deleted<<" is deleted "<<endl;

	display(first);

	return 0;
}
