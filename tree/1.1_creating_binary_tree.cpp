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
	struct node *r;
	struct queue *next;
}*front,*rear;


void enque(struct node *d)
{
	struct queue *temp = new queue;
	temp->r = d;
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
	if(front!=nullptr)
	{
		struct node *temp = front->r;
		front = front->next;
		return temp;
	}
	else
	{
		return nullptr;
	}
}

bool isempty()
{
	return front==nullptr;
}

void display(struct queue *t)
{
	struct queue *temp = front;
	while(temp->next!=nullptr)
	{
		cout<<temp->r->data<<" ";
		temp = temp->next;
	}cout<<endl;
}

void create()
{
	struct node *p , *t;
	int x;
	cout<<"enter root node value : ";
	cin>>x;
	root = new node;
	root->data = x;
	root->lchild = root->rchild = nullptr;
	enque(root);
	while(!isempty())
	{
		p = deque();
		int lchild,rchild;
		cout<<"Enter left child : ";
		cin>>lchild;
		if(lchild!=-1)
		{
			t = new node;
			t->data = lchild;
			t->lchild = t->rchild = nullptr;
			p->lchild = t;
			enque(t);
		}
		cout<<"Enter right child : ";
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
		cout<<temp->data<<" ";
	}
	else
	{
		return ;
	}
	preorder(temp->rchild);
	preorder(temp->lchild);
}

int main()
{
	create();

	preorder(root);

	return 0;
}
