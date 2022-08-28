#include<iostream>
using namespace std;

int static res = 0;
int static cons = 0;

int countvowel(char arr[],int n)
{
	if(res==0)
	{
		for(int i = 0 ; i < n ; i++)
		{
		  if ( arr[i]=='a' | arr[i]=='e' | arr[i]=='o' | arr[i]=='i' | arr[i]=='u')
		   {
			res++;
		   }
		   else if(arr[i]==' ')
		   {

		   }
		   else
			 {cons++;}
	    }
	    return res;
	}
	else
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

	int vow = countvowel(wel,i);
	cout<< "vowels : "<<vow<<" & consonants : "<<cons<<endl;
}
