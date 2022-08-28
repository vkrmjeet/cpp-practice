#include<iostream>
using namespace std;

struct queue
{
	int data;
	struct queue *next;
	struct queue *prev;
}*front,*rear;

void enqueatfront(struct queue *q,int x)
{
	struct queue *temp = new queue;
	temp->data = x;
	temp->prev = nullptr;
	if(temp && front==nullptr)
	{
		temp->next = nullptr;
		front = rear = temp;
	}
	else if(temp)
	{
		temp->next = front;
		front->prev = temp;
		front = temp;
	}
	cout<<x<<" inserted at front "<<endl;
}

void enqueatrear(struct queue *q,int x)
{
	struct queue *temp = new queue;
	temp->data = x;
	temp->prev = nullptr;
	if(temp && front==nullptr)
	{
		temp->next = nullptr;
		front = rear = temp;
	}
	else if(temp)
	{
		rear->next = temp;
		temp->prev = rear;
		temp->next = nullptr;
		rear = temp;
	}
	cout<<x<<" inserted at rear "<<endl;
}

void dequeatfront()
{
	if(front==nullptr)
	{
		cout<<"queue is empty"<<endl;
	}
	else
	{
		struct queue *temp = front;
		front = front->next;
		front->prev = nullptr;
		int x = front->data;
		free(temp);
		cout<<x<< " is deleted. "<<endl;
	}
}

void dequeatrear()
{
	if(front==nullptr)
	{
		cout<<"queue is empty"<<endl;
	}
	else
	{
		struct queue *temp = rear;
		rear = rear->prev;
		rear->next = nullptr;
		int x = rear->data;
		free(temp);
		cout<<x<< " is deleted. "<<endl;
	}
}

void display(struct queue *q)
{
	struct queue *temp = q;
	while(temp!=nullptr)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}cout<<endl;
}

int main()
{
	struct queue q;

	enqueatrear(&q,2);
	enqueatrear(&q,3);
	enqueatfront(&q,4);
	enqueatfront(&q,5);

	display(front);

	dequeatfront();
	dequeatrear();

	display(front);
}
