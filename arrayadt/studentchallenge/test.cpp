#include<bits/stdc++.h>
using namespace std;

void pattern(int n)
{
	for(int i = n ; i >= 1 ; i--)
	{
		for(int j = n ;  j >= 1 ; j--)
		{
			if(j<i) cout<<i;
			else cout<<j;
		}
		for(int j = 2 ; j<=n ; j++)
		{
			if(i>j) cout<<i;
			else  cout<<j;
		}cout<<endl;
	}
	for(int i = 2 ; i <= n ; i++)
	{
		for(int j = n ;  j >= 1 ; j--)
		{
			if(j<i) cout<<i;
			else cout<<j;
		}
		for(int j = 2 ; j<=n ; j++)
		{
			if(i>j) cout<<i;
			else  cout<<j;
		}cout<<endl;
	}
}


int main()
{
	pattern(5);

	return 0;
}
