#include<iostream>
using namespace std;

struct queue
{
	int data;
	struct queue *next;
}*front,*rear;

void enque(struct queue *q,int x)
{
	struct queue *temp = new queue;
	if(temp==nullptr)
	{
		cout<<"queue is full"<<endl;
	}
	else
	{
		temp->data = x;
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
		cout<<x<<" is inserted . "<<endl;
	}
}

void display(struct queue *q)
{
	if(front==nullptr)
	{
		cout<<"queue is empty";
	}
	else
	{
		struct queue *temp = q;
		while(temp!=nullptr)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}cout<<endl;
	}
}

void deque(struct queue *q)
{
	if(rear==nullptr)
	{
		cout<<"queue is empty"<<endl;
	}
	else
	{
		struct queue *temp = front;
		int x = temp->data;
		front = front->next;
		cout<<x<< " is deleted ."<<endl;
		free(temp);
	}
}

int main()
{
	struct queue q;

	enque(&q,3);
	enque(&q,4);
	enque(&q,5);

	display(front);

	deque(&q);

	display(front);
}
