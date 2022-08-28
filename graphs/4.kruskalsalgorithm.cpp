#include<iostream>
#include<limits.h>
using namespace std;


int edges [3][9] = {{1,1,2,2,3,4,4,5,5},
					{2,6,3,7,4,5,7,6,7},
					{25,5,12,10,8,16,14,20,18}};

int set[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
int included[9] = {0};
int t[2][6];

void printarray()
{
	for(int i = 0 ; i < 8 ; i++)
	{
		cout<<set[i]<<" ";
	}cout<<endl;
}

void munion(int u,int v)
{
	if(set[u]<set[v])
	{
		set[u] += set[v];
		set[v] = u;
	}
	else
	{
		set[v] += set[u];
		set[u] = v;
	}
}

int find(int u)
{
	int x = u ,v = 0;
	while(set[x]>0)
	{
		x = set[x];
	}

	while(u!=x)
	{
		v = set[u];
		set[u] = x;
		u = v;
	}
	return x;
}

int main()
{
	int i,j,k,u,v,min=INT_MAX;
	int n=7,e=9;

	i = 0;
	while(i<n-1)
	{
		min = INT_MAX;
		for(j=0; j<e ; j++)
		{
			if(included[j]==0&&edges[2][j]<min)
			{
				u = edges[0][j];
				v = edges[1][j];
				min = edges[2][j];
				k = j;
			}
		}
		if(find(u)!=find(v))
		{
			cout<<"\n " <<find(u)<<" "<<find(v)<<"\n";
			t[0][i] = u;
			t[1][i] = v;
			munion(find(u),find(v));
			i++;
		}
		printarray();
		included[k] = 1;
	}

	for(i=0 ; i < n-1 ; i++)
	{
		cout<<"( "<<t[0][i]<<" , "<<t[1][i]<<" ) "<<endl;
	}

	return 0;
}
