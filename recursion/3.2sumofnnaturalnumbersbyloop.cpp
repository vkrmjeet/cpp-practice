#include<iostream>
using namespace std;

int natural(int n)
{
	int i=1,s=0;
	for(i;i<=n;i++)
	{
		s=s+i;
	}
	return s;
}

int main()
{
	int x=5;
	cout<<natural(x);

	return 0;
}
