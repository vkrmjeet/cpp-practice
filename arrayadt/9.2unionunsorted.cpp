#include<bits/stdc++.h>
using namespace std;

struct aray {
   int a[10];
   int length;
   int size;
};

bool ispresent(int x,struct aray ar)
{
	for(int i=0 ; ar.length ; i++)
	{
		if(x==ar.a[i])
		{
			return false;
		}
	}
	return true;
}

aray unionsorted(struct aray ar1, struct aray ar2)
{
	struct aray c3 = {{0},ar1.length+ar2.length, ar1.length+ar2.length};
	int i =0 , j = 0,k = 0;
	while(i<ar1.length)
	{
	if(ispresent(ar1.a[i],ar2)==true)
		{
			c3.a[k++] = ar1.a[i++];
		}
		else
		{
			i++;
		}
	}
	for(; j < ar2.length ; j++)
	{
		c3.a[k++] = ar2.a[j];
	}
	c3.length = k;
	return c3;
}

int main ()
{
	struct aray ar1 = {{6,3,9,7,5},5,10};
	struct aray ar2 = {{8,2,5,3,7},5,10};

	struct aray res = unionsorted(ar1,ar2);
	for(int i = 0 ; i<res.length ; i++)
	{
		cout<<res.a[i]<<" ";
	}
}
