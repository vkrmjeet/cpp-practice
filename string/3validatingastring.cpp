#include<iostream>
using namespace std;

bool isvalid(char arr[], int n)
{
	bool res = false;
	for(int i = 0 ; i<n ; i++)
	{
		if((arr[i]>= 65 && arr[i]<=90) || (arr[i]>=97 && arr[i]<=122) || (arr[i]>=48 &&arr[i]<=57))
		{
			res = true;
		}
		else
		{
			return false;
	     }
	}
	return res;
}

int main()
{
	char wel[] = "anil@21";
	int i = 0;
	while(wel[i]!='\0')
	{
		i++;
	}

	bool ans = isvalid(wel,i);


	ans ? cout<<" valid " : cout<< "Invalid";
}
