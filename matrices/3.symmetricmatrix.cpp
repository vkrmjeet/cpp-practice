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
		a = new int[n];
	}
	void setm(int i, int j , int x)
	{
		if(i>=j) // we are taking lower triangular form
		{
			int position = 0;
			position = i*(i-1)/2+j-1;
			a[position] = x;
		}
	}
	void display()
	{
		for(int i = 1 ; i<=n ; i++)
		{
			for(int j = 1; j<=n ; j++)
			{
				if(i>=j)
				{
					int position = 0 ;
					position = i*(i-1)/2+j-1;
					cout<<a[position];
				}
				else
				{
					int position = 0 ;
					position = j*(j-1)/2+i-1;
					cout<<a[position];
				}
			}cout<<endl;
		}
	}
};

int main()
{
	symm l(4);

	l.setm(1,1,2);
	l.setm(2,1,3);
	l.setm(2,2,4);
	l.setm(3,1,5);
	l.setm(3,2,6);
	l.setm(3,3,7);
	l.setm(4,1,8);
	l.setm(4,2,2);
	l.setm(4,3,9);
	l.setm(4,4,1);

	l.display();
}
