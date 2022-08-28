#include<iostream>
#include "queuecpp.h"
using namespace std;

class tree
{
public:
	node *root;
	tree(){root=nullptr;}

	void createtree();
	void preorder(node *p);
	void postorder(node *p);
	void inorder(node *p);
	void levelorder(node *p);
	int height(node *p);
	int height() {height(root);}
	int countnodes(node *p);
	int leafnodes(node *p);
};

void tree::createtree()
{
	node *t,*p;
	root = new node;
	cout<<"enter the value of root node : ";
	cin>>root->data;
	root->lchild = root->rchild = nullptr;
	queue q(100);
	q.enque(root);
	while(!q.isempty())
	{
		p = q.deque();
		int lchild,rchild;
		cout<<"enter value of left child of "<<p->data<<" : ";
		cin>>lchild;
		if(lchild!=-1)
		{
			t = new node;
			t->data = lchild;
			t->lchild = t->rchild = nullptr;
			p->lchild = t;
			q.enque(t);
		}
		cout<<"enter value of right child "<<p->data<<" : ";
		cin>>rchild;
		if(rchild!=-1)
		{
			t = new node;
			t->data = rchild;
			t->lchild = t->rchild = nullptr;
			p->rchild = t;
			q.enque(t);
		}
	}
}

void tree::preorder(node *p)
{
	if(p)
	{
		cout<<p->data<<" ";
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void tree::postorder(node *p)
{
	if(p)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		cout<<p->data<<" ";
	}
}

void tree::inorder(node *p)
{
	if(p)
	{
		inorder(p->lchild);
		cout<<p->data<<" "<<flush;
		inorder(p->rchild);
	}
	else
	{
		return;
	}
}

int tree::height(node *p)
{
	int x =0;
	int y = 0;
	if(p==nullptr)
	{
		return 0;
	}
	x = height(p->lchild);
	y = height(p->rchild);
	if(x>=y)
	{
		cout<<"returned x"<<endl;
		return x+1;

	}
	else
	{
		cout<<"returned y"<<endl;
		return y+1;

	}
}

void tree::levelorder(node *p)
{
	queue q(100);
	cout<<p->data<<" ";
	q.enque(p);
	while(!q.isempty())
	{
		p = q.deque();
		if(p->lchild)
		{
			cout<<p->lchild->data<<" ";
			q.enque(p->lchild);
		}
		if(p->rchild)
		{
			cout<<p->rchild->data<<" ";
			q.enque(p->rchild);
		}
	}
}

int tree::countnodes(node *p)
{
	int static x = 0;
	if(p)
	{
		x++;
		countnodes(p->lchild);
		countnodes(p->rchild);
	}
	return x;
}

int tree::leafnodes(node *p)
{
	if(!p)
	{
		return 0;
	}
	if(p->lchild == nullptr && p->rchild == nullptr)
	{
		return 1;
	}
	else
	{
		return leafnodes(p->lchild)+leafnodes(p->rchild);
	}

}
int main()
{
	tree t;
	t.createtree();
	cout<<"preorder : "; t.preorder(t.root); cout<<endl;
	cout<<"postorder : "; t.postorder(t.root); cout<<endl;
	cout<<"inorder : "; t.inorder(t.root); cout<<endl;
	cout<<"level - order : "; t.levelorder(t.root); cout<<endl;
	cout<<"nodes count : "; cout<<t.countnodes(t.root); cout<<endl;
	cout<<"leaf nodes count : "; cout<<t.leafnodes(t.root); cout<<endl;


	cout<<"height of tree is : "<<t.height(t.root)-1<<endl;

	return 0;
}
