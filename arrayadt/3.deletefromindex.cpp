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

int del(struct aray *ar,int index)
{
	int x = 0;
	if(index <= ar->length && index>=0)
	{

		x = ar->a[index];
		for(int i=index ; i<ar->length ; i++)
		{
			ar->a[i] = ar->a[i+1];
		}
		ar->length--;
	}
	return x;
}

int main()
{
    struct aray ar = {{1,2,3,4,5},10,5} ;
	display(ar);
	cout<<endl;
    cout<<del(&ar,0)<< " is deleted "<<endl;
    display(ar);

    return 0;
}
