#include<iostream>
using namespace std;

void swap(int &a , int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void display(int arr[],int n)
{
	int i = 0;
	while(i<n && arr[i]!=-1)
	{
		cout<<arr[i]<<" ";
		i++;
	}cout<<endl;
}

void maxh(int arr[],int n)
{
	int i = n;
	int temp = arr[n];
	while(i>0 && temp > arr[ i%2==0 ? (i/2)-1 : (i/2) ] )
	{
		arr[i] = arr[ i%2==0 ? (i/2)-1 : i/2 ];
		i = i%2==0 ? (i/2)-1 : i/2 ;
	}
	arr[i] = temp;
}

void minh(int arr[], int n)
{
	int i = n;
	int temp = arr[n];
	while(i>0 && temp < arr[ i%2==0 ? (i/2)-1 : i/2 ])
	{
		arr[i] = arr[ i%2==0 ? (i/2)-1 : i/2 ];
		i = i%2==0 ? (i/2)-1 : i/2;
	}
	arr[i] = temp;
}

void minheap(int arr[], int n)
{
	for(int i = 0 ; i < n ; i++)
	{
		minh(arr,i);
	}
}

void maxheap(int arr[],int n)
{
	for(int i = 0 ; i < n ; i++)
	{
		maxh(arr,i);
	}
}

void deletee(int arr[],int n)
{
	int x = arr[0];
	arr[0] = arr[n];
	arr[n] = -1;
	int i = 0;
	int j = 1;
	while(j+1<n)
	{
		if(arr[j+1]>arr[j])
		{
			j++;
		}
		if(arr[j]>arr[i])
		{
			swap(arr[i],arr[j]);
			int temp = j;
			j = i%2==0 ? (i+1)*j : i*2;
			i = temp;
		}
		else
		{
			break;
		}
	}
	cout<<x<<" is deleted "<<endl;
}

void deletem(int arr[], int n)
{
	int x = arr[0];
	arr[0] = arr[n];
	arr[n] = x;
	int i = 0;
	int j = 1;
	while(j+1<n)
	{
		if(arr[j+1]<arr[j])
		{
			j++;
		}
		if(arr[i]>arr[j])
		{
			swap(arr[i],arr[j]);
			int temp = j;
			j = i%2==0 ? (i+1)*2 : i*2;
			i = temp;
		}
		else
		{
			break;
		}
	}
	cout<<x<<" is deleted. "<<endl;
}

int main()
{
	int minh[] = {90,80,70,60,50,40,30,20,10};
	int maxh[] = {10,20,30,40,50,60,70,80,90};

	int m = sizeof(minh)/sizeof(minh[0]);
	int n = sizeof(maxh)/sizeof(maxh[0]);

	cout<<"normal array : "; display(maxh,n);
	maxheap(maxh,n);
	cout<<"maxheap version : "; display(maxh,n);

	cout<<"normal array : "; display(minh,m);
	minheap(minh,m);
	cout<<"minheap version : "; display(minh,m);

	cout<<"before deletion : "; display(maxh,n);
	deletee(maxh,n-1);
	cout<<"after deletion : "; display(maxh,n);

	cout<<"before deletion : "; display(minh,m);
	deletem(minh,n-1);
	cout<<"after deletion : "; display(minh,n);
	return 0;
}
