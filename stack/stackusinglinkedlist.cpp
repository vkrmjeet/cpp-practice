#include<iostream>
using namespace std;

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

struct stack
{
	int size;
	int topp;
	struct node *top;
	struct node *s;
};

void create(struct stack &p)
{
	cout<<"please enter size of stack : ";
 	cin>>p.size;
 	p.s = new node;
 	p.s->prev = nullptr;
 	cout<<"enter element : ";
 	cin>>p.s->data;
 	struct node *last;
 	p.s->next = nullptr;
 	last = p.s;
 	for(int i = 0 ; i<p.size-1 ; i++)
	{
		struct node *temp = new node;
		cout<<"Enter element : ";
		cin>>temp->data;
		temp->prev = last;
		temp->next = nullptr;
		last->next = temp;
		last = temp;
		p.top = last;
		cout<<endl;
	}
}

void display(struct stack p)
{
	struct node *temp = p.top ;
	while(temp!=nullptr)
	{
		cout<<temp->data<<" ";
		temp = temp->prev;
	}
}

int push(struct stack &s,int ele)
{
	struct node *temp = new node;
	temp->data = ele;
	temp->prev = s.top ;
	s.top->next = temp;
	s.top = temp;
	cout<<endl;
	cout<<ele<<" has been pushed on stack " <<endl;
}

void pop(struct stack &s)
{
	struct node *temp = s.top;
	s.top = s.top->prev;
	int ele = temp->data;
	free(temp);
 	cout<<endl;
	cout<<ele<<" has been popped from the stack "<<endl;
}

void peek(struct stack s, int index)
{

}

void top(struct stack s)
{
	cout<<"\ntopmost element is : "<<s.top->data<<endl;
}

bool isempty(struct stack s)
{
	if(s.top==nullptr)
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

	top(st);


	return 0;
}
