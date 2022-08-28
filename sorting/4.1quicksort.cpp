#include<iostream>
#include<limits.h>
using namespace std;

void swap(int &a,int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int partition(int arr[], int low , int high)
{
	int pivot = arr[low];
	int i = low , j = high;

	do
	{
		do{i++;} while (pivot >= arr[i]);
		do{j--;} while (pivot < arr[j]);
		if(i<j)
		{
			swap(arr[i],arr[j]);
		}
	}while (i<j);
	swap(arr[low],arr[j]);
	return j;
}

void quicksort(int arr[], int low , int high)
{
	int j;
	if(low<high)
	{
		j = partition(arr,low,high);
		quicksort(arr,low,j);
		quicksort(arr,j+1,high);
	}
}

display(int arr[],int m, int n)
{
	for(int i = m ; i< n ; i++)
	{
		cout<<arr[i]<<" ";
	}cout<<endl;
}

int main()
{
	int arr[] ={8,7,6,5,4,3,2,INT_MAX};
	int n = sizeof(arr)/sizeof(arr[0]);
	display(arr,0,n-1);
	quicksort(arr,0,n-1);
	display(arr,0,n-1);
	return 0;
}
