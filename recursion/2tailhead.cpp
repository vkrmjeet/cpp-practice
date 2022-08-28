#include<iostream>
using namespace std;

void tail(int n)
{
	if(n>0)
	{
		cout<<n<<endl;
		tail(n-1);
	}
}

int main()
{
	int x=3;
	tail(3);

	return 0;
}
