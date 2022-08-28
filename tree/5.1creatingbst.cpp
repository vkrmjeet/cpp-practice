#include<iostream>
using namespace std;

struct node
{
	struct node *lchild;
	int data;
	struct node *rchild;
}*root;

void createbst(struct node *t,int key)
{
	struct node *r;
	while(t)
	{
		r = t;
		if(key==t->data)
		{
			cout<<"key is already present in the bst.\n";
		}
		else if(key<t->data)
		{
			t = t->lchild;
		}
		else
		{
			t = t->rchild;
		}
	}
	struct node *p = new node;
	p->data = key;
	p->lchild = p->rchild = nullptr;
	if(p->data < r->data)
	{
		r->lchild = p;
	}
	else
	{
		r->rchild = p;
	}
}

void inorder(struct node *t)
{
	if(t)
	{
		inorder(t->lchild);
		cout<<t->data<<" ";
		inorder(t->rchild);
	}
}

int main()
{
	root = new node;
	root->data = 30;
	root->lchild = root->rchild = nullptr;

	createbst(root,20);
	createbst(root,40);
	createbst(root,25);
	createbst(root,35);
	createbst(root,15);

	inorder(root);

}
