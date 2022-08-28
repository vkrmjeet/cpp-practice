#include<iostream>
using namespace std;

class symm{
private:
	int *a;
	int n;
public:
	symm(int x)
	{
		n = x;
		a = new int[3*n-2];
	}
	void setm(int i, int j , int x)
	{
		if(i-j==0)
		{
			int pos = 0;
			pos = n - 1 + i - 1;
			a[pos] = x;
		}
		else if(i-j>0)
		{
			int pos = 0;
			pos = i-2;
			a[pos] = x;
		}
		else if(i-j<0)
		{
			int pos = 0 ;
			pos = 2*n - 1 + i -1;
			a[pos] = x;
		}
		else
		{
			//do nothing
		}
	}
	void display()
	{
		for(int i = 1 ; i<=n ; i++)
		{
			for(int j = 1; j<=n ; j++)
			{
				if(i-j==0)
		        {
			int pos = 0;
			pos = n - 1 + i - 1;
			cout<<a[pos];
		}
		else if(i-j>0 && i-j<=1)
		{
			int pos = 0;
			pos = i-2;
			cout<<a[pos];
		}
		else if(i-j<0 && i-j>=-1)
		{
			int pos = 0 ;
			pos = 2*n - 1 + i -1;
			cout<<a[pos];
		}
		else
		{
			cout<<0;
		}
			}cout<<endl;
		}
	}
};

int main()
{
	symm l(5);

	l.setm(1,1,2);
	l.setm(1,2,3);
	l.setm(2,1,4);
	l.setm(2,2,5);
	l.setm(2,3,6);
	l.setm(3,2,7);
	l.setm(3,3,8);
	l.setm(3,4,2);
	l.setm(4,3,9);
	l.setm(4,4,1);
	l.setm(4,5,2);
	l.setm(5,4,3);
	l.setm(5,5,4);

	l.display();
}
