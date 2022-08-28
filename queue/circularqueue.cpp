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
	if((q.last+1)%q.size==q.first)
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

void enque(struct queue &q, int x)
{
	if(!isfull(q))
	{
		q.last = (q.last+1)%q.size;
		q.q[q.last] = x;
	}
	else
	{
		cout<<"queue is full";
	}
}

int deque(struct queue &q)
{
	if(!isempty(q))
	{
		q.first = (q.first+1)%q.size;
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
		int i = q.first + 1;
		do
		{
			cout<<q.q[i]<<" ";
			i = (i+1)%q.size;
		}while(i!=(q.last+1)%q.size);
		cout<<endl;
	}
	else
	{
		cout<<"queue is empty"<<endl;
	}
}

int main()
{
	struct queue q;
	q.size = 4;
	q.q = new int[q.size];

	q.first = q.last = -1;

	enque(q,3);
	enque(q,4);
	enque(q,5);
	enque(q,8);
	enque(q,9);

	display(q);

	deque(q);
	deque(q);

	cout<<endl;
	enque(q,6);
	display(q);
}
