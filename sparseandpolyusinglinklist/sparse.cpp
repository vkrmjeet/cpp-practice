#include<iostream>
using namespace std;

struct node
{
	int column;
	int data;
	struct node *next;
};

struct sparse
{
	int m;
	int n;
	struct node *a;
};

void create(struct sparse &st)
{
	for(int i = 0 ; i < st.m ; i++)
	{
		int j = 0;
		cout<<"enter non zero elements in "<<i+1<<" row : ";
		cin>>j;
		for(int k = 0 ; k < j ; k++)
		{
			struct node *temp = new node;
			struct node *last;
			if(k=0)
			{
				cout<<"enter column : ";
				cin>>temp->column;
				cout<<"enter value : ";
				cin>>temp->data;
				temp->next = nullptr;
				st.a[i] = temp;
				last = temp;
			}
			else
			{
				cout<<"enter column : ";
				cin>>temp->column;
				cout<<"enter value : ";
				cin>>temp->data;
				temp->next = nullptr;
				last->next = temp;
				last = temp;
			}
		}
	}
}

void display(struct sparse s)
{
	for(int i = 0 ; i<s.m ; i++)
	{cout<<i<<endl;
		struct node *temp = s.a[i].next;
		for(int j=0 ; j<s.n ; j++)
		{
			if(temp->column==j)
			{
				cout<<temp->data<<" ";
			}
			else
			{
				cout<<"0 ";
			}
		}cout<<endl;
	}
}

int main()
{
	struct sparse st;
	cout<<"enter rows : ";
	cin>>st.m;
	cout<<"enter columns : ";
	cin>>st.n;
	st.a = new node[st.m];
	create(st);
	display(st);
}
