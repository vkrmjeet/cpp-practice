#ifndef Queue_h
#define Queue_h
struct node
{
	struct node *lchild;
	int data;
	struct node *rchild;
};

struct Queue
{
	int size;
	int front;
	int rear;
	struct node **Q;
};

void create(struct Queue *q,int size)
{
	q->size = size;
	q->front = q->rear = 0;
	q->Q = (struct node**)new node[q->size];
}

void enque(struct Queue *q,struct node *x)
{
	if((q->rear+1)%q->size==q->front)
	{
		printf("queue is full \n");
	}
	else
	{
		q->rear = (q->rear+1)%q->size;
		q->Q[q->rear] = x;
	}
}

node* deque(struct Queue *q)
{
	node *x = NULL;

	if(q->front==q->rear)
	{
		printf("queue is empty \n");
	}
	else
	{
		q->front = (q->front+1)%q->size;
		x = q->Q[q->front];
	}
	return x;
}

bool isEmpty(struct Queue *q)
{
	return q->front==q->rear;
}

#endif // Queue_h
