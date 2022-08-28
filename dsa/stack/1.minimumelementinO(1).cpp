#include<stack>
#include<iostream>
using namespace std;

class getminstack
{
public:
	stack<int> s;
	int min;
	void push(int x);
	int pop();
	int top();
	bool isempty();
	int getmin();
};

void getminstack::push(int x)
{
	if(s.empty())
	{
		min = x;
		s.push(x);
	}
	else
	{
		if(x>=min)
		{
			s.push(x);
		}
		else
		{
			s.push(2*x-min);
			min = x;
		}
	}
}

int getminstack::pop()
{
	if(s.empty())
	{
		return -1;
	}
	else
	{
		int var = s.top();
		s.pop();
		if(var>min)
		{
			return var;
		}
		else
		{
			int prevmin = min;
			min = 2*min - var;
			return prevmin;
		}
	}
}

int getminstack::top()
{
	if(s.empty())
	{
		return -1;
	}
	else
	{
		int x = s.top();
		if(x>min)
		{
			return x;
		}
		else
		{
			return min;
		}
	}
}

bool getminstack::isempty()
{
	return s.empty();
}

int getminstack::getmin()
{
	return s.empty() ? -1 : min;
}


int main()
{
	getminstack s;
	s.push(7);
	s.push(6);
	s.push(5);
	s.push(4);
	cout<<"minimum element : "<<s.getmin()<<endl;
	cout<<"popped : " <<s.pop()<<endl;
	cout<<"minimum element : "<<s.getmin()<<endl;
	cout<<"popped : " <<s.pop()<<endl;
	cout<<"minimum element : "<<s.getmin()<<endl;
	cout<<"popped : " <<s.pop()<<endl;
	cout<<"minimum element : "<<s.getmin()<<endl;
	cout<<"popped : " <<s.pop()<<endl;
	cout<<"minimum element : "<<s.getmin()<<endl;
	cout<<"minimum element : "<<s.getmin()<<endl;



    return 0;
}
