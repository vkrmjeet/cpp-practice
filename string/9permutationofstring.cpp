#include<bits/stdc++.h>
using namespace std;

void permutation(char a[])
{
	for(int i = 0 ; a[i]!='\0' ; i++)
	{
		for(int j = 0 ; a[j]!='\0' ; j++)
		{
			for(int k = 0 ; a[k]!='\0' ; k++)
			{
				if(i!=j && j!=k && i!=k)
				{
					cout<<a[i]<<a[j]<<a[k]<<endl;
				}
			}
		}
	}cout<<endl;
}

void recpermutation(char a[],int k)
{
	static int b[10] = {0};
	static char res[10];
	int i ;
	if(a[k]=='\0')
	{
		if(res[k]=='\0')
		{
			cout<<res[k];
		}
		else
		{
			for(i = 0 ; a[i]!='\0' ; i++)
			{
		    if(b[i]==0)
			{
			res[k] = a[i];
			b[i] = 1;
			recpermutation(a,k+1);
			b[i] = 0;
	      	}
	        }
		}
	}

}

int main()
{
	char a[] = "abc";

	recpermutation(a,3);
}
