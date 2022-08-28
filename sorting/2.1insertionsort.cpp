#include<iostream>
using namespace std;

void insertionsort(int arr[],int n)
{
	int i = 1;
	while(i<n)
	{
		int temp = arr[i];
		int j = i - 1;
		while(j>-1 && arr[j]>temp)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
		i++;
	}
}

int main()
{
	int arr[] = {8,7,2,3,5};
	int n = sizeof(arr)/sizeof(arr[0]);

	insertionsort(arr,n);

	for(int i = 0 ; i<n ; i++)
	{
		cout<<arr[i]<<" ";
	}


	return 0;
}
