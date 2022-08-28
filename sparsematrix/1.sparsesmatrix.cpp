#include<iostream>
using namespace std;

struct element
{
	int i ;
	int j;
	int x;
};

struct sparse
{
	int m;
	int n;
	int num;
	struct element *e;
};

void create(struct sparse *s)
{
	cout<< "Enter number of rows : ";
	cin>>s->m;
	cout<< "Enter number of Columns : ";
	cin>>s->n;

	cout<< "Enter number of non zero elemens : ";
	cin>>s->num;

	s->e = new element[s->num];

	cout<< "Enter all the elements"<<endl;
	for(int i = 0 ; i<s->num ; i++)
	{
		cout<< "Enter Row : ";
		cin>>s->e[i].i;
		cout<< "Enter column : ";
		cin>>s->e[i].j;
		cout<< "Enter element : ";
		cin>>s->e[i].x;
	}
}

void print(struct sparse s)
{
	if(s.num>0)
	{
		int k = 0;
		for(int i = 0 ; i<s.m ; i++)
		{
			for(int j = 0 ; j<s.n ; j++)
			{
				if(s.e[k].i == i && s.e[k].j == j)
				{
					cout<<s.e[k++].x;
				}
				else
				{
					cout<<0;
				}
			}cout<<endl;
		}
	}
	else
	{
		cout<< " Empty sparse matrix ";
	}
}

int main()
{
	struct sparse s;
	create(&s);

	print(s);
}
