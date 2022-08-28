#include<iostream>
#include "queue.h"
using namespace std;


int height(struct node *t)
{
	int x = 0 , y = 0;
	if(t)
	{
		x = height(t->lchild);
		y = height(t->rchild);
	}
	else
	{
		return -1;
	}

	return x>y ? x+1 : y+1;
}

int nodeheight(struct node *t)
{
	int hl,hr;
	hl = t && t->lchild ? t->lchild->height : 0;
	hr = t && t->rchild ? t->rchild->height : 0;

	return hl>hr ? hl+1 : hr+1;
}

int balancefactor(struct node *t)
{
	int hl,hr;
	hl = t && t->lchild ? t->lchild->height : 0;
	hr = t && t->rchild ? t->rchild->height : 0;

	return hl-hr;
}

node * LLrotation(struct node *t)
{
	struct node *tl = t->lchild;
	struct node *tlr = tl->rchild;

	tl->rchild = t;
	t->lchild = tlr;

	t->height = nodeheight(t);
	tl->height = nodeheight(t);

	if(root==t)
		root = tl;
	return tl;
}

node * LRrotation(struct node *t)
{
	struct node *tl = t->lchild;
	struct node *tlr = tl->rchild;

	t->lchild = tlr->rchild;
	tl->rchild =  tlr->lchild;
	tlr->rchild = t;
	tlr->lchild = tl;

	tl->height = nodeheight(tl);
	t->height = nodeheight(t);
	tlr->height = nodeheight(tlr);

	if(root=t)
	{
		root = tlr;
	}

	return tlr;

}

node * RRrotation(struct node *t)
{
	struct node *tr = t->rchild;
	struct node *trl = tr->lchild;

	t->rchild = trl;
	tr->lchild = t;

	t->height = nodeheight(t);
	tr->height = nodeheight(tr);

	if(root==t)
	{
		root = tr;
	}
	return tr;
}

node * RLrotation(struct node *t)
{
	struct node *tr = t->rchild;
	struct node *trl = tr->lchild;

	t->rchild = trl->lchild;
	tr->lchild = trl->rchild;
	trl->lchild = t;
	trl->rchild = tr;

	if(root==t)
	{
		root = trl;
	}
	return trl;
}

node * insert(struct node *t,int x)
{
	struct node *temp;

	if(t==nullptr)
	{
		temp = new node;
		temp->data = x;
		temp->height=1;
		temp->lchild = temp->rchild = nullptr;
		return temp;
	}
	else
	{
		if( x < t->data)
		{
			t->lchild = insert(t->lchild,x);
		}
		else
		{
			t->rchild = insert(t->rchild,x);
		}
	}
	t->height = nodeheight(t);

	if(balancefactor(t)==2 && balancefactor(t->lchild)==1)
	{
		return LLrotation(t);
	}
	else if(balancefactor(t)==2 && balancefactor(t->lchild)==-1)
	{
		return LRrotation(t);
	}
	else if(balancefactor(t)==-2 && balancefactor(t->rchild)==-1)
	{
		return RRrotation(t);
	}
	else if(balancefactor(t)==-2 && balancefactor(t->rchild)==1)
	{
		return RLrotation(t);
	}

	return t;
}

void inorder(struct node *t)
{
	if(t)
	{
		inorder(t->lchild);
		cout<<t->data<<" ";
		inorder(t->rchild);
	}
	else
	{
		return ;
	}
};

void levelorder(struct node *t)
{
	cout<<"Level 0 : "<<t->data<<" "<<endl;
	queue q(100);
	q.enque(t);
	while(!q.isempty())
	{
		t = q.deque();
		if(t->lchild)
		{
			cout<<t->lchild->data<<" ";
			q.enque(t->lchild);
		}
		if(t->rchild)
		{
			cout<<t->rchild->data<<" ";
			q.enque(t->rchild);
		}
    }
}

int main()
{
	root = insert(root,10);
	insert(root,9);
	insert(root,8);
	insert(root,13);
	insert(root,15);
	insert(root,18);
	insert(root,14);
	insert(root,20);

	levelorder(root);

	cout<<"\n height of binary tree is : "<<height(root)<<endl;

	return 0;
}
