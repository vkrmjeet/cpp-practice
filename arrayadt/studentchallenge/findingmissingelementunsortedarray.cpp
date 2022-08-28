#include<bits/stdc++.h>
using namespace std;

struct aray {
int a[100];
int length;
int size;
};

int maxaray(struct aray ar)
{
	int max = INT_MIN;
	for(int i =0 ; i<ar.length ; i++)
	{
		if(max<ar.a[i])
		{
			max = ar.a[i];
		}
	}
	return max;
}

int minaray(struct aray ar)
{
	int min = INT_MAX;
	for(int i =0 ; i<ar.length ; i++)
	{
		if(min>ar.a[i])
		{
			min = ar.a[i];
		}
	}
	return min;
}

vector<int> findingmissingelement(struct aray ar)
{
	struct aray temp = {{0},maxaray(ar),maxaray(ar)};
	vector<int>res;
	for(int i=0 ; i<ar.length ; i++)
	{
		int var = ar.a[i];
		temp.a[var] = -1;
	}
	for(int i = 1 ; i<temp.length ; i++)
	{
		if(temp.a[i]==0)
		{
			res.push_back(i);
		}
	}
	return res;
}

int main()
{
	struct aray ar = {{3,7,4,9,12,6,1,11,2,10,18},11,100};

	vector<int> res = findingmissingelement(ar);

 	for(int i = 0 ; i<res.size() ; i++)
	{
		cout<<res[i]<<" ";
	}

}
