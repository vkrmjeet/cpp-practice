#include<bits/stdc++.h>
using namespace std;

struct aray{
   int a[10];
   int length;
   int size;
};

int binarysearch(struct aray ar, int l , int h , int key)
{
	if(l<=h)
	{
		int mid = (l+h)/2;
		if(ar.a[mid]==key)
			return mid;
		else if(key<ar.a[mid])
			return binarysearch(ar,l,mid-1,key);
		else
			return binarysearch(ar,mid+1,h,key);
	}
	else
		return -1;
}

int main()
{
	struct aray ar = {{1,2,3,4,5,6,7},7,10} ;
	cout<< "enter element to search ";
	int key;
	cin>>key;

	int res = binarysearch(ar,0,ar.length,key);
	res==-1 ? cout<<"element not found" : cout<< "element found at : "<<res<<endl;

	return 0;
}
