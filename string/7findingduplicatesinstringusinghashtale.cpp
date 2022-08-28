#include<bits/stdc++.h>
using namespace std;


void printstring(char a[])
{
	for( int i = 0 ; a[i]!='\0' ; i++)
	{
		cout<<a[i];
	}
}

char * duplicateschar(char a[])
{
	int hash[25] = {0};
	for(int i =  0 ; a[i]!='\0' ; i++)
	{
		int temp = 0 ;
		temp = (int)a[i] - 97 ;
		hash[temp] += 1;
	}
	for(int i = 0 ; i<25 ; i++)
	{
		if(hash[i]>1)
		{
			cout<<(char)(i+97)<< " is occuring "<<hash[i]<< " times ."<<endl;
		}
	}
}

int main()
{
	char a[] = "finding";

	char *res = duplicateschar(a);


}
