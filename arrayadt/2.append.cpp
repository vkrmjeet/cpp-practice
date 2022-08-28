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

void append(struct aray *ar, int x)
{
	if(ar->length < ar->size)
	{
		ar->a[ar->length++] = x;
	}
}

void insert(struct aray *ar,int index,int x)
{
	if(index>=0 && index <= arr->length)
	{
		for(i=arr->length ; i>index ; i--)
		{
			ar->a[i] = ar->a[i-1];
		}
		ar->a[index] = x;
		ar->length++;
	}
}

int main()
{
    struct aray ar = {{1,2,3,4,5},10,5} ;

    append(&ar,10);

	display(ar);

    return 0;
}
