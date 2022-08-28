#include<iostream>
#include<stack>
using namespace std;

struct node
{
	struct node *lchild;
	int data;
	struct node *rchild;
}*root;

void createpre(int arr[], int n)
{
	stack<struct node *> st;
	struct node *t,*p;
	int i = 0;
	root = new node;
	root->data = arr[i++];
	root->lchild = root->rchild = nullptr;
	p = root;
	while(i<n)
	{
		if(arr[i]<p->data)
		{
			t = new node;
			t->data = arr[i++];
			t->lchild = t->rchild = nullptr;
			p->lchild = t;
			st.push(p);
			p = t;
		}
		else
		{
			if(arr[i]>p->data && arr[i] < st.empty() ? 32767 : st.top()->data)
			{
				t = new node;
				t->data = arr[i++];
				t->lchild = t->rchild = nullptr;
				p->rchild = t;
				p = t;
			}
			else
			{
				p = st.top();
				st.pop();
			}
		}
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
	int a[] = {30,20,10,15,25,40,50,45};
	int n = sizeof(a)/sizeof(a[0]);

	createpre(a,n);

	inorder(root);

	return 0;
}
