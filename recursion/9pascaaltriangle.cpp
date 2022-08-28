#include<iostream>
#include<iomanip>
using namespace std;

long ncr(int n, int r)
{
	if(r==0 || n==r)
		return 1;
	else
		return ncr(n-1,r-1)+ncr(n-1,r);
}

long long pascal(long n)
{
	for(int i=0 ; i<n ; i++)
	{
		// for spaces
		for(int j=0 ; j<n-i-1 ; j++)
		{
			cout<<setw(3)<< " ";
		}
		for(int j=0 ; j<=i ; j++)
		{
			cout<<setw(3)<<ncr(i,j)<<setw(3)<< " ";
		}
		cout<<endl;
	}
}

int main()
{
	cout<<pascal(5);
}
