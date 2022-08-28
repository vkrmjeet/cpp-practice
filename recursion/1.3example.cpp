#include<iostream>
using namespace std;

void table(int i)
{
	int j=1;
	while(j<=10)
	{
		cout<<j*i<<endl;
		j++;
	}
}

int main()
{
	int x=10;
	table(x);
}
