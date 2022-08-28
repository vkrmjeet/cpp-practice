#include<bits/stdc++.h>
using namespace std;

void swap(char *a,char *b)
{
	char temp;
	temp = *a;
	*a = *b ;
	*b = temp;
}

void reversestring(char a[],int n)
{
	int i = 0 , j = n-1;
	while(i<=j)
	{
		swap(&a[i],&a[j]);
		i++;
		j--;
	}
}

void printstring(char a[], int n)
{
	for(int i = 0 ; i < n ; i++)
	{
		cout<<a[i];
	}cout<<endl;
}

int main()
{
	char a[] = {'p','y','t','h','o','n'};
	int i = 0;
	while(a[i]!='\0')
	{
		i++;
	}i--;

	printstring(a,i);

	reversestring(a,i);

	printstring(a,i);
}
