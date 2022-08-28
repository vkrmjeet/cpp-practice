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

int main()
{
	struct aray ar = {{1,2,4,5,6},5,10};
    display(ar);
    int x = 3;
	insertsortedarray(&ar,x);
	display(ar);

	return 0;
}
