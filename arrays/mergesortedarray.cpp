#include<iostream>
using namespace std;

int * mergearrays(int ar1[],int ar2[], int a , int b)
{
	int res[a+b] = {0};
	int i=0,j=0,k=0;
	while(i<a && j<b)
	{
		if(ar1[i]<ar2[j])
		{
			res[k] = ar1[i];
			i++;
			k++;

		}
		else
		{
			res[k] = ar2[j];
			j++;
			k++;
		}
	}
	while(i<a)
	{
		res[k++] = ar1[i++];
	}
	while(j<b)
	{
		res[k++] = ar2[j++];
cout<<res[k];
	}
	return res;
}

int main()
{
	int arr1[] = {1,3,5};
	int arr2[] = {2,4,6,8};
	int n = sizeof(arr1)/sizeof(arr1[0]);
	int m = sizeof(arr2)/sizeof(arr2[0]);

	int *p = mergearrays(arr1,arr2,n,m);

	for(int i=0 ; i<m+n-1 ; i++)
	{
		cout<<*(p+i)<<endl;
	}


}
