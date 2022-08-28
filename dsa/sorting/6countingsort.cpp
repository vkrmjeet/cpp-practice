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

void countsort(int arr[],int n)
{
	int maxi = returnmax(arr,n);
	maxi += 1;
	int coun[maxi] = {0};
	for(int i = 0 ; i < n ; i++)
	{
		coun[arr[i]]++;
	}
	int i = 0;
	int k = 0;
	while(i<maxi)
	{
		if(coun[i]!=0)
		{
			while(coun[i]!=0)
			{
				arr[k++] = i;
				coun[i]--;
			}
		}
		else
		{
			i++;
		}
	}
}

int main()
{
	int arr[] = {10,9,8,4,3,1,2,7,8,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<< "Before sorting : "; display(arr,n);

    countsort(arr,n);

    cout<<"after soritng : "; display(arr,n);


	return 0;
}
