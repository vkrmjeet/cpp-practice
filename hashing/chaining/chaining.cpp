#include<iostream>
#include "require.h"
using namespace std;

int Hash(int key)
{
	return key%10;
}

void insert(struct node *h[],int key)
{
	int index = Hash(key);
	sortedinsert(&h[index],key);
}

int main()
{
	struct node *ht[10];
	struct node *temp;
	int i = 0;
	for( i ; i < 10 ; i++)
	{
		ht[i] = nullptr;
	}
	insert(ht,10);
	insert(ht,20);
	insert(ht,30);
	insert(ht,40);

	temp = search(ht[Hash(29)],29);
	if(temp==nullptr)
	{
		cout<<"element not present in the hash table ";
	}
	else
	{
		cout<<" element present : "<<temp->data;
	}
	return 0;
}
