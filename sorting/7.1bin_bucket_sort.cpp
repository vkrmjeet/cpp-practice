#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

void insert(struct node **temp,int x)
{
	struct node *t ;
	t = new node;
	t->data = x;
	t->next = nullptr;

	if(temp[x] == nullptr)
	{
		temp[x] = t;
	}
	else
	{
		struct node *p = temp[x];
		while(p->next != nullptr)
		{
			p = p->next;
		}
		p->next = t;
	}

}

int deletee(struct node **temp , int index)
{
	struct node *p = temp[index];
	temp[index] = temp[index]->next;
	int x = p->data;
	delete p;
	return x;
}

int returnmax(int arr[], int n)
{
	int maximum_value = -1;
	for(int i = 0 ; i < n ; i++)
	{
		if(arr[i]>maximum_value)
		{
			maximum_value = arr[i];
		}
	}
	return maximum_value;
}

void display(int arr[], int n)
{
	for(int i = 0 ; i < n ; i++)
	{
		cout<<arr[i]<<" ";
	}cout<< "\n";
}

void bucketsort(int arr[], int n)
{
	int maxi = returnmax(arr,n);
	maxi += 1;
	struct node **bin;
	bin = new struct node*[maxi];

	for(int i = 0 ; i < maxi ; i++)
	{
		bin[i] = nullptr;
	}

	for(int i = 0 ; i < n ; i++)
	{
		insert(bin,arr[i]);
	}

	int i = 0 , j = 0;
	while(i<maxi)
	{
		if(bin[i]!=nullptr)
		{
			while(bin[i]!=nullptr)
			{
				arr[j++] = deletee(bin,i);
			}
			i++;
		}
		else
		{
			i++;
		}
	}

	delete [] bin;
}

int main()
{
	int arr[] = {9,8,7,6,5,4,3,42,32,22};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<"before sortiong : "; display(arr,n);
	bucketsort(arr,n);
	cout<< "After sorting : "; display(arr,n);

	return 0;
}
