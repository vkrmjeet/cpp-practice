#include<iostream>
using namespace std;

void insertionsort(int a[], int n)
{
	int temp;
	int posi;
	for(int i = 1 ; i<n ; i++)
	{
		temp = a[i];
		for(int j = i - 1 ; j>-1 ; j--)
		{
			if(a[j]>temp)
			{
				a[j+1] = a[j];
				posi = j;
			}
			else
			{
				break;
			}
		}
		a[posi] = temp;
	}
}

int main()
{
	int arr[] = {8,7,5,3,2};
	int n = sizeof(arr)/sizeof(arr[0]);

	insertionsort(arr,n);

	for(int i = 0 ; i<n ; i++)
	{
		cout<<arr[i]<<" ";
	}


	return 0;
}
