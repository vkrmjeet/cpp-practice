#include<iostream>
using namespace std;

struct stack
{
	int size;
	int top;
	int *s;
};

void create(struct stack &p)
{
	cout<<"please enter size of stack : ";
 	cin>>p.size;
 	p.s = new int[p.size];
 	p.top = -1;
 	for(int i = 0 ; i<p.size ; i++)
	{
		cout<<"Enter element : ";
		cin>>p.s[i];
		p.top++;
		cout<<endl;
	}
}

void display(struct stack p)
{
	int var = p.top ;
	while(var!=-1)
	{
		cout<<p.s[var]<<" ";
		var--;
	}
}

int push(struct stack &s,int ele)
{
	s.s[s.top+1] = ele;
	s.top++;
	cout<<endl;
	cout<<ele<<" has been pushed on stack " <<endl;
}

void pop(struct stack &s)
{
	int ele = s.s[s.top];
	s.top--;
 	cout<<endl;
	cout<<ele<<" has been popped from the stack "<<endl;
}

void peek(struct stack s, int index)
{
	if(index-1>s.top || index-1<-1)
	{
		cout<< "\n index not present in the stack ";
	}
	else
	{
		cout<<"\nelement at index : "<<index<<" is "<<s.s[index-1]<<endl;
	}
}

void top(struct stack s)
{
	cout<<" topmost element is : "<<s.s[s.top]<<endl;
}

bool isempty(struct stack s)
{
	if(s.top==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isfull(struct stack s)
{
	cout<<"\n top "<<s.top<<" \n size "<<s.size<<endl;
	if(s.top!=s.size-1)
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
	struct stack st;
	create(st);
	display(st);

	push(st,6);
	display(st);

	pop(st);
	display(st);

	peek(st,-1);

	bool isemp = isempty(st);
	isemp ? cout<< "\nstack is empty" : cout<<"\nstack is not empty";

	bool isful = isfull(st);
	isful ? cout<<"\n stack is full " : cout<<"\n stack is not full";
}
