#include<iostream>
#ifndef queuecpp_h
#define queuecpp_h

class node
{
public:
	node *lchild;
	int data;
	node *rchild;
};

class queue
{
private:
	int front;
	int rear;
	int size;
	node **q;
public:
	queue(){front = rear = -1 ; size = 10 ; q = new node*[size]; }
	queue(int size){front = rear = -1 ; this->size = size ; q = new node*[size];}
	void enque(node *x);
	node* deque();
	void display();
	bool isempty();
};

void queue::enque(node *x)
{
	if((rear+1)%size==front%size)
	{
		printf("queue is full \n");
	}
	else
	{
		rear++;
		q[rear%size] = x;
	}
}

node * queue::deque()
{
	node * x = nullptr;
	if(front==rear)
	{
		printf("queue is empty \n");
	}
	else
	{
		x = q[(front+1)%size];
		front++;
	}
	return x;
}

void queue::display()
{
	int temp = front + 1;
	while((temp%size)!=rear+1%size)
	{
		printf("%d ",q[temp]);
		temp++;
	}printf("\n");
}

bool queue::isempty()
{
	return front==rear;
}

#endif // queuecpp_h
