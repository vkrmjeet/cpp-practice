#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void bubblesort(int arr[],int n)
{
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = i+1 ; j<n ; j++)
		{
			if(arr[i]>arr[j])
			{
				swap(arr[i],arr[j]);
			}
		}
	}
}

void kthSmallestLargest(int arr[], int n, int k) {
    bubblesort(arr,n);
    int smallest = -1;
    int largest = -1;
    int a = 0;
    int smallestpos = -1;
    for(int i = 0 ; i < n - 1 ; i++)
	{
		if(arr[i]<arr[i+1])
		{
			a++;
			smallestpos = i;
		}
		if(a==k-1)
		{
			break;
		}
	}
	int b = 0;
	int largestpos = -1;
	for(int i = n-1 ; i>0 ; i--)
	{
		if(arr[i]>arr[i-1])
		{
			a++;
			largestpos = i;
		}
		if(a==k)
		{
			break;
		}
	}
	if(smallestpos==-1 && largestpos==-1)
	{
		cout<<-1<<" "<<-1;
	}
	else
	{
		cout<<arr[largestpos]<<" "<<smallestpos;
	}
}

int main() {
    int t;
    cin >> t;

    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        kthSmallestLargest(arr, n, k);
        cout<<endl;
        t--;
    }
    return 0;
}
