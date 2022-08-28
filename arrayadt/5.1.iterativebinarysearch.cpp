#include<bits/stdc++.h>
using namespace std;



int iterativebinarysearch(int arr[],int l,int h,int key)
{
	while(l<=h)
	{
		int mid = (l+h)/2;
	if(arr[mid]==key)
		return mid;
	else if(key<arr[mid])
	   {
	   	  h=mid-1;
	   }
	   else
	   {
	   	l=mid+1;
	   }
	}

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

	int res = iterativebinarysearch(arr,l,h,key);
	cout<<res;
}
