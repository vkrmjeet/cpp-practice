#include<iostream>
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

void bubblesort(int arr[],int n)
{
    for(int i = 0 ; i < n ; i++)
	{
		bool isswapped = false; //this variable is used in the case if the array is already sorted
								//so that the loop doesn't run unneccesrily , if there is no swap in a iteration we can say array is sorted.
		for(int j = i+1 ; j < n ; j++)
		{
			if(arr[i]>arr[j])
			{
				swap(arr[i],arr[j]);
				isswapped = true;
			}
		}
		if(isswapped==false)
		{
			break;
		}
	}
}


int main()
{
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<< "Before sorting : "; display(arr,n);

    bubblesort(arr,n);

    cout<<"after soritng : "; display(arr,n);


    return 0;
}
