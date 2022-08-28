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
public:
	int m ;
	int n ;
	int num ;
	element *e;

	sparse(int m,int n,int num)
	{
		this->m = m;
		this->n = n;
		this->num = num;
		e = new element[this->num];
	}

	~sparse()
	{
		delete []e;
	}

	sparse operator+(sparse &s);

	friend istream & operator>>(istream &is , sparse &s);
	friend ostream & operator<<(ostream &os , sparse &s);
};

istream & operator>>(istream &is , sparse &s)
	{
		cout<<"Enter non zero elements \n";
		for(int i = 0 ; i<s.num ; i++)
		{
			cout<< "Enter Row : ";
			cin>>s.e[i].i;
			cout<< "Enter column : ";
			cin>>s.e[i].j;
			cout<<"Enter Element : ";
			cin>>s.e[i].x;
		}
		return is;
	}
 ostream & operator<<(ostream &os , sparse &s)
	{
		int k = 0;
		for(int i = 0 ; i<s.m ; i++)
		{
			for(int j = 0 ; j<s.n ; j++)
			{
				if(i==s.e[k].i && j==s.e[k].j)
				{
					cout<<s.e[k++].x;
				}
				else
				{
					cout<<0;
				}
			}cout<<endl;
		}
		return os;
	}

sparse sparse::operator+(sparse &s)
{
	int i,j,k;
	if(m!=s.m || n!=s.n)
	{
		return sparse(0,0,0);
	}
	sparse *sum = new sparse(m,n,num+s.num);

	i=j=k=0;
	while(i<num && j<s.num)
	{
		if(e[i].i<s.e[j].i)
		{
			sum->e[k++] = e[i++];
		}
		else if (e[i].i>s.e[i].j)
		{
			sum->e[k++] = s.e[j++];
		}
		else
		{
			if(e[i].j<s.e[j].j)
			{
				sum->e[k++] = e[i++];
			}
			else if (e[i].j>s.e[j].j)
			{
				sum->e[k++] = s.e[j++];
			}
			else
			{
				sum->e[k] = s.e[i];
				sum->e[k++].x = e[i++].x + s.e[j++].x;
			}
		}
	}
	for(;i<num ; i++)
	{
		sum->e[k++] = e[i];
	}
	for(;j<s.num ; j++)
	{
		sum->e[k++] = e[j];
	}
	sum->num = k ;
}

int main()
{
	sparse s(5,5,5);
	sparse s1(5,5,5);
	cin>>s;
	cin>>s1;

	sparse sum = s1+s;

	cout<<s<<endl;
	cout<<s1<<endl;
	cout<<sum<<endl;
}
