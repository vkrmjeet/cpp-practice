#include<iostream>
using namespace std;

struct node
{
	struct node *lchild;
	int data;
	struct node *rchild;
}*root;

node * insert(struct node *p,int x)
{
	struct node *t;
	if(p==nullptr)
	{
		t = new node;
		t->data = x;
		t->lchild = t->rchild = nullptr;
		return t;
	}
	else
	{
		if(x<p->data)
		{
			p->lchild = insert(p->lchild,x);
		}
		else if(x>p->data)
		{
			p->rchild = insert(p->rchild,x);
		}
		else
		{
			cout<<"node already exists";
		}
	}
	return p;
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

int height(struct node* t)
{
	if(!t)
	{
		return 0;
	}
	int x,y;
	x = height(t->lchild);
	y = height(t->rchild);

	return x>y ? x+1 : y+1;
}

struct node * inpre(struct node *t)
{
	while(t && t->rchild!=nullptr)
	{
		t = t->rchild;
	}
	return t;
}

struct node * insucc(struct node *t)
{
	while(t && t->lchild!=nullptr)
	{
		t = t->lchild;
	}
	return t;
}

struct node * deletee(struct node *t,int key)
{
	struct node *q;
	if(t==nullptr)
	{
		return nullptr;
	}
	if(t->rchild==nullptr && t->lchild == nullptr)
	{
		if(root == t)
		{
			root == nullptr;
		}
		free(t);
		return nullptr;
	}
	if(key<t->data)
	{
		t->lchild = deletee(t->lchild,key);
	}
	else if(key>t->data)
	{
		t->rchild = deletee(t->rchild,key);
	}
	else
	{
		if(height(t->lchild)>height(t->rchild))
		{
			q = inpre(t->lchild);
			t->data = q->data;
			t->lchild = deletee(t->lchild,q->data);
		}
		else
		{
			q = insucc(t->rchild);
			t->data = q->data;
			t->rchild = deletee(t->rchild,q->data);
		}
	}
	return t;
}

int main()
{
	root = nullptr;
	root = insert(root,30);
	insert(root,20);
	insert(root,15);
	insert(root,12);
	insert(root,17);
	insert(root,35);
	insert(root,33);
	insert(root,32);
	insert(root,40);
	insert(root,4);
	insert(root,8);

	struct node *temp;
	temp = inpre(root);
	cout<<"\n inorder predecessor : "<<temp->data<<endl;
	temp = insucc(root);
	cout<<"\n inorder successdor : "<<temp->data<<endl;

	cout<< "Before deletion"; inorder(root);
	cout<< "\nEnter node to delete : ";
	int x; cin>>x;
	deletee(root,x);
	cout<< "After deletion : "; inorder(root);

	return 0;
}
