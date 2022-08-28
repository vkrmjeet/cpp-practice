#include<bits/stdc++.h>
using namespace std;

struct node
{
	char data;
	struct node *next;
}*top;

void push(char c)
{
	struct node *temp = new node;
	if(temp)
	{
		temp->data = c;
		temp->next = top;
		top = temp;
	}
	else
	{
		cout<<"no space left";
		return;
	}
}

char pop()
{
	if(top)
	{
		char temp = top->data;
		struct node *temps = top;
		top = top->next;
		free(temps);
		return temp;
	}
	else
	{
		cout<<"no node exist";
	}
}

void display()
{
	struct node *temp = top;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

int precedence(char c)
{
	if(c=='+'||c=='-')
	{
		return 1;
	}
	else if(c=='/'||c=='*')
	{
		return 2;
	}
	return 0;
}

bool isoperand(char c)
{
	if(c=='+'||c=='-'||c=='/'||c=='*')
	{
		return false;
	}
	else
		return true;
}

char * postfix(char*infix)
{
	char *postfix;
	int len = strlen(infix);
	postfix = new char[len+2];
	int i = 0, j = 0;

	while(infix[i]!='\0')
	{
		if(isoperand(infix[i]))
		{
			postfix[j++] = infix[i++];
		}
		else
		{
			if(precedence(infix[i])>precedence(top->data))
			{
				push(infix[i++]);
			}
			else
			{
				postfix[j++] = pop();
			}
		}
	}

	while(top!=nullptr)
	{
		postfix[j++] = pop();
	}
	postfix[j] = '\0';

	return postfix;
}



int main()
{
	char *infix = "a+b*c-d/e";
	push('#');
	char *postfi = postfix(infix);

	cout<<postfi;

	return 0;
}
