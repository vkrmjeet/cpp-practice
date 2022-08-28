#include<iostream>
using namespace std;

void fun(int i)
{
	if(i>0)
	{fun(i-1);
		cout<<i<<endl;

	}
}

int main()
{
	int x=3;
	fun(x);
}
