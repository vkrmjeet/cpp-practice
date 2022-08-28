#include<iostream>
using namespace std;

struct node
{
	struct node *lchild;
	int data;
	struct node *rchild;
}*root;

struct queue
{
	struct node *n;
	struct queue *next;
}*front,*rear;


void enque(struct node *x)
{
	struct queue *temp = new queue;
	temp->n = x;
	temp->next = nullptr;
	if(front==nullptr)
	{
		front = rear = temp;
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}
}

node * deque()
{
	if(front==nullptr)
	{
		return nullptr;
	}
	else
	{
		struct node *temp = front->n;
		front = front->next;
		return temp;
	}
}

bool isempty()
{
	return front==nullptr;
}

void display()
{
	struct queue *temp = front;
	while(temp!=nullptr)
	{
		cout<<temp->n->data<<" ";
		temp = temp->next;
	}cout<<endl;
}

void create()
{
	struct node *t,*p;
	root = new node;
	cout<<"enter the value of root node : ";
	cin>>root->data;
	root->lchild = root->rchild = nullptr;
	enque(root);
	cout<<isempty();
	while(!isempty())
	{
		p = deque();
		int lchild,rchild;
		cout<<"enter value of left child of "<<p->data<<" : ";
		cin>>lchild;
		if(lchild!=-1)
		{
			t = new node;
			t->data = lchild;
			t->lchild = t->rchild = nullptr;
			p->lchild = t;
			enque(t);
		}
		cout<<"enter value of right child "<<p->data<<" : ";
		cin>>rchild;
		if(rchild!=-1)
		{
			t = new node;
			t->data = rchild;
			t->lchild = t->rchild = nullptr;
			p->rchild = t;
			enque(t);
		}
	}
}

void preorder(struct node *temp)
{
	if(temp)
	{
		cout<<temp->data << " ";
	}
	else
	{
		return;
	}
	preorder(temp->lchild);
	preorder(temp->rchild);
}

void postorder(struct node *temp)
{
	if(temp)
	{
	postorder(temp->lchild);
	postorder(temp->rchild);
	cout<<temp->data<<" ";
	}
}

void inorder(struct node *t)
{
	if(t)
	{
		inorder(t->lchild);
		cout<<t->data<< " "<<flush;
		inorder(t->rchild);
	}
}

int main()
{
	create();

	cout<<"preorder : "; preorder(root);
	cout<<endl;

	cout<<"postorder : "; postorder(root);
	cout<<endl;

	cout<<"inorder : "; inorder(root);
	cout<<endl;

	return 0;
}
