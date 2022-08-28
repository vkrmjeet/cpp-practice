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

void negleftside(struct aray *ar)
{
	int i = 0;
	int j = ar->length-1;
	while(i<j)
	{
		if(ar->a[i]>ar->a[j])
		{
			swap(&ar->a[i],&ar->a[j]);
			i++,j--;
		}
		while(ar->a[i]<0)
		{
			i++;
		}
		while(ar->a[j]>0)
		{
			j--;
		}
	}
}

int main()
{
	struct aray ar = {{1,2,4,-5,-6,9,-7},7,10};
    display(ar);
    negleftside(&ar);
    display(ar);


	return 0;
}
