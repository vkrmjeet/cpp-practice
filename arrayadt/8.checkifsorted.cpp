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

int swap(int *a , int *b)
{
	int temp;
	temp = *a;
	*a = *b ;
	*b = temp;
	return temp;
}

bool issorted(struct aray ar)
{
	for(int i=0 ; i<ar.length-1 ; i++)
	{
		if(ar.a[i]>ar.a[i+1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	struct aray ar = {{1,2,3,4,5},5,10};
    display(ar);
	bool res = issorted(ar);
	res ? cout<<"array is sorted" : cout<< "array is not sorted";

	return 0;
}
