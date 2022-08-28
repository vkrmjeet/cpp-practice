#include<iostream>
using namespace std;

struct node
{
	struct node *lchild;
	int data;
	struct node *rchild;
}*root;

node * createtree(struct node *t,int x)
{
	t = new node;
	t->data = x;
	t->lchild = t->rchild = nullptr;
	return t;
}

void preorder(struct node *t)
{
	if(t)
	{
		cout<<t->data<<" ";
		preorder(t->lchild);
		preorder(t->rchild);
	}
	else
	{
		return ;
	}
}

int main()
{
	root = new node;
	root->data = 1;
	root->lchild = createtree(root->lchild,2);
	root->rchild = createtree(root->rchild,3);
	root->lchild->lchild = createtree(root->lchild->lchild,2);

	preorder(root);
}
