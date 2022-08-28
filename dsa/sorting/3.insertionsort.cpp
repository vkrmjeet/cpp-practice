#include<iostream>
#include<limits.h>
using namespace std;

void swap(int &a , int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void display(int arr[], int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
}

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

//the two algorithms of insertion sort are similar only , the number of iterations is same in both
//above one takes j less than i , below one takes j equal to i the difference lies in the temporary variable.
//the time complexity is same

void insertionsort2(int arr[],int n)
{
	int i = 0;
	while(i<n-1)
	{
		int j = i;
		int temp = arr[j+1];
		while(j>=0 && temp<arr[j])
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
    int arr[] = {10,9,8,4,3,1,2,7,8,7,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<< "Before sorting : "; display(arr,n);

    insertionsort2(arr,n);

    cout<<"after soritng : "; display(arr,n);


    return 0;
}
