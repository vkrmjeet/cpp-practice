#include<iostream>
using namespace std;

void display(int arr[], int n)
{
	for(int i = 0 ; i < n ; i++)
	{
		cout<<arr[i]<<" ";
	}cout<<endl;
}

void insert(int arr[], int n)
{
	int i = n;
	int temp = arr[n];
	while(i>1 && temp<arr[i/2])
	{
		arr[i] = arr[i/2];
		i /= 2;
	}
	arr[i] = temp;
}

void deletem(int arr[], int n)
{
	int x = arr[1];
	arr[1] = arr[n];
	arr[n] = x;
	int i = 1;
	int j = i*2;
	while(j+1<n)
	{
		if(arr[j+1]>arr[j])
		{
			j++;
		}
		if(arr[i]>arr[j])
		{
			swap(arr[i],arr[j]);
			i = j;
			j *= 2;
		}
		else
		{
			break;
		}
	}
}

void heap(int arr[], int n)
{
	for(int i = 2 ; i < n ; i++)
	{
		insert(arr,i);
	}
}

void heapsort(int arr[],int n)
{
	int i = n;
	while(i>1)
	{
		deletem(arr,i);
		i--;
	}
}

int main()
{
	int arr[] = {0,14,15,5,20,30,8,40};
	int n = sizeof(arr)/sizeof(arr[0]);
	display(arr,n);
	heap(arr,n);
	display(arr,n);

	cout<<"\n\n\n\n";

	cout<<"Before Heap Sort :" ; display(arr,n);
	heapsort(arr,n);
	cout<<"After heap sort : "; display(arr,n);



	return 0;
}
