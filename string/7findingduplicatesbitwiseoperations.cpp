#include<bits/stdc++.h>
using namespace std;

void findingduplicates(char a[])
{
	long int h = 0 , x = 0;
	for(int i = 0 ; a[i]!='\0' ; i++)
	{
		x = 1;
		x = x<<a[i]-97;
		cout<<x<<endl;
		if((x&h)>0)
		{
			cout<<a[i]<<" is duplicate.";
		}
		else
		{
			h = x|h;
			cout<<h<<endl;
		}
	}
}

int main()
{
	char a[] = "finding";

	int h = 0 ;

	findingduplicates(a);
}
