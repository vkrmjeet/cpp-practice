#include<iostream>
using namespace std;

class lowt{
private:
	int *a;
	int n;
public:
	lowt(int x)
	{
		n = x;
		int y = (n*(n+1)/2);
		cout<< "size"<<y<<endl;
		a = new int[y];
	}
	void setm(int i, int j , int x)
	{
		if(i>=j)
		{
			int position = 0;
			position = n*(j-1)-(j-1)*(j-2)/2 +i-j;

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
				if(i>=j)
				{
					int position = 0 ;
					position = (n*(j-1)-(j-2)*(j-1)/2)+i-j;
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
	lowt l(4);
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

	return 0;
}
