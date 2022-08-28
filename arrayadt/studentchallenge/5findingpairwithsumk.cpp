#include<bits/stdc++.h>
using namespace std;

struct aray{
   int a[20];
   int length;
   int size;
};

int max(struct aray ar)
{
	int max= INT_MIN;
	for(int i =0 ; i<ar.length ; i++)
	{
		if(max<ar.a[i])
		{
			max=ar.a[i];
		}
	}
	return max;
}

vector<int> pairsum(struct aray ar,int key)
{
	vector<int> res;
	struct aray hashh = {{0},max(ar),max(ar)};
	for(int i = 0 ; i<ar.length ; i++)
	{
		if(hashh.a[key-ar.a[i]]!=0)
		{
			cout<<ar.a[i]<< " + "<<key-ar.a[i]<< " = "<<key<<endl;
		}
		hashh.a[ar.a[i]]++;
	}

	return res;
}

int main()
{
	struct aray ar = {{1,2,3,4,5,6,7,8,9},10,20};
	int key = 9;
	cout<<max(ar);
	vector<int> res = pairsum(ar,key);

	for(int i = 0 ; i< res.size() ; i++)
	{
		cout<<res[i]<<" ";
	}cout<<endl;

	return 0;
}
