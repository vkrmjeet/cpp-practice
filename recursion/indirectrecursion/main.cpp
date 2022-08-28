#include <iostream>

using namespace std;

int funb(int n);
int funa(int n)
{
	if(n>0)
	{
		cout<<n<<endl;
		funb(n-1);
	}
}

int funb(int n)
{
	if(n>1)
	{
		cout<<n<<endl;
		funa(n/2);
	}
}

int main()
{
    int x=20;
    funa(x);
    return 0;
}
