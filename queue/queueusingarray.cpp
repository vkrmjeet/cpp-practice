#include<iostream>
using namespace std;


struct queue
{
	int size;
	int first,last;
	int *q;
};

bool isfull(struct queue q)
{
	if(q.last==q.size-1)
	{
		return true;
	}
	else
		return false;
}

bool isempty(struct queue q)
{
	if(q.last==-1)
	{
		return true;
	}
	else
		return false;
}

void insert(struct queue &q, int x)
{
	if(!isfull(q))
	{
		q.last += 1;
		q.q[q.last] = x;
	}
	else
	{
		cout<<"queue is full";
	}
}

int deleteq(struct queue &q)
{
	if(!isempty(q))
	{
		q.first++;
		int x = q.q[q.first];
		cout<<x<<" is deleted"<<endl;
	}
	else
	{
		cout<<"queue is empty";
	}
}

void display(struct queue q)
{
	if(!isempty(q))
	{
		for(int i = q.first+1 ; i<=q.last ; i++)
		{
			cout<<q.q[i]<<" ";
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
	q.q = new int[q.size];

	q.first = q.last = -1;

	insert(q,3);
	insert(q,4);
	insert(q,5);

	display(q);

	deleteq(q);
	deleteq(q);

	cout<<endl;
	display(q);
}
