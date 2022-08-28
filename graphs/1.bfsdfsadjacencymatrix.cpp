#include<iostream>
using namespace std;

struct queue
{
	int data;
	struct queue *next;
}*front,*rear;

void push(int x)
{
	struct queue *temp = new queue;
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
}

int pop()
{
	if(front!=nullptr)
	{
		int var = 0;
		var = front->data;
		struct queue *temp = front;
		front = front->next;
		free(temp);
		return var;
	}
	else
	{
		return -1;
	}
}

bool isempty()
{
	if(front==nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void queueprint()
{
	if(front==nullptr)
	{
		cout<<"queue is empty";
		return ;
	}
	struct queue *temp = front;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}cout<<endl;
}

void bfs(int g[][7],int start,int n)
{
	int i = start;
	int visited[n] = {0};
	cout<<i<<" ";
	push(i);
	visited[i] = 1;
	while(!isempty())
	{
		i = pop();
		for(int j = 0 ; j < n ; j++)
		{
			if(g[i][j]==1 && visited[j]==0)
			{
				cout<<j<<" ";
				visited[j] = 1;
				push(j);
			}
		}
	}
}

void dfs(int g[][7] , int start,int n)
{
	static int visited[7] = {0};
	if(visited[start]==0)
	{
		cout<<start<<" ";
		visited[start] = 1;
		for(int j = 0 ; j < n ; j++)
		{
			if(g[start][j]==1 && visited[j]==0)
			{
				dfs(g,j,n);
			}
		}
	}
	else
	{
		return ;
	}
}

int main()
{
	int g[7][7] = {
		           {0,0,0,0,0,0,0},
		           {0,0,1,1,0,0,0},
		           {0,1,0,0,1,0,0},
		           {0,1,0,0,1,0,0},
		           {0,0,1,1,0,1,1},
		           {0,0,0,0,1,0,0},
		           {0,0,0,0,1,0,0}
				   };
	bfs(g,1,7);
	cout<<endl;
	dfs(g,4,7);


	return 0;
}
