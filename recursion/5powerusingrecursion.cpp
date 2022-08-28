#include<iostream>
using namespace std;

int power(int n,int m)
{
	if(m==0)
	{
		return 1;
	}
	else
	{
		return n*power(n,m-1);
	}
}

int main()
{
	int x=5,n=4;
	cout<<x<< " raise to the power "<<n<< " is "<<power(x,n);
}
