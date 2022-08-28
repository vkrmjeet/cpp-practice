#include<iostream>
using namespace std;

void display(int arr[],int n)
{
	for(int i = 1 ; i < n ; i++)
	{
		cout<<arr[i]<<" ";
	}cout<<endl;
}

void Insert(int arr[],int n)
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

int Delete(int arr[],int n)
{
	int temp = arr[1];
	arr[1] = arr[n];

	int i = 1;
	int j = i*2;

	while(j<n)
	{
		if(arr[j+1]>arr[j])
		{  //change above condition for descending order if original heap is min heap
			j++;
		}
		if(arr[i]<arr[j])
		{  //change the above condition for descending order
			swap(arr[i],arr[j]);
			i = j;
			j = i*2;
		}
		else
		{
			break;
		}
	}
	arr[n] = temp;
}

int main()
{
	int heap[] = {0,10,20,30,25,5,40,35};
	int n = sizeof(heap)/sizeof(heap[0]);
	display(heap,n);

	for(int i = 1 ; i < n ; i++)
	{
		Insert(heap,i);
	}

	display(heap,n);

	for(int i = n-1 ; i>1 ; i--)
	{
		Delete(heap,i);
	}

	display(heap,n);

	return 0;
}
