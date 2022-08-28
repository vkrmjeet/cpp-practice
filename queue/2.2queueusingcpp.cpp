#include<iostream>
using namespace std;

class queue
{
public:
	int size;
	int front;
	int rear;
	int *a;
	queue()
	{
		size = 10;
		front = rear = -1;
		a = new int[size];
	}
	queue(int siz)
	{
		size = siz;
		front = rear = -1;
		a = new int[size];
	}
	void enque(int x);
	void deque();
	void display();
};

void queue::enque(int x)
	{
		if(rear==size-1)
		{
			cout<<"queue is full.(overflow condition)"<<endl;
		}
		else
		{
			rear++;
			a[rear] = x;
			cout<<a[rear]<< " is inserted. "<<endl;
		}
	}
	void queue::deque()
	{
		if(rear == -1)
		{
			cout<<"queue is empty."<<endl;;
		}
		else
		{
			front++;
			int x = a[front];
			cout<<x<<" is deleted from queue. "<<endl;
		}
	}
	void queue::display()
	{
		if(rear == -1)
		{
			cout<<"queue is empty"<<endl;
		}
		else
		{
			for(int i= front+1 ; i<= rear ; i++)
			{
				cout<<a[i]<<" ";
			}cout<<endl;
		}
	}

int main()
{
	queue q(10);
	q.enque(3);
	q.enque(4);
	q.enque(5);

	q.display();

	q.deque();

	q.display();
}
