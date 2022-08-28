#include<iostream>
using namespace std;

void perm(char s[],int k)
{
	static int a[10] = {0};
	static char res[10];
	if(s[k]=='\0')
	{
		for(int i = 0 ; res[i] != '\0' ; i++)
			{
				cout<<res[i];
			}cout<<endl; return ;

	}
	else
	{
		for(int i = 0 ; s[i]!= '\0' ; i++)
		{
			if(a[i]==0)//if we remove this condition it will print all the possible combinations when char are repeated
				{
				res[k] = s[i];
				a[i] = 1;
				perm(s,k+1);
				a[i] = 0;
			}
		}
	}
}

int main()
{
	char a[] = "abc";

	perm(a,0);
}
