#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*first;

void create(int a[], int n)
{
	first = new node;
	first->data = a[0];
	first->next = NULL;

	struct node *last,*temp;
	last = first;

	for(int i = 1 ; i < n ; i++)
	{
		temp = new node;
		temp->data = a[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

void display(struct node *p)
{
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
}

int countnodes(struct node *p)
{
	int count = 0;
	while(p!=NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

void sumofall(struct node *traversingpointer)
{
	int sum = 0;
	int nodes = countnodes(traversingpointer);
	while(traversingpointer!=NULL)
	{
		sum += traversingpointer->data;
		traversingpointer = traversingpointer->next;
	}
	cout<< "\nsum of "<<nodes<< " nodes is "<<sum<<endl;

}

int main()
{
	int arr[] = {1,5,3,6,3,3,6,3,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	create(arr,n);
	display(first);

	sumofall(first);

	return 0;
}

