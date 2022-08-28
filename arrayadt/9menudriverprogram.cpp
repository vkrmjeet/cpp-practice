#include<bits/stdc++.h>
using namespace std;

struct aray {
   int a[10];
   int length;
   int size;
};

aray unionsorted(struct aray ar1, struct aray ar2)
{
	struct aray c3 = {{0},ar1.length+ar2.length, ar1.length+ar2.length};
	int i =0 , j = 0,k = 0;
	while(i<ar1.length && j <ar2.length)
	{
		if(ar1.a[i]<ar2.a[j])
		{
			c3.a[k++] = ar1.a[i++];
		}
		else if(ar2.a[j]<ar1.a[i])
		{
			c3.a[k++] = ar2.a[j++];
		}
		else
		{
			c3.a[k++] = ar1.a[i++];
			j++;
			c3.length--;
		}
	}
	for(; i<ar1.length ; i++)
	{
		c3.a[k++] = ar1.a[i];
	}
	for(; j < ar2.length ; j++)
	{
		c3.a[k++] = ar2.a[j];
	}
	return c3;
}

int get(struct aray ar, int index)
{
	if(index>=0 && index<ar.length)
	{
		return ar.a[index];
	}
	return -1;
}

int sete(struct aray *ar, int index,int val)
{
	if(index<ar->length && index>=0)
	{
		ar->a[index]=val;
	}
}

int max(struct aray ar)
{
	int max=-1;
	for(int i = 0 ; i < ar.length ; i++)
	{
		if(max<ar.a[i])
		{
			max = ar.a[i];
		}
	}return max;
}

int min(struct aray ar)
{
	int min = INT_MAX;
	for ( int i = 0 ; i < ar.length ; i++)
	{
		if(min>ar.a[i])
		{
			min = ar.a[i];
		}
	}return min;
}

int total(struct aray ar)
{
	int total = 0;
	for(int i = 0 ; i<ar.length ; i++)
	{
		total += ar.a[i];
	}
	return total;
}

float avg(struct aray ar)
{
	return (float)(total(ar))/ar.length;
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
	if(index>=0 && index <= ar->length)
	{
		for(int i=ar->length ; i>index ; i--)
		{
			ar->a[i] = ar->a[i-1];
		}
		ar->a[index] = x;
		ar->length++;
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

int linearsearch(struct aray *ar,int x)
{
	for(int i=0; i<ar->length; i++ )
	{
		if(ar->a[i]==x)
		{
			return i;
		}
	}
	return -1;
}

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

int main ()
{
	struct aray ar1 = {{0},0,0} ;
	int ch;
	int x , index;
	cout<< "Enter size of the array : ";
	cin>>ar1.size;

	do{
	cout<< "\nMenu\n"<< " 1. Insert \n " << " 2. Delete\n " << " 3. Search \n " << " 4. Sum \n " << " 5. Display\n " << " 6.exit\n "<<endl;

	cout<< "Enter your choice ";
	cin>>ch;

	switch(ch)
	{
		case 1: cout<< "enter an value and index";
				cin>>x>>index;
				insert(&ar1,index,x);
				break;
		case 2: cout<< "Enter index ";
				cin>>index;
				del(&ar1,index);
				break;
		case 3 : cout<< "Enter element to search";
				cin>>x;
				index = linearsearch(&ar1,x);
				cout<< " Element index "<<index;
				break;
		case 4 : cout<< " Sum is : "<<total(ar1);
				break;
		case 5 : display(ar1);

	}
	}
	while(ch<6);
	return 0;
}
