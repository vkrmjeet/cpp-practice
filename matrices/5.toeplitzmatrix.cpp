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
		a = new int[n+n-1];
	}
	void setm(int i, int j , int x)
	{
		if(i<=j)
		{
			int pos = 0;
			pos = j-i;
			a[pos] = x;
		}
		else if(i>j)
		{
			int pos = 0 ;
			pos = n + i - j - 1;
			a[pos] = x;
		}
	}
	void display()
	{
		for(int i = 1 ; i<=n ; i++)
		{
			for(int j = 1; j<=n ; j++)
			{
				if(i<=j)
		{
			int pos = 0;
			pos = j-i;
			cout<<a[pos];
		}
		else if(i>j)
		{
			int pos = 0 ;
			pos = n + i - j - 1;
			cout<<a[pos];
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
	l.setm(1,3,4);
	l.setm(1,4,5);
	l.setm(1,5,6);
	l.setm(2,1,7);
	l.setm(3,1,8);
	l.setm(4,1,9);
	l.setm(5,1,1);

	l.display();
}
