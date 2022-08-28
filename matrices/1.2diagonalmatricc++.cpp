#include<iostream>
using namespace std;


class matric{
private:
	int *a;
	int n;
public:
	matric(int x)
	{
		n = x;
		a = new int[n];
	}

void setm(int i , int j ,int x)
{
	if(i==j)
	{
		a[i-1] = x;
	}
}

int get(int i , int j)
{
	if(i==j)
		return a[i-1];
	else
		return 0;
}

void display()
{
	int i , j;
	for(i = 0 ; i<n ; i++)
	{
		for(j = 0 ; j<n ; j++)
		{
			if(i==j)
				cout<<a[i];
			else
				cout<<0;
		}cout<<endl;
	}
}
};


int main()
{
	matric m(4);
	m.setm(1,1,4);
	m.setm(2,2,5);
	m.setm(3,3,6);
	m.setm(4,4,7);

	m.display();

	return 0;
}
