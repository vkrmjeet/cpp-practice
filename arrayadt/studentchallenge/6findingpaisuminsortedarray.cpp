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

void pairsum(struct aray ar,int key)
{
	int i = 0, j = ar.length;
	while(i<j)
	{
		if(ar.a[i]+ar.a[j]==key)
		{
			cout<<ar.a[i]<<" + "<<ar.a[j]<< " = "<<key<<endl;
			i++;
			j++;
		}
		else if(ar.a[i]+ar.a[j]<key)
		{
			i++;
		}
		else
		{
			j--;
		}
	}
}

int main()
{
	struct aray ar = {{1,3,4,6,8,9,10,12,14},10,20};
	int key = 10;
	cout<<max(ar);
    pairsum(ar,key);

	return 0;
}
