#include<iostream>
#ifndef queue_h
#define queue_h

struct node
{
	struct node *lchild;
	int data;
	int height;
	struct node *rchild;
}*root=nullptr;

class queue
{
private:
	int front;
	int rear;
	int size;
	struct node **q;
public:
	queue(){int size = 10; front = rear = -1; q = new node*[size];}
	queue(int sz) {int size = sz; front=rear = -1; q = new node*[size];}
	void enque(struct node *t);
	node * deque();
	bool isempty();
};

void queue::enque(node *t)
{
	if((rear+1)%size==front%size)
	{
		printf("queue is full \n");
	}
	else
	{
		rear++;
		q[rear%size] = t;
	}
}

node * queue::deque()
{
	node * temp = nullptr;
	if(front==rear)
	{
		printf("queue is empty");
	}
	else
	{
		temp = q[(front+1)%size];
		front++;
	}
	return temp;
}

bool queue::isempty()
{
	return front==rear;
}

#endif
