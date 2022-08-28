#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void bubblesort(int a[],int n)
{
	int flag; // to make it adaptive (if array is already sorted).
	for(int i = 0 ; i<n-1 ; i++)
	{
		flag = 0;
		for(int j = 0 ; j<n-i-1 ; j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				flag = 1;
			}
		}cout<<endl;
		if(flag==0)
		{
			break;
		}
	}
}

int main()
{
	int arr[] = {8,5,7,3,2};
	int n = sizeof(arr)/sizeof(arr[0]);

	bubblesort(arr,n);

	for(int i = 0 ; i<n ; i++)
	{
		cout<<arr[i]<<" ";
	}cout<<endl;


	return 0;
}
