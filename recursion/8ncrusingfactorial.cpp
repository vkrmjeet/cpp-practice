#include<iostream>
using namespace std;

int fact(int n)
{
	int res=1;
	for(int i=1 ; i<=n ; i++)
	{
		res *= i;
	}
	return res;
}

int ncr(int n,int r)
{
	int res=0;
	return fact(n)/(fact(r)*fact(n-r));
}

int main()
{
	cout<<ncr(5,3);
}
