#include<bits/stdc++.h>
using namespace std;

bool issame(char a[],char b[])
{
	for(int i=0,h=0 ; a[i]!='\0' && b[h]!='\0' ; i++ , h++)
	{
		if(a[i]!=b[h])
		{
			return false;
		}
	}
	return true;
}

void printstring(char a[])
{
	for( int i = 0 ; a[i]!='\0' ; i++)
	{
		cout<<a[i];
	}
}

void indictionary(char a[], char b[])
{
	for(int i = 0 , j = 0 ; a[i]!='\0' && b[j]!='\0' ; i++,j++)
	{
		if(a[i]!=b[j])
		{
			if((int)a[i]>(int)b[j])
			{
				printstring(b); cout<< " comes first in dictionary.";
			}
			else
			{
				printstring(a); cout<< " comes first in dictionary.";
			}
			break;
		}
	}
}

int main()
{
	char a[] = "painter";
	char b[] = "painting";

	bool isequal = issame(a,b);

	isequal ? cout<< "string equal" : cout<< "String is not equal";

	cout<<endl;
	indictionary(a,b);
}
