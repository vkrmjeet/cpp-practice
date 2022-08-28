#include<iostream>
using namespace std;

//this is wrong
int power(int m,int n)
{
	if(n==0)
		return 1;
	if(n%2==0)
		return power(m*m,n/2);
	else
		return m*power(m*m,(n-1)/2);
}

int factorial(int n)
{
	int res=0;
	for(int i = 1 ; i <= n ; i++)
	{
		res *= i;
	}
	return res;
}

double taylor(int x,int n)
{
	double res = 1;
	if(n<1)
		return 1;
	else
		{
			int res=0;
			res = 1;
			for(int i = 2 ; i<=n ; i++)
			{
				res += power(x,i)/factorial(i);
			}
		}
		cout<<res;
	return res;
}

int main()
{
	int x=3;
	cout<< "taylor series upto "<<x<<" is "<<taylor(3,10);
}
