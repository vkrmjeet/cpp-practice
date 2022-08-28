#include<iostream>
using namespace std;

void swap (char *a, char*b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b` = temp;
}

void perm(char s[],int l, int h)
{
	if(l==h)
	{
		for(int i = 0 ; s[i] != '\0' ; i++)
		{
			cout<<s[i];
		}cout<<endl; return ;
	}
	else{
		for(int i = l ; i <= h ; i++)
		{
			swap(&s[i],&s[l]);
			perm(s,l+1,h);
			swap(&s[i],&s[l]);
		}
	}
}

int main()
{
	char a[] = "abc";

	perm(a,0,2);
}
