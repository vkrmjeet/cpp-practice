#include<iostream>
#include<stack>
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

void iterativepreorder(struct node *t)
{
	stack<struct node *> st;
	while(t || !st.empty())
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

void recursivepreorder(struct node *t)
{
	if(t)
	{
		cout<<t->data<<" ";
		recursivepreorder(t->lchild);
		recursivepreorder(t->rchild);
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
			cout<<t->data<<" ";
			t = t->rchild;
		}
	}
}

void recursiveinorder(struct node *t)
{
	if(t)
	{
		recursiveinorder(t->lchild);
		cout<<t->data<<" ";
		recursiveinorder(t->rchild);
	}
}

void recrusivepostorder(struct node *t)
{
	if(t)
	{
		recrusivepostorder(t->lchild);
		recrusivepostorder(t->rchild);
		cout<<t->data<<" ";
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
			st.emplace((long int)t);
			t = t->lchild;
		}
		else
		{
			temp = (long int)st.top();
			st.pop();
			if(temp>0)
			{
				st.push(-temp);
				t = (struct node *)temp;
				t = t->rchild;
			}
			else
			{
				t = (struct node *)(-1*temp);
				cout<<t->data<<" ";
				t = nullptr;
			}
		}
	}
}

int main()
{
	root = new node;
	root->data = 1;
	root->lchild = createtree(root->lchild,2);
	root->rchild = createtree(root->rchild,3);
	root->lchild->lchild = createtree(root->lchild->lchild,4);

	cout<<" iterative preorder : "; iterativepreorder(root); cout<<endl;
	cout<<" recursive preorder : "; recursivepreorder(root); cout<<endl;
	cout<<" iterative inorder : "; iterativeinorder(root); cout<<endl;
	cout<<" recursive inorder : "; recursiveinorder(root); cout<<endl;
	cout<<" recursive postorder : "; recrusivepostorder(root); cout<<endl;
	cout<<" iterative postorder : "; iterativepostorder(root); cout<<endl;
}
