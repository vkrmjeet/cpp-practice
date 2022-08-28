#include<bits/stdc++.h>
using namespace std;

struct aray{
  int a[20];
  int length;
  int size;
};

//it can also be said as the efficient approach
vector<int> findingmissingelement(struct aray ar)
{
	vector<int>res;
	int diff = ar.a[0];
	for(int i = 0 ; i<ar.length ; i++)
	{
		if(ar.a[i]-i!=diff)
		{
			cout<< "a["<<i<<"]"<<ar.a[i]<<" "<<diff<<endl;
			while(diff<ar.a[i]-i){
			res.push_back(i+diff);
			diff++;
			}
		}
	}
	return res;
}

int main()
{
	struct aray ar = {{1,2,3,4,6,7,8,9,11,12,15},11,15};

	vector<int> res = findingmissingelement(ar);

	for(int i = 0 ; i<res.size(); i++)
	{
		cout<<res[i]<<" ";
	}
}
