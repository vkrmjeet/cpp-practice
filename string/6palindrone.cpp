#include<bits/stdc++.h>
using namespace std;


void printstring(char a[])
{
	for( int i = 0 ; a[i]!='\0' ; i++)
	{
		cout<<a[i];
	}
}

bool ispalindrome(char a[])
{
	int j = 0;
	while(a[j]!='\0')
	{
		j++;
	}j--;
	cout<<j<<endl;
	int i = 0 ;
	while(i<=j)
	{
		if(a[i]!=a[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}


int main()
{
	char a[] = "abccba";

	bool ispali = ispalindrome(a);

	ispali ? cout<< "string is palindrome" : cout<< "String is not palindrome";

}
