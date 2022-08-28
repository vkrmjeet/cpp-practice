#include<bits/stdc++.h>
using namespace std;

struct aray {
   int a[10];
   int length;
   int size;
};

aray intersectionsorted(struct aray ar1, struct aray ar2)
{
	struct aray c3 = {{0},ar1.length+ar2.length, ar1.length+ar2.length};
	int i =0 , j = 0,k = 0;
	while(i<ar1.length && j <ar2.length)
	{
		if(ar1.a[i]<ar2.a[j])
		{
			i++;
			c3.length--;
		}
		else if(ar2.a[j]<ar1.a[i])
		{
			j++;
			c3.length--;
		}
		else
		{
			c3.a[k++] = ar1.a[i++];
			j++;
			c3.length--;
		}
	}
	return c3;
}

int main ()
{
	struct aray ar1 = {{2,3,10,18,25},5,10};
	struct aray ar2 = {{3,4,7,18,20},5,10};

	 struct aray res = intersectionsorted(ar1,ar2);
	for(int i = 0 ; i<res.length-1; i++)
	{
		cout<<res.a[i]<<" ";
	}
}
