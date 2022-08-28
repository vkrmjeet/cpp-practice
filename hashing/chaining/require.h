#ifndef require_h
#define require_h
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void sortedinsert(struct node **h,int x)
{
	struct node *t,*q = nullptr,*p = *h;
	t = new node;
	t->data = x;
	t->next = nullptr;

	if(*h==nullptr)
	{
		*h = t;
	}
	else
	{
		while(p && p->data<x)
		{
			q = p;
			p = p->next;
		}
		if(p==*h)
		{
			t->next = *h;
			*h = t;
		}
		else
		{
			t->next = q->next;
			q->next = t;
		}
	}
}

node* search(struct node *p,int key)
{
	while(p)
	{
		if(key==p->data)
		{
			return p;
		}
		p = p->next;
	}
	return nullptr;
}


#endif require_h
