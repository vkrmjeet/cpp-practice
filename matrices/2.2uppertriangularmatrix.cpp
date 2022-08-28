#include<iostream>
using namespace std;

class uppt{
private:
	int *a;
	int n;
public:
	uppt(int x)
	{
		n = x;
		int y = (n*(n+1)/2);
		cout<< "size"<<y<<endl;
		a = new int[y];
	}
	void setm(int i, int j , int x)
	{
		if(i<=j)
		{
			int position = 0;
			position = (n*(i-1)-(i-2)*(i-1)/2) + j - i ;
			cout<< "position "<<position<<endl;
			a[position] = x;
		}
	}
	void display()
	{
		int pos=0;
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1 ; j <= n ; j++)
			{
				if(i<=j)
				{
					int position = 0 ;
					position = (n*(i-1)-(i-2)*(i-1)/2) + j - i ;
					cout<<a[position];
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
	uppt l(4);
	l.setm(1,1,2);
	l.setm(1,2,3);
	l.setm(1,3,4);
	l.setm(1,4,5);
	l.setm(2,2,6);
	l.setm(2,3,7);
	l.setm(2,4,8);
	l.setm(3,3,9);
	l.setm(3,4,1);
	l.setm(4,4,2);

	l.display();

	return 0;
}
