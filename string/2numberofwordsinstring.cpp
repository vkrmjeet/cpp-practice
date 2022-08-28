#include<iostream>
using namespace std;

int numwords(char arr[], int n)
{
	int res=0;
	for(int i = 0 ; i < n ; i++)
	{
		if(arr[i]==' ' && arr[i-1]!=' ')
		{
			res++;
		}
	}
	return res;
}

int main()
{
	char wel[] = "how are you";
	int i = 0;
	while(wel[i]!='\0')
	{
		i++;
	}
	int word = numwords(wel,i);
	cout<< "Num of words "<<word+1;
}
