#include<bits/stdc++.h>
using namespace std;

struct aray{
    int a[10];
    int length;
    int size;
};

void display(struct aray ar)
{
	for(int i = 0 ; i<ar.length;i++)
	{
		cout<<ar.a[i]<<" ";
	}cout<<endl;
}

int get(struct aray ar, int index)
{
	if(index>=0 && index<ar.length)
	{
		return ar.a[index];
	}
	return -1;
}

int sete(struct aray *ar, int index,int val)
{
	if(index<ar->length && index>=0)
	{
		ar->a[index]=val;
	}
}

int max(struct aray ar)
{
	int max=-1;
	for(int i = 0 ; i < ar.length ; i++)
	{
		if(max<ar.a[i])
		{
			max = ar.a[i];
		}
	}return max;
}

int min(struct aray ar)
{
	int min = INT_MAX;
	for ( int i = 0 ; i < ar.length ; i++)
	{
		if(min>ar.a[i])
		{
			min = ar.a[i];
		}
	}return min;
}

int total(struct aray ar)
{
	int total = 0;
	for(int i = 0 ; i<ar.length ; i++)
	{
		total += ar.a[i];
	}
	return total;
}

float avg(struct aray ar)
{
	return (float)(total(ar))/ar.length;
}

int main()
{
	struct aray ar = {{1,2,3,4,5},5,10};

	display(ar);
	cout<<max(ar)<<endl;
	cout<<min(ar)<<endl;
	cout<<get(ar,2)<<endl;
	sete(&ar,2,9);
	display(ar);
	cout<<avg(ar)<<endl;
	cout<<total(ar)<<endl;

	return 0;
}
