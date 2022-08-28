#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

void display(int arr[], int n)
{
	for(int i = 0 ; i < n ; i++)
	{
		cout<<arr[i]<<" ";
	}cout<<endl;
}

int returnmax(int arr[], int n)
{
	int maximumval = -1;
	for(int i = 0 ; i < n ; i++)
	{
		if(arr[i]>maximumval)
		{
			maximumval = arr[i];
		}
	}
	return maximumval;
}

int returnsize(int n)
{
	int count = 0;
	while(n>0)
	{
		n /= 10;
		count++;
	}
	return count;
}

void insert(struct node **temp,int index,int value)
{
	struct node *t;
	t = new node;
	t->data = value;
	t->next = nullptr;

	if(temp[index]==nullptr)
	{
		temp[index] = t;
	}
	else
	{
		struct node *p = temp[index];
		while(p->next != nullptr)
		{
			p = p->next;
		}
		p->next = t;
	}
}

int deletee(struct node **t,int index)
{
	struct node *p;
	p = t[index];
	t[index] = t[index]->next;
	int x = p->data;
	delete p;
	return x;
}

void radixsort(int arr[], int n)
{
	int maxi = returnmax(arr,n);
	int maxisize = returnsize(maxi);

	struct node **bin = new node*[10];

	for(int i = 0 ; i < 10 ; i++)
	{
		bin[i] = nullptr;
	}

	int num = 1;

	while(maxisize>0)
	{
		for( int i = 0 ; i < n  ; i++)
		{
			int position = (arr[i]/num)%10;
			insert(bin,position,arr[i]);
		}
		int j = 0,k = 0;
		while(j<10)
		{
			if(bin[j]!=nullptr)
			{
				while(bin[j]!=nullptr)
				{
					arr[k++] = deletee(bin,j);
				}
				j++;
			}
			else
			{
				j++;
			}
		}
		num *= 10;
		maxisize--;
	}
}

int main()
{
	int arr[] = {2347,146,259,152,235,48,36,62};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<< "before sorting "; display(arr,n);

	radixsort(arr,n);

	cout<< "after sorting "; display(arr,n);

	return 0;
}
