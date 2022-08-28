#include<iostream>
using namespace std;

void display(int arr[], int n)
{
	for(int i = 0 ; i < n ; i++)
	{
		cout<<arr[i]<<" ";
	}cout<<endl;
}

void shellsort(int arr[], int n)
{
	int gap ,i,j,temp;

	for(gap=n/2 ; gap>=1 ; gap/=2)
	{
		for(i = gap ; i < n ; i++)
		{
			temp = arr[i];
			j = i - gap;
			while(j>=0 && arr[j]>temp)
			{
				arr[j+gap] = arr[j];
				j = j - gap;
			}
			arr[j+gap] = temp;
		}
	}
}

int main()
{
	int arr[] = {9,8,7,6,5,4,3,2};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<< "before sorting : "; display(arr,n);

	shellsort(arr,n);

	cout<< "after sorting : "; display(arr,n);

    return 0;
}
