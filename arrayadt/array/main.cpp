#include <bits/stdc++.h>

using namespace std;

struct aray{
    int *a;
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

int main()
{
    struct aray ar;
    cout<<"Enter size of the array : ";
    cin>>ar.size;
    ar.a = new int[ar.size];
    ar.length = 0;
    int n,i;
    cout<< "enter numbers";
    cin>>n;

    cout<<"enter all the elements\n";
    for(i=0 ; i<n ; i++)
	{
		cin>>ar.a[i];
	}
	ar.length = n;
	display(ar);

	cout<<"Enter any element you want to insert : ";



    return 0;
}
