#include<iostream>
using namespace std;

void swap(int  x, int y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
	cout<<"after : "<<x<<" and "<<y<<endl;
}
void swapref(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void swapadd(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int a,b;
	a = 10;
	b = 20;
	cout<<"parameter passing by value"<<endl;
	cout<<"before : "<<a<<" and "<<b<<endl;
	swap(a,b);

	cout<<"\n \n \n";

	int c,d;
	c = 10;
	d = 20;
	cout<<"parameter passing by reference"<<endl;
	cout<<"before : "<<c<<" and "<<d<<endl;
	swapref(c,d);
	cout<<"after : "<<c<<" and "<<d<<endl;
	cout<<"\n \n \n";


	int e,f;
	e = 10;
	f = 20;
	cout<<"parameter passing by address"<<endl;
	cout<<"before : "<<e<<" and "<<f<<endl;
	swapadd(&e,&f);
	cout<<"after : "<<e<<" and "<<f<<endl;
	cout<<"\n \n \n";
}
