#include<bits/stdc++.h>
using namespace std;

struct aray{
    int a[10];
    int length;
    int size;
};

void display(struct aray ar)
{
	for(int i = 0 ; i<ar.length;i++)
	{
		cout<<ar.a[i]<<" ";
	}cout<<endl;
}

int swap(int *a , int *b)
{
	int temp;
	temp = *a;
	*a = *b ;
	*b = temp;
	return temp;
}

void reverse(struct aray *ar)
{
	int i=0;
	int j = ar->length-1;
	while(i<j)
	{
		swap(&ar->a[i],&ar->a[j]);
		i++;
		j--;
	}
}

void reversefor(struct aray *ar)
{
	int i , j;
	for(i = 0 ,j = ar->length-1 ; i < j ; i++, j--)
	{
		swap(&ar->a[i],&ar->a[j]);
	}
}

int reverseaux(struct aray *ar)
{
	// this method have more space complexity as compared to the above two pointer method
	// as it requires a new array to be created and used required throughout the program
	// it also has slightly more time complexity as it requires two loops
	int *b;
	int i , j;
	b = new int[ar->length];
	for(i=ar->length-1,j=0 ; i>=0; i--,j++)
	{
		b[j] = ar->a[i];
	}
	for(int i = 0 ; i<ar->length ; i++)
	{
		ar->a[i] = b[i];
	}
}

void leftshift(struct aray *ar)
{
	for(int i=0 ; i<ar->length-1 ; i++)
	{
		swap(&ar->a[i],&ar->a[i+1]);
	}
}

void rightshift(struct aray *ar)
{
	for(int i=ar->length-1 ; i>0 ; i--)
	{
		swap(&ar->a[i],&ar->a[i-1]);
	}
}

int main()
{
	struct aray ar = {{1,2,3,4,5},5,10};

	display(ar);


	return 0;
}
