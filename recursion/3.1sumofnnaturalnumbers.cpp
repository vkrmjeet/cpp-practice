#include<iostream>
using namespace std;

int natural(int n)
{
	return n*(n+1)/2;
}

int natura(int i)
{
	if(i==1)
	{
		return 1;
	}
	else
	{
		return i+natura(i-1);
	}
}

int main()
{
	int x=5;
	cout<<natural(x)<<endl;

	cout<<natura(x)<<endl;

	return 0;
}
