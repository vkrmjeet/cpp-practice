#include<bits/stdc++.h>
using namespace std;


void printstring(char a[])
{
	for( int i = 0 ; a[i]!='\0' ; i++)
	{
		cout<<a[i];
	}
}

vector<char> duplicateschar(char a[])
{
	vector<char> res;
	for(int i = 0 ; a[i] != '\0' ; i++)
	{
		for(int j = i+1 ; a[j] != '\0' ; j++)
		{
			cout<< " index "<<i<< " "<<j<<endl;
			if(a[i]==a[j] && a[j]!=' ')
			{
				a[j]=' ';
				res.push_back(a[i]);
			}
		}
	}
	return res;
}

int main()
{
	char a[] = "finding";

	vector<char> res = duplicateschar(a);

	for(int i = 0 ; i<res.size(); i++)
	{
		cout<<res[i] << " is repeated "<<endl;
	}
}
