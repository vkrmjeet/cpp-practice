#include<iostream>
#include<limits.h>
using namespace std;

void swap(int &a , int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void display(int arr[], int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void Merge(int arr[],int low,int mid, int high)
{
	int b[high+1];
	int i = low;
	int j = mid+1;
	int k = low;
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
		b[k++] = arr[i];
	}
	for(int l = low ; l<=high ; l++)
	{
		arr[l] = b[l];
	}
}

void mergesort(int arr[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid = (low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		Merge(arr,low,mid,high);
	}
}

int main()
{
    int arr[] = {10,9,8,4,3,1,2,7,8,7,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<< "Before sorting : "; display(arr,n);

    mergesort(arr,0,n-1);

    cout<<"after soritng : "; display(arr,n);


    return 0;
}
