#include<iostream>
using namespace std;

class element
{
public:
	int i ;
	int j ;
	int x ;
};

class sparse
{
private:
	int m ;
	int n ;
	int num ;
	element *e;
public:
	sparse(int m,int n,int num)
	{
		this->m = m;
		this->n = n;
		this->num = num;
		e = new element[this->num];
	}

	void read()
	{
		cout<<"Enter non zero elements \n";
		for(int i = 0 ; i<num ; i++)
		{
			cout<< "Enter Row : ";
			cin>>e[i].i;
			cout<< "Enter column : ";
			cin>>e[i].j;
			cout<<"Enter Element : ";
			cin>>e[i].x;
		}
	}

	void print()
	{
		int k = 0;
		for(int i = 0 ; i<m ; i++)
		{
			for(int j = 0 ; j<n ; j++)
			{
				if(i==e[k].i && j==e[k].j)
				{
					cout<<e[k++].x;
				}
				else
				{
					cout<<0;
				}
			}cout<<endl;
		}
	}
	~sparse()
	{
		delete []e;
	}
};



int main()
{
	sparse s(5,5,5);
	s.read();
	s.print();
}
