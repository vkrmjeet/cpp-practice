#include<iostream>
using namespace std;

struct stack
{
	int size;
	int *a;
	int top;
};

void push(struct stack *s,int x)
{
	if(s->top!=s->size)
	{
			s->top++;
			s->a[s->top] = x;
		    cout<<x<<" is inserted."<<endl;
	}
}

int pop(struct stack *s1,struct stack *s2)
{
	if(s2->top!=0)
	{
		int x = s2->a[s2->top];
		s2->top--;
		cout<<x<<" is popped. ";
	}
	else if(s1->top!=0)
	{
		while(s1->top!=0)
		{
			int x = s1->a[s1->top];
			push(s2,x);
			s1->top--;
		}
		int x = s2->a[s2->top];
		s2->top--;
		cout<<x<<" is popped."<<endl;;
	}
	else
	{
		cout<<"queue is empty.";
	}
}

int main()
{
	struct stack s1;
	struct stack s2;

	s1.size = 10;
	s2.size = 10;

	s1.a = new int[s1.size];
	s2.a = new int[s1.size];

	s1.top = -1;
	s2.top = 0;

	push(&s1,-1);
	push(&s1,4);
	push(&s1,5);
	push(&s1,6);
	push(&s1,7);
	push(&s1,8);

	pop(&s1,&s2);
	pop(&s1,&s2);

	return 0;
}
