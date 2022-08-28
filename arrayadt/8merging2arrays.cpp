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

void insertsortedarray(struct aray *ar, int val)
{
	ar->a[ar->length] = val;
	ar->length++;
	int i = ar->length-1;
	while(ar->a[i-1] > ar->a[i])
	{
		swap(ar->a[i],ar->a[i-1]);
		i--;
	}
}

int * mergearr(struct aray *ar1, struct aray *ar2)
{
	int *b;
	b = new int[ar1->length+ar2->length-1];
	int i = 0 , j = 0 , k = 0 ;

	while(i<ar1->length && j <ar2->length)
	{
		if(ar1->a[i] < ar2->a[j])
		{
			b[k++] = ar1->a[i++];
		}
		else
		{
			b[k++] = ar2->a[j++];
		}
	}
	for( ; i < ar1->length ; i++)
	{
		b[k++] = ar1->a[i];
	}
	for( ; j < ar2->length ; j++)
	{
		b[k++] = ar2->a[j];
	}
	return b;
}

int main()
{
	struct aray ar1 = {{1,3,5,7,9},5,10};
	struct aray ar2 = {{2,4,6,8,10},5,10};

    int *res = mergearr(&ar1,&ar2);

    for(int i=0 ; i < ar1.length + ar2.length  ; i++)
	{
		cout<<*(res+i)<<" ";
	}cout<<endl;

	return 0;
}
