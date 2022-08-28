#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void display(int arr[],int n)
{
	for(int i = 0 ; i<n ; i++)
	{
		cout<<arr[i]<<" ";
	}cout<<endl;
}

void selectionsort(int arr[],int n)
{
	int  smallesposition;
	for(int i = 0 ; i < n ; i++)
	{
		smallesposition = i;
		int smallest = arr[i];
		for(int j = i ; j < n ; j++)
		{
			if(smallest>arr[j])
			{
				smallesposition = j;
				smallest = arr[j];
			}
		}
		if(i!=smallesposition)
		{
			swap(arr[smallesposition],arr[i]);
		}
	}
}

int main()
{
	int arr[] = {8,7,6,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	display(arr,n);
	selectionsort(arr,n);
	display(arr,n);

	return 0;
}
