#include<bits/stdc++.h>
using namespace std;

struct aray{
   int a[20];
   int length;
   int size;
};

vector<int> dupelements(struct aray ar,struct aray hashh)
{
	vector<int> res;
	for(int i = 0 ; i<ar.length ; i++)
	{
		int temp = ar.a[i];
		hashh.a[temp]++;
	}
	for(int i = 0 ; i<hashh.length ; i++)
	{
		if(hashh.a[i]>1)
		{
			cout<<i<< " is repeated "<<hashh.a[i]<< " times "<<endl;
		}
	}
	return res;
}

int main()
{
	struct aray ar = {{3,6,8,8,10,12,15,15,15,20},10,20};
	struct aray hashh = {{0},ar.length*2-1,ar.size*2};

	vector<int> res = dupelements(ar,hashh);

}
