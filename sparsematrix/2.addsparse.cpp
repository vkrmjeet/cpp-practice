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

void print(struct sparse *s)
{
	if(s->num>0)
	{
		int k = 0;
		for(int i = 0 ; i<s->m ; i++)
		{
			for(int j = 0 ; j<s->n ; j++)
			{
				if(s->e[k].i == i && s->e[k].j == j)
				{
					cout<<s->e[k++].x;
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

int adds(struct sparse s1,struct sparse s2)
{
	if(s1.m != s2.m && s1.n != s2.n)
	{
		return 0;
	}
	sparse *sum;
	sum = new sparse;
	sum->m = s1.m;
	sum->n = s1.n;

	sum->num = s1.num + s2.num ;

	sum->e = new element[sum->num];

	int i = 0 , j = 0 , k= 0;
	while(i<s1.num && j<s2.num)
	{
		if(s1.e[i].i<s2.e[j].i)
		{
			sum->e[k++] = s1.e[i++];
		}
		else if(s1.e[i].i>s2.e[j].i)
		{
			sum->e[k++] = s2.e[j++];
		}
		else
		{
			if(s1.e[i].j<s2.e[j].j)
			{
				sum->e[k++] = s1.e[i++];
			}
			else if(s1.e[i].j>s2.e[j].j)
			{
				sum->e[k++] = s2.e[j++];
			}
			else
			{
				sum->e[k] = s1.e[i];
		     	sum->e[k].x = s1.e[i].x+s2.e[j].x;
		    	k++,i++,j++;
			}
		}
	}
	for(;i<s1.num;i++){sum->e[k++] = s1.e[i];}
	for(;j<s2.num;j++){sum->e[k++] = s2.e[j];}
	cout<< "\nfirst matrix \n";
	print(s1);
	cout<< "\nsecond matrix \n";
	print(s2);
	cout<< "\nsum matrix \n";
	print(*sum);

}

int main()
{
	struct sparse s;
	struct sparse s2;
	create(&s);
	create(&s2);

	adds(s,s2);

}
