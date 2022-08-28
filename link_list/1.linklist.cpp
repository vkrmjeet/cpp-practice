#include<iostream>
using namespace std;

struct node
{
	int val;
	struct node *next;
}*first;

void display(struct node *p)
{
	while(p!=NULL)
	{
		cout<<p->val;
		p = p->next;
	}
}

void create(int a[],int n)
{
	int i;
	struct node *t,*last;
	first = new node;
	first->val = a[0];
	first->next = NULL;
	last = first;

	for(i=1 ; i<n ; i++)
	{
		t = new node;
		t->val = a[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}

}

int main()
{
	int a[] = {3,5,7,3,4,6,};
	int n = sizeof(a)/sizeof(a[0]);
	create(a,n);
	display(first);

	return 0;
}
