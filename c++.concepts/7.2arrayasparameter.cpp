#include<iostream>
using namespace std;

void fun(int a[], int  n)
{
	for(int i=0 ; i<n ; i++)
	{
		cout<<a[i]<<endl;
	}
}


int * createdynamicarr(int size)
{
	int *p;
	p = new int[size];

	for(int i=0 ; i<size ; i++)
	{
		p[i] = i+1;
	}

	return p;
}

int main()
{
	int a[4] = {2,4,5,6};
	int n=sizeof(a)/sizeof(int);
	fun(a,n);

	cout<<"\n\n\n";
	int *b,sz=5;
	b = createdynamicarr(sz);

	for(int i=0 ; i<sz ; i++)
	{
		cout<<b[i]<<endl;
	}
	return 0;
}
