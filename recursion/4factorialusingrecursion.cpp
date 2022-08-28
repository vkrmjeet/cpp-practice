#include<iostream>
using namespace std;

//factorial using recursion
int factorial(int n)
{
	if(n==0)
	{
		return 1;
	}
	else
	{
		return n*factorial(n-1);
	}
}

//factorial using loop
int factori(int n)
{
	int res=1;
	for(int i=1 ; i<=n ; i++)
	{
		res *= i;
	}
	return res;
}

int main()
{
	int x=5;
	cout<<"factorial of "<<x<< " using recursion is : " <<factorial(x)<<endl;
	cout<<"factorial of "<<x<< " using loop is is : " <<factori(x);
}
