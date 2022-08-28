#include<iostream>
#include<stack>
using namespace std;

struct node
{
	struct node *lchild;
	int data;
	struct node *rchild;
};

node * insert(struct node *p, int key)
{
	struct node *t;
	if(p==nullptr)
	{
		t = new node;
		t->data = key;
		t->lchild = t->rchild = nullptr;
	}
	else
	{
		if(key<p->data)
		{
			p->lchild = insert(p->lchild,key);
		}
		else
		{
			p->rchild = insert(p->rchild,key);
		}
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
}

int countleafnodes(struct node *t)
{
	if(!t)
	{
		return 0;
	}
	if(t->rchild == nullptr && t->rchild ==nullptr)
	{
		return 1;
	}
	else
	{
		return countleafnodes(t->rchild)+countleafnodes(t->lchild);
	}

}

int countnodes(struct node *t)
{
	if(t==nullptr)
		return 0;
	else
	{
		return 1+countnodes(t->lchild)+countnodes(t->rchild);
	}
}

void iterativepostorder(struct node *t)
{
	stack<long int> st;
	long int temp;
	while(t || !st.empty())
	{
		if(t)
		{
			st.push((long int)t);
			t = t->lchild;
		}
		else
		{
			temp = st.top();
			st.pop();
			if(temp>0)
			{
				st.push(-temp);
				t = (struct node *)temp;
				t = t->rchild;
			}
			else
			{
				temp = -1 * temp;
				t = (struct node *)temp;
				cout<<t->data<<" ";
				t = nullptr;
			}
		}
	}
}

node * search(struct node *t , int key)
{
	if(t==nullptr)
	{
		return t;
	}
	if(key==t->data)
	{
		return t;
	}
	else if(key<t->data)
	{
		return search(t->lchild,key);
	}
	else
	{
		return search(t->rchild,key);
	}
}

void iterativepreorder(struct node *t)
{
	stack<struct node *> st;
	while (t || !st.empty())
	{
		if(t)
		{
			cout<<t->data<<" ";
			st.push(t);
			t = t->lchild;
		}
		else
		{
			t = st.top();
			st.pop();
			t = t->rchild;
		}
	}
}

void iterativeinorder(struct node *t)
{
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
			cout<<t->data <<" ";
			t = t->rchild;
		}
	}
}

int main()
{
	struct node *root = nullptr;
	root = insert(root,30);
	insert(root,25);
	insert(root,20);
	insert(root,40);
	insert(root,50);

	inorder(root);

	cout<<"\n nodes : "<<countnodes(root);
	cout<<"\n leaf nodes : "<<countleafnodes(root);
	cout<<"\n postorder : "; iterativepostorder(root);
	cout<<"\n preorder : "; iterativepreorder(root);
	cout<<"\n inorder : "; iterativeinorder(root);


	cout<<"\nenter key to search ";
	int key;
	cin>>key;
	struct node * res = search(root,key);
	if(res)
	{
		cout<<"element is present in the tree ";
	}
	else
	{
		cout<<"element is not present in the tree";
	}

	return 0;
}
