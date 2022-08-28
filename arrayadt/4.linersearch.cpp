#include <bits/stdc++.h>

using namespace std;

struct aray{
    int a[10];
    int size;
    int length;
};

void display(struct aray arr)
{
	//displaying elements of the array
	int i ;
	cout<< "elements in the array : ";
	for(int i=0 ; i<arr.length ; i++)
	{
		cout<<arr.a[i]<<" ";
	}
}

int linearsearch(struct aray *ar,int x)
{
	for(int i=0; i<ar->length; i++ )
	{
		if(ar->a[i]==x)
		{
			return i;
		}
	}
	return -1;
}

void swap(int *x,int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int linearsearchwithtransposition(struct aray *ar,int x)
{
	for(int i=0; i<ar->length; i++ )
	{
		if(ar->a[i]==x)
		{
			swap(ar->a[i],ar->a[i-1]);
			return i;
		}
	}
	return -1;
}

int main()
{
    struct aray ar = {{1,2,3,4,5},10,5} ;
	display(ar);
	cout<<endl;
	int z = linearsearchwithtransposition(&ar,3);
	z==-1 ? cout<<"element not found in the array" : cout<<"element found at position : "<<z<<endl;
	z = linearsearchwithtransposition(&ar,3);
	z==-1 ? cout<<"element not found in the array" : cout<<"element found at position : "<<z<<endl;

    return 0;
}
