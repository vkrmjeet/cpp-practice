#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void push(struct node **a,int index,int element)
{
    struct node *temp = new node;
    temp->data = element;
    temp->next = nullptr;
    if(a[index]==nullptr)
    {
        a[index] = temp;
    }
    else
    {
        struct node *q = a[index];
        while(q->next != nullptr)
        {
            q = q->next ;
        }
        q->next = temp;
    }
}

void bfs(struct node **a,struct node *start,int n)
{
	int visited[n] = {0};
	static int var = 0;
	struct node  *temp= start;
	cout<<start->data<<" ";
	visited[start->data] = 1;
	int j = 1;
	for(int i = 1 ; i < n ; i++)
	{
		temp = a[i];
		while(temp)
		{
			if(visited[temp->data]==0)
			{
				cout<<temp->data<<" ";
				visited[temp->data] = 1;
				temp = temp->next;
				j++;
			}
			else
			{
				temp = temp->next;
			}
		}
		cout<<endl;
		if(j==n-1)
		{
			break;
		}
	}
}

void print(int arr[], int n)
{
	cout<<endl;
	for(int i = 0 ; i < n ; i++)
	{
		cout<<arr[i]<<" ";
	}cout<<endl;
}

void dfs(struct node **a,struct node *start,int n)
{
	if(start==nullptr)
	{
		return ;
	}
	static int visited[7] = {0};
	print(visited,7);
	if(visited[start->data]==0)
	{
		cout<<start->data<<" ";
		visited[start->data] = 1;

			dfs(a,a[start->data],n);
		    if(start->next!=nullptr)
			{
				start->next;
			}

	}
	else
	{
		dfs(a,start->next,n);
	}
}

void print(struct node *t)
{
    while(t)
    {
        cout<<t->data<<" ";
        t = t->next;
    }cout<<endl;
}

int main()
{
    struct node **a = new node*[7];
    for(int i = 0 ; i <= 6 ; i++)
    {
        a[i] = nullptr;
    }
    push(a,1,2);
    push(a,1,3);
    push(a,1,5);
    push(a,1,6);
    push(a,2,3);
    push(a,3,1);
    push(a,3,2);
    push(a,3,4);
    push(a,3,5);
    push(a,4,1);
    push(a,4,6);
    push(a,5,3);
    push(a,5,4);
    push(a,6,2);
    push(a,6,4);
    dfs(a,a[1],7);

    return 0;
}
