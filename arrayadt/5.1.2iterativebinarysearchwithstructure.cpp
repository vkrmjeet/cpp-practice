#include <bits/stdc++.h>

using namespace std;

struct aray{
    int a[10];
    int size;
    int length;
};

void display(struct aray arr)
{
	//displaying elements of the array
	int i ;
	cout<< "elements in the array : ";
	for(int i=0 ; i<arr.length ; i++)
	{
		cout<<arr.a[i]<<" ";
	}
}

int binarysearchiterative(struct aray ar,int l , int h , int key)
{  // we could have used pointer to the array here also but there awas no need as the operation
	// doesn't perform any kind of permanent change to our original array
	while(l<=h)
	{
		int mid = (l+h)/2;
		if(ar.a[mid]==key)
			return mid;
		else if(key<ar.a[mid])
			h = mid-1;
		else
			l = mid+1;
	}
	return -1;
}


int main()
{
    struct aray ar = {{1,2,3,4,5},10,5} ;
	display(ar);
	int key;
	cout<<endl<<"Enter element to search in the array : "<<endl;
	cin>>key;
	int z = binarysearchiterative(ar,0,ar.length,key);
	z==-1 ? cout<<"element not found in the array" : cout<<"element found at position : "<<z<<endl;


    return 0;
}
