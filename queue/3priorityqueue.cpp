#include<iostream>
using namespace std;

struct queue
{
	int data;
	int priority;
	struct queue *prev;
	struct queue *next;
}*front,*rear;

void enque(struct queue *q)
{
	int x, pr;
	cout<<"enter value of element : ";
	cin>>x;
	cout<<"enter priority of element : ";
	cin>>pr;

	struct queue *temp = new queue;
	temp->data = x;
	temp->priority = pr;
	temp->next = nullptr;

	if(front==nullptr)
	{
		temp->prev = nullptr;
		front = rear = temp;
	}
	else
	{
		temp->prev = rear;
		rear->next = temp;
		rear = temp;
	}
}

void deque(struct queue *q)
{
	if(front==nullptr)
	{
		cout<<"queue is empty."<<endl;
	}
	else
	{
		struct queue *temp = front;
		struct queue *highpr = front;

		while(temp!=nullptr)
		{
			if(highpr->priority < temp->priority)
			{
				highpr = temp;
			}
			temp = temp->next;
		}
		cout<< "Highest priority member :     data : "<<highpr->data << "   priority : "<<highpr->priority<<endl;
		temp = highpr->prev;
		if(highpr->next!=nullptr)
		{
			temp->next = highpr->next;
			highpr->next->prev = temp;
		}
		else
		{
			temp->next = nullptr;
			free(highpr);
		}
	}
}

void display(struct queue *temp)
{
	while(temp!=nullptr)
	{
		cout<< "data : "<<temp->data << "   priority : "<<temp->priority<<endl;
		temp = temp->next;
	}cout<<endl;
}

int main()
{
	struct queue q;

	enque(&q);
	enque(&q);
	enque(&q);
	enque(&q);

	display(front);

	deque(&q);

	display(front);

	return 0;
}
