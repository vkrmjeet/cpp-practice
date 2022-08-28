#include<iostream>
using namespace std;

int returnmax(int arr[], int n)
{
	int max = -1;
	for(int i = 0 ; i < n ; i++)
	{
		if(arr[i]>max)
		{
			max = arr[i];
		}
	}
	return max;
}

void countsort(int arr[], int n)
{
	int maximum_value  = returnmax(arr,n);
	maximum_value += 1;

	int countarray[maximum_value] = {0};

	for(int i = 0 ; i < n ; i++)
	{
		countarray[arr[i]]++;
	}

	int i = 0, j = 0;

	while(i<maximum_value)
	{
		if(countarray[i]!=0)
		{
			while(countarray[i]>0)
			{
				arr[j++] = i;
				countarray[i]--;
			}
			i++;
		}
		else
		{
			i++;
		}
	}

}

void display(int arr[], int n)
{
	for(int i = 0 ; i < n ; i++)
	{
		cout<<arr[i]<< " ";
	}cout<<endl;
}

int main()
{
	int arr[] = {9,8,7,6,6,5,4,3,2};
	int n = sizeof(arr)/sizeof(arr[0]);

	display(arr,n);

	countsort(arr,n);

	display(arr,n);

	return 0;

}
