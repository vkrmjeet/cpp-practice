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

void selectionsort(int arr[],int n)
{
	for(int i = 0 ; i < n-1 ; i++)
	{
		int lowest = arr[i];
		int pos = i;
		for(int j = i+1 ; j < n ; j++)
		{
			if(arr[j]<lowest)
			{
				lowest = arr[j];
				pos = j;
			}
		}
		swap(arr[i],arr[pos]);
	}
}

int lowest(int arr[],int i,int n)
{
	int lowest = arr[i];
	int pos = i;
	for(int j = i+1 ; j<n ; j++)
	{
		if(lowest>arr[j])
		{
			lowest = arr[j];
			pos = j;
		}
	}
	return pos;
}

void selectionsort2(int arr[],int n)
{
	for(int i = 0 ; i < n-1 ; i++)
	{
		int pos = lowest(arr,i,n);
		swap(arr[i],arr[pos]);
	}
}

int main()
{
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<< "Before sorting : "; display(arr,n);

    selectionsort2(arr,n);

    cout<<"after soritng : "; display(arr,n);


    return 0;
}
