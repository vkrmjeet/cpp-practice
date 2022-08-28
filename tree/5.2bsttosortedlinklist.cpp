#include<iostream>
#include<stack>
using namespace std;

struct node
{
	struct node *lchild;
	int data;
	struct node *rchild;
}*root;

struct llnode
{
	int data;
	struct llnode *next;
}*first;

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

void bsttoll(struct node *t)
{
	struct llnode *last,*temp;
	stack<struct node *> st;
	while(t || !st.empty())
	{
		if(t)
		{
			st.push(t);
			t = t->lchild;
		}
		else
		{
			t = st.top();
			st.pop();
			if(first!=nullptr)
			{
				temp = new llnode;
				temp->data = t->data ;
				temp->next = nullptr;
				last->next = temp;
				last = temp;
			}
			else
			{
				first = new llnode;
				first->data = t->data;
				first->next = nullptr;
				last = first;
			}
			t = t->rchild;
		}
	}
}

void display(struct llnode *t)
{
	while(t)
	{
		cout<<t->data<<" ";
		t = t->next;
	}cout<<endl;
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

	bsttoll(root);

	display(first);

	cout<<first->data<<endl;
	cout<<first->next->data<<endl;

	return 0;
}
