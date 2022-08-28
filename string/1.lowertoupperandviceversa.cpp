#include<iostream>
using namespace std;

void lowertoupper(char arr[],int n)
{
	for(int i = 0 ; i<n-1 ; i++)
	{   if(arr[i]>=97 && arr[i]<=122)
	        {
		      arr[i] = arr[i] - 32;
	        }
	}cout<<endl;

}

void uppertolower(char arr[],int n)
{
	for(int i = 0 ; i<n-1 ; i++)
	{
		if(arr[i]>=65 && arr[i]<=90)
	        {
		      arr[i] = arr[i] + 32;
	        }
	}cout<<endl;
}

void printstring(char arr[],int n)
{
	for(int i = 0 ; i <n-1 ; i++)
	{
		cout<<arr[i];
	}cout<<endl;
}

int main()
{
	char wel[] = {'w','e','l','c','o','m','e'};
	int i = 0;
	while(wel[i]!='\0')
	{
		i++;
	}

	printstring(wel,i);

	lowertoupper(wel,i);
	printstring(wel,i);

	uppertolower(wel,i);
	printstring(wel,i);
}
