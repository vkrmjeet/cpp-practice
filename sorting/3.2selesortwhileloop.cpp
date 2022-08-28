#include<bits/stdc++.h>
using namespace std;

void selectionsort(int arr[],int n)
{
	int i = 0;
	int k,j;
	while(i<n)
	{
		k = j = i;
		while(j<n)
		{
			if(arr[j]<arr[i])
			{
				k = j;
			}
			j++;
		}
		swap(arr[k],arr[i]);
		i++;
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
	int arr[] {8,7,6,5,4,3,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	display(arr,n);

	selectionsort(arr,n);

	display(arr,n);

	return 0;
}
