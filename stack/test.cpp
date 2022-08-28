#include<iostream>
using namespace std;

struct node
{
	char c;
	struct node *next;
}*first;

void push(char x)
{
	struct node *temp = new node;
	temp->c = x;
	if(first==nullptr)
	{
		cout<<temp->c<<" is pushed . ";
		temp->next = nullptr;
		first = temp;
	}
	else
	{
		cout<<temp->c<<" is pushed onto stack . ";
		temp->next = first;
		first = temp;
	}
}

bool pop()
{
	if(first==nullptr)
	{
		return false;
	}
	else
	{
		cout<<first->c<<" is popped. ";
		first = first->next;
		return true;
	}
}

void display()
{
	struct node *s = first;
	while(s!=nullptr)
	{
		cout<<s->c<<" ";
		s = s->next;
	}
}

bool checkparen(string p)
{
	for(int i = 0 ; p[i]!='\0' ; i++)
	{
		if(p[i]=='(')
		{
			push(p[i]);
		}
		else if(p[i]==')')
		{
			bool re = pop();
			if(re==false)
			{
				return false;
			}
		}
	}
	if(first!=nullptr)
		{
			return false;
		}
	else
	{
		return true;
	}
}

int main()
{
	string p = "((a+b))";
	bool res = checkparen(p);
	cout<<res;
}
