#include<iostream>
using namespace std;

void display(int arr[],int n)
{
	for(int i = 1 ; i < n ; i++)
	{
		cout<<arr[i]<<" ";
	}cout<<endl;
}

void insert(int arr[],int n)
{
	int i = n;
	int temp = arr[n];
	while(i>1 && temp>arr[i/2])
	{
		arr[i] = arr[i/2];
		i = i/2;
	}
	arr[i] = temp;
}

void deletem(int arr[],int n)
{
	int val = arr[1];
	arr[1] = arr[n];

	int i = 1;
	int j = i*2;
	while(j<n)
	{
		if(arr[j+1]>arr[j])
		{
			j++;
		}
		if(arr[i]<arr[j])
		{
			swap(arr[i],arr[j]);
			i = j;
			j = j*2;
		}
		else
		{
			break;
		}
	}
	arr[n] = val;
}

int main()
{
	int arr[] = {0,5,7,2,4,9,10,20,15,19};
	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i = 1 ; i < n ; i++)
	{
		insert(arr,i);
	}

	display(arr,n);

	for(int i = n-1 ; i>1 ; i--)
	{
		deletem(arr,i);
		display(arr,n);
	}

	display(arr,n);

	return 0;
}
