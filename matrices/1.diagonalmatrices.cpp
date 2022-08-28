#include<iostream>
using namespace std;

struct matrix{
   int a[10];
   int n;
};

void setm(struct matrix *m,int i , int j , int x)
{
	if(i==j)
	{
		m->a[i-1] = x;
	}
}

int get(struct matrix m, int i , int j)
{
	if(i==j)
		return m.a[i-1];
	else
		return 0;
}

void display(struct matrix m)
{
	int i , j;
	for(i = 0 ; i<m.n ; i++)
	{
		for(j = 0 ; j<m.n ; j++)
		{
			if(i==j)
				cout<<m.a[i];
			else
				cout<<0;
		}cout<<endl;
	}
}

int main()
{
	struct matrix m;
	m.n=4;

	setm(&m,1,1,5);
	setm(&m,2,2,7);
	setm(&m,3,3,4);
	setm(&m,4,4,10);

	display(m);

	return 0;
}
