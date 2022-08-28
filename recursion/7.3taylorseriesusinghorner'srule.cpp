#include<iostream>
using namespace std;

//iterative function
double horner(int x, int n)
{
	static double res = 1;
	for(; n>0 ; n--)
	{
		res = 1 + res*x/n;
	}
	return res;
}

//recursive function
double e(int x,int n)
{
	static double s=1;
	if(n==0)
	{
		return s;
	}
	else{
		s = 1 + x*s/n;
	}
	return e(x,n-1);
}

int main()
{
	cout<<horner(3,10)<<endl;
	cout<<e(3,10)<<endl;
	return 0;
}
