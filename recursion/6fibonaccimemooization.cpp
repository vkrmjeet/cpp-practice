//In computing, memoization or memoisation is an optimization technique used primarily to speed up
//computer programs by storing the results of expensive function calls and returning the cached result
//when the same inputs occur again.

#include<bits/stdc++.h>
using namespace std;

int dp[100];

int fibo(int n)
{
	if(n<=1)
	{
		dp[n]=n;
		return n;
	}
	else
	{
		if(dp[n-2]==-1)
		{
			dp[n-2]=fibo(n-2);
		}
		if(dp[n-1]==-1)
			dp[n-1]=fibo(n-1);

		dp[n] = dp[n-1]+dp[n-2];
		return dp[n-1]+dp[n-2];
	}
}

int main()
{
	memset(dp,-1,sizeof(dp));
	cout<<fibo(20);
}
