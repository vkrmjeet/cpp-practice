#include<iostream>
using namespace std;

class queue
{
private:
	int front;
	int rear;
	int size;
	int *q;
public:
	queue(){front = rear = -1 ; size = 10 ; q = new int[size]; }
	queue(int size){front = rear = -1 ; this->size = size ; q = new int[size];}
	void enque(int x);
	int deque();
	void display();
};

void queue::enque(int x)
{
	if((rear+1)%size==front%size)
	{
		cout<<"queue is full";
	}
	else
	{
		rear++;
		q[rear%size] = x;
	}
}

int queue::deque()
{
	int x;
	if(front==rear)
	{
		cout<<"queue is empty ";
	}
	else
	{
		x = q[(front+1)%size];
		front++;
		cout<<x<<" is deleted . ";
	}
}

void queue::display()
{
	int temp = front + 1;
	while((temp%size)!=rear+1%size)
	{
		cout<<q[temp]<<" ";
		temp++;
	}cout<<endl;
}

int main()
{
	queue q(10);
	q.enque(4);
	q.enque(5);
	q.enque(6);
	q.enque(7);

	q.display();

	return 0;
}
