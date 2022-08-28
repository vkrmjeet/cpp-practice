#include<iostream>
using namespace std;

void merge(int arr[],int low, int mid , int high)
{
	int b[high+1];
	int i , j , k;
	i = low; j = mid+1; k = low;
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
	for( i = low ; i <= high ; i++)
	{
		arr[i] = b[i];
	}
}

void quicksort(int arr[],int low , int high)
{
	int mid;
	if(low<high)
	{
		mid = (low+high)/2;
		quicksort(arr,low,mid);
		quicksort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}

void display(int arr[] , int n)
{
	for(int i = 0 ; i<n ; i++)
	{
		cout<<arr[i]<<" ";
	}cout<<endl;
}

int main ()
{
	int arr[] = {10,9,8,4,3,1,2,7,8,7,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	display(arr,n);
	quicksort(arr,0,n-1);
	display(arr,n);
	return 0 ;
}

