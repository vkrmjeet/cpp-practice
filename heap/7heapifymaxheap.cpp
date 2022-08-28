#include<iostream>
using namespace std;

void display(int arr[],int n)
{
	for(int i = 1 ; i < n ; i++)
	{
		cout<<arr[i]<<" ";
	}cout<<endl;
}

void heapify(int arr[],int n)
{
	for(int i = n/2 ; i>=1 ; i--)
	{
		int j = i*2;
		while(j<n-1)
		{
			//set j equal to largest child
			if(arr[j+1]>arr[j])
			{
				j++;
			}
			//compare parent and largest child
			if(arr[i]<arr[j])
			{
				swap(arr[i],arr[j]);
				i = j;
				j = i * 2;
			}
			else
				break;
		}
	}
}

int main()
{
	int arr[] = {0,5,10,30,20,35,40,15};
	int n = sizeof(arr)/sizeof(arr[0]);

	display(arr,n);
	heapify(arr,n);
	display(arr,n);


	return 0;
}
