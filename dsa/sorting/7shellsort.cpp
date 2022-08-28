#include<iostream>
#include<limits.h>
using namespace std;

void swap(int &a,int &b)
{
	int temp;
	temp = a;
	a = b;
	 b = temp;
}

void display(int arr[],int n)
{
	for(int i = 0 ; i < n ; i++)
	{
		cout<<arr[i]<<" ";
	}cout<<endl;
}

int returnmax(int arr[],int n)
{
	int maximum = INT_MIN;
	for(int i = 0 ; i < n ; i++)
	{
		if(arr[i]>maximum)
		{
			maximum = arr[i];
		}
	}
	return maximum;
}

void shellsort(int arr[],int n)
{
	int i,j,temp,gap;
	for( gap = n/2 ; gap>=1 ; gap /=2 )
	{
		for( i = gap ; i < n ; i++ )
		{
			temp = arr[i];
			j = i - gap;
			while(j>=0 && arr[j]>temp)
			{
				arr[j+gap] = arr[j];
				j = j - gap;
			}
			arr[j+gap] = temp;
			display(arr,n);
		}
	}
}

int main()
{
	int arr[] = {10,9,8,4,3,1,2,7,8,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<< "Before sorting : "; display(arr,n);

    shellsort(arr,n);

    cout<<"after soritng : "; display(arr,n);


	return 0;
}
