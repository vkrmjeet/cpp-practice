#include<iostream>
using namespace std;

int fiboitr(int n)
{
    int	term1 = 0, term2 = 1 , res =0;
	for(int i=0 ; i<n-1 ; i++)
	{
		res = term1 + term2;
		term1 = term2;
		term2 = res;
	}
	return res;
}

int fiborec(int n)
{
	if(n<=1)
		return n;
	else
		return fiborec(n-1)+fiborec(n-2);
}

int main()
{
	cout<<fiboitr(10)<<endl;
	cout<<fiborec(20);
}
