#include<stack>
#include<iostream>
using namespace std;

class getmaxstack
{
public:
	stack<int> s;
	int max;
	void push(int x);
	int pop();
	int top();
	bool isempty();
	int getmax();
	void print();
};

void getmaxstack::print()
{
	stack<int> temp = s;
	int i = s.size();
	while(!s.empty())
	{
		cout<<"["<<i<<"] Element : "<<  s.top()<<endl;
		i--;
		s.pop();

	}
}

void getmaxstack::push(int x)
{
	if(s.empty())
	{
		max = x;
		s.push(x);
	}
	else
	{
		if(x<=max)
		{
			s.push(x);
		}
		else
		{
			s.push((2*x)+max);
			max = x;
		}
	}
}

int getmaxstack::pop()
{
	if(s.empty())
	{
		return -1;
	}
	else
	{
		int var = s.top();
		s.pop();
		if(var<max)
		{
			return var;
		}
		else
		{
			int prevmin = max;
			max = var - (2 * max);
			return prevmin;
		}
	}
}

int getmaxstack::top()
{
	if(s.empty())
	{
		return -1;
	}
	else
	{
		int x = s.top();
		if(x<max)
		{
			return x;
		}
		else
		{
			return max;
		}
	}
}

bool getmaxstack::isempty()
{
	return s.empty();
}

int getmaxstack::getmax()
{
	return s.empty() ? -1 : max;
}


int main()
{
	getmaxstack s;
	s.push(7);
	s.push(8);
	s.push(9);
	s.push(10);
	s.print();
	cout<<"maximum element : "<<s.getmax()<<endl;
	cout<<"popped : " <<s.pop()<<endl;
	cout<<"maximum element : "<<s.getmax()<<endl;
	cout<<"popped : " <<s.pop()<<endl;
	cout<<"maximum element : "<<s.getmax()<<endl;
	cout<<"popped : " <<s.pop()<<endl;
	cout<<"maximum element : "<<s.getmax()<<endl;
	cout<<"popped : " <<s.pop()<<endl;
	cout<<"maximum element : "<<s.getmax()<<endl;
	cout<<"maximum element : "<<s.getmax()<<endl;



    return 0;
}
