
#include<bits/stdc++.h>
using namespace std;

struct aray{
   int a[20];
   int length;
   int size;
};

int max(struct aray ar)
{
	int max = INT_MIN;
	for(int i = 0 ; i<ar.length ; i++)
	{
		if(max<ar.a[i])
		{
			max = ar.a[i];
		}
	}
	return max-1;
}

void dupelements(struct aray ar,struct aray hashh)
{
	hashh.length = max(ar);
	for(int i=0 ; i<ar.length ; i++)
	{
		int temp = ar.a[i];
		hashh.a[temp]++;
	}
	for(int i = 0 ; i<hashh.length ; i++)
	{
		if(hashh.a[i]>1)
		{
			cout<<i<< " is repeated "<<hashh.a[i]<< " times"<<endl;
		}
	}
}

int main()
{
	struct aray ar = {{3,6,8,8,10,12,15,15,15,20},10,20};
	struct aray hashh = {{0},1,ar.size*2};

	dupelements(ar,hashh);

}
