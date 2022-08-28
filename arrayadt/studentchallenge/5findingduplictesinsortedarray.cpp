#include<bits/stdc++.h>
using namespace std;

struct aray{
   int a[20];
   int length;
   int size;
};

vector<int> dupelements(struct aray ar)
{
	vector<int> res;
	for(int i = 0 ; i<ar.length ; i++)
	{
		if(ar.a[i]==ar.a[i+1])
		{
			res.push_back(ar.a[i]);
			j = i;
			element = ar.a[i];
			while(ar.a[i]==ar.a[i+1])
			{
				i++;
			}
		}
	}
	return res;
}

int main()
{
	struct aray ar = {{3,6,8,8,10,12,15,15,15,20},10,20};

	vector<int> res = dupelements(ar);

	for(int i = 0 ; i<res.size() ; i++)
	{
		cout<<res[i]<<" ";
	}
}
