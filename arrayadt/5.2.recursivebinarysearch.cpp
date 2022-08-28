#include<bits/stdc++.h>
using namespace std;

int binarysearch(int arr[],int l,int h,int key)
{
	if(l<=h)
	{
		int mid = (l+h)/2;
		if(arr[mid]==key)
			return mid;
		else if(key<arr[mid])
			binarysearch(arr,l,mid-1,key);
		else
			binarysearch(arr,mid+1,h,key);
	}
	else
		return -1;
}

int main()
{
int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int l,h;
	l = arr[0];
	h = sizeof(arr)/sizeof(arr[0]);

	int key=0;
	cout<<"enter element to search ";
	cin>>key;

	int res = binarysearch(arr,l,h,key);
	cout<<res;
}
