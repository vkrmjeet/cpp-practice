#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct queue
{
	int size;
	struct node *first;
	struct node *last;
	struct node *q;
};

bool isempty(struct queue *q)
{
	if(q->last==q->first)
	{
		return true;
	}
	else
		return false;
}

void insert(struct queue &q, int x)
{
	static int first = 0;
	struct node *temp = new node;
	temp->data = x;
	temp->next = nullptr;
	q.last->next = temp;
	q.last = temp;
	if(first==0)
	{
		q.first = q.last;
		first++;
	}
	cout<<x<<" is inserted "<<endl;
}

int deleteq(struct queue &q)
{
	if(!isempty(&q))
	{
		int x = q.first->data;
		struct node *temp = q.first;
		q.first = q.first->next;
		cout<<x<<" is deleted";
		free(temp);
		cout<<endl;
	}
	else
	{
		cout<<"queue is empty";
	}
}

void display(struct queue *q)
{
	if(!isempty(q))
	{
		struct node *temp = q->first;
		while(temp)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}cout<<endl;
	}
	else
	{
		cout<<"queue is empty"<<endl;
	}
}

int main()
{
	struct queue q;
	q.size = 8;
	q.q = new node[q.size];
	insert(q,3);
	insert(q,4);
	insert(q,5);
	insert(q,6);

	display(&q);

	deleteq(q);

	display(&q);
	insert(q,7);
	display(&q);

	return 0;
}
