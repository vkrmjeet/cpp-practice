#include<iostream>
using namespace std;

int add(int a, int b)
{
	return a+b;
}

int main()
{
	int x,y,z;
	x=10;
	y=20;
	z = add(x,y);
	cout<<z<<endl;
}
