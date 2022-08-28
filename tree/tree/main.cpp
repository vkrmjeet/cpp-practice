#include<iostream>
#include<stdio.h>
#include "queue.h"

struct node *root = nullptr;

void treecreate()
{
	struct node *p,*t;
	int x;
	struct Queue q;
	create(&q,100);
	printf("enter root value : ");
	scanf("%d",&x);

	root = new node;
	root->data = x;
	root->lchild = root->rchild = nullptr;

	enque(&q,root);

	while(!isEmpty(&q))
	{
		p = deque(&q);
		printf("enter left child of %d : ",p->data);
		scanf("%d",&x);
		if(x!=-1)
		{
			t = new node;
			t->data = x;
			t->lchild = t->rchild = nullptr;
			p->lchild = t;
			enque(&q,t);
		}
		printf("enter right child %d : ",p->data);
		scanf("%d",&x);
		if(x!=-1)
		{
			t = new node;
			t->data = x;
			t->lchild = t->rchild = nullptr;
			p->rchild = t;
			enque(&q,t);
		}
	}
}

void preorder(struct node *t)
{
	if(t)
	{
		printf("%d ",t->data);
	}
	else
	{
		return ;
	}
	preorder(t->lchild);
	preorder(t->rchild);
}

int main()
{
	treecreate();

	preorder(root);

	return 0;
}
