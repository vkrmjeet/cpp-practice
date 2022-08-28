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
	int i = n ;
	int temp = arr[n];
	while(n>0 && temp > arr[n%2==0 ? (n/2)-1 : n/2])
	{
		arr[n] = arr[n%2==0 ? (n/2)-1 : n/2];
		n = n%2==0 ? (n/2)-1 : n/2 ;
	}
	arr[n] = temp;
	cout<<" iteration : "<<i<< " elements : "; display(arr,8);
}

int main()
{
	int arr[] = {10,20,40,50,60,70,80,90};
	int n = sizeof(arr)/sizeof(arr[0]);

	display(arr,n);

	for(int i = 0 ; i < n ; i++)
	{
		insert(arr,i);
	}

	display(arr,n);

	return 0;
}
