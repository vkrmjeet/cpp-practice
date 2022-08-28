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
    for(int i = 0 ; i < n - 1 ; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int Parition(int arr[],int low,int high)
{
	int temp = arr[low];
	int i = low;
	int j = high;
	do
	{
		do
		{
			i++;
		}while(arr[i]<=temp);
		do
		{
			j--;
		}while(arr[j]>temp);
		if(i<j)
		{
			swap(arr[i],arr[j]);
		}

	}while(i<j);
	swap(arr[low],arr[j]);
	return j;
}

void quicksort(int arr[],int low,int high)
{
	int j;
	if(low<high)
	{
		j = Parition(arr,low,high);
		quicksort(arr,low,j);
		quicksort(arr,j+1,high);
	}
}

int main()
{
    int arr[] = {10,9,8,4,3,1,2,7,8,7,INT_MAX};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<< "Before sorting : "; display(arr,n);

    quicksort(arr,0,n-1);

    cout<<"after soritng : "; display(arr,n);


    return 0;
}
