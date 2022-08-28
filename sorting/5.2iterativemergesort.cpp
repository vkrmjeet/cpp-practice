#include<iostream>
using namespace std;

void merge(int arr[],int low , int mid , int high)
{
	int b[high+1];
	int i , j , k;
	i = k = low ; j = mid+1;

	while(i<=mid && j<=high)
	{
		if(arr[i]<arr[j])
		{
			b[k++] = arr[i++];
		}
		else
		{
			b[k++] = arr[j++];
		}
	}
	for( ; i<=mid ; i++)
	{
		b[k++] = arr[i];
	}
	for( ; j<=high ; j++)
	{
		b[k++] = arr[j];
	}
	for(int i = low ; i<=high ; i++)
	{
		arr[i] = b[i];
	}
}

void mergesort(int arr[], int n)
{
	int p , l , h , mid , i;

	for( p = 2; p<=n ; p = p*2)
	{
		for( i = 0 ; i+p-1 < n ; i = i + p)
		{
			l = i;
			h = i+p - 1;
			mid = (l+h)/2;
			merge(arr,l,mid,h);
		}
		if(n-i>p/2)
		{
			l = i;
			h = i + p -1;
			mid = (l+h)/2;
			merge(arr,l,mid,n - 1);
		}
	}
	if(p/2<n)
	{
		merge(arr,0,p/2-1,n-1);
	}
}

void display(int arr[], int n)
{
	for(int i = 0 ; i<n ; i++)
	{
		cout<<arr[i]<<" ";
	}cout<<endl;
}

int main()
{
	int arr[] = {9,8,7,6,5,4,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	display(arr,n);
	mergesort(arr,n);
	display(arr,n);
}
