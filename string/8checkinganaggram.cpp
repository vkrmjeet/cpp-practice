#include<bits/stdc++.h>
using namespace std;

bool checkinganagram(char a[], char b[])
{
	long int h = 0 , x = 0 , j = 0;
	for(int i = 0 ; a[i]!='\0' ; i++)
	{
		x = 1;
		x = x<<a[i]-97;
		h = (x|h) ;
		x = 1;
		x = x<<b[i]-97;
		j = (j|x);
	}
	if(j!=h)
		return false;
	else
		return true;
}

int main()
{
	char a[] = "decimal";
	char b[] = "medical";

	bool isana = checkinganagram(a,b);

	isana ? cout<< "given strings are anagram " : cout<< "given strings are not anagram";
}
