#include<bits/stdc++.h>
using namespace std;

void reversestring(char a[],int n)
{
	int j = 0 , k = n-1;
	char res[n];
	while(k>=0)
	{
		res[j++] = a[k--];
	}
	for(int b = 0 ; b<n ; b++)
	{
		cout<<res[b]<<endl;
	}
}

int main()
{
	char a[] = {'p','y','t','h','o','n'};
	int i = 0;
	while(a[i]!='\0')
	{
		cout<<a[i];
		i++;
	}cout<<" i "<<i<<endl;

	reversestring(a,i);

}
