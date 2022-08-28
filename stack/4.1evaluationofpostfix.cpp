#include<bits/stdc++.h>
using namespace std;

struct node
{
	char data;
	struct node *next;
}*top;

struct nood
{
	int data;
	struct nood *next;
}*too;

void pus(int c)
{
	struct nood *temp = new nood;
	if(temp)
	{
		temp->data = c;
		temp->next = too;
		too = temp;
	}
	else
	{
		cout<<"no space left";
		return;
	}
}

int po()
{
	if(top)
	{
		int temp = too->data;
		struct nood *temps = too;
		too = too->next;
		free(temps);
		return temp;
	}
	else
	{
		cout<<"no node exist";
	}
}


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

int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')'){
        return 0;
    }
    return 1;
}

int outPrecedence(char x){
    if (x == '+' || x == '-'){
        return 1;
    } else if (x == '*' || x == '/'){
        return 3;
    } else if (x == '^'){
        return 6;
    } else if (x == '('){
        return 7;
    } else if (x == ')'){
        return 0;
    }
    return -1;
}

int inPrecedence(char x){
    if (x == '+' || x == '-'){
        return 2;
    } else if (x == '*' || x == '/'){
        return 4;
    } else if (x == '^'){
        return 5;
    } else if (x == '('){
        return 0;
    }
    return -1;
}

char * postfix(char*infix)
{
	char *postfix;
	int len = strlen(infix);
	postfix = new char[len+2];
	int i = 0, j = 0;

	while(infix[i]!='\0')
	{
		if(isOperand(infix[i]))
		{
			postfix[j++] = infix[i++];
		}
		else
		{
			if(outPrecedence(infix[i])>inPrecedence(top->data))
			{
				push(infix[i++]);
			}
			else if(outPrecedence(infix[i])==inPrecedence(top->data))
			{
				pop();
			}
			else
			{
				postfix[j++] = pop();
			}
		}
	}

	while(top!=nullptr && top->data!=')' && top->data!='#')
	{
		postfix[j++] = pop();
	}
	postfix[j] = '\0';

	return postfix;
}

int eval(char *postfix)
{
	int i = 0;
	int x1,x2,r;

	for(i=0 ; postfix[i]!='\0' ; i++)
	{
		if(isOperand(postfix[i]))
		{
			pus(postfix[i]-'0');
		}
		else
		{
			x2=po(); x1=po();
			switch(postfix[i])
			{
				case '+' : r = x1+x2;cout<<"r = "<<x1<<"+"<<x2<<endl; break;
				case '-' : r = x1-x2; cout<<"r = "<<x1<<"-"<<x2<<endl; break;
				case '*' : r = x1*x2; cout<<"r = "<<x1<<"*"<<x2<<endl; break;
				case '/' : r = x1/x2; cout<<"r = "<<x1<<"/"<<x2<<endl; break;
			}
			pus(r);
		}
	}return too->data;
}

int main()
{
	char *infix = "2+3*4-8/2";
	push('#');
	char *postfi = postfix(infix);
	cout<<postfi<<endl;
	pus(-1);
	cout<<eval(postfi);



	return 0;
}
