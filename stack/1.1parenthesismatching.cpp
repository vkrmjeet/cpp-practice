#include<iostream>
using namespace std;

struct node
{
	char c;
	struct node *next;
};

struct stack
{
	int size;
	struct node *top;
};


void display(struct stack st);

void push(struct stack &st,char c)
{
	struct node *temp = new node;
	temp->c = c;
	if(st.top==nullptr)
	{
		st.top = temp;
		st.top->next = nullptr;
		cout<<c<<" is pushed. ";
	}
	else
	{
		cout<<c<<" is pushed onto top. ";
		temp->next = st.top;
		st.top = temp;
	}
}

bool pop(struct stack &st)
{
	if(st.top->c=='-')
		return false;
	if(st.top==nullptr)
	{
		cout<<"stack is empty";
		return false;
	}
	else
	{
		struct node *temp = st.top;
		st.top = st.top->next;
		cout<<"\n"<<temp->c<<" is popped .";
		free(temp);
		return true;
	}
}


bool checkparen(struct stack &st,string p)
{

	for(int i = 0 ; p[i] != '\0' ; i++)
	{
		if(p[i]=='(')
		{
			push(st,p[i]);
		}
		else if(p[i]==')')
		{
			bool res = pop(st);
			if(res==false)
				return false;
		}
	}
	if(st.top->c=='-')
		return true;
	else
		return false;
}

void display(struct stack st)
{
	struct node *temp = st.top;
	while(temp!=nullptr)
	{
		cout<<temp->c<<" ";
		temp = temp->next;
	}
}

void disp(string p)
{
	for(int i=0 ; p[i] != '\0' ; i++)
	{
		cout<<p[i];
	}cout<<endl;
}

int main()
{
	struct stack st;
	st.top = new node;
	st.top->c='-';
	st.top->next = nullptr;
	string s = "((a+b)))";
	disp(s);
	bool res = checkparen(st,s);

	res ? cout<< " parenthesis matching " : cout<< " parenthesis not matching ";
}
