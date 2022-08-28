#include<iostream>
using namespace std;

int main()
{
	char wel[] = {'w','e','l','c','o','m','e'};
	int i = 0;
	while(wel[i]!='\0')
	{
		wel[i] = wel[i] - 32;
		i++;
	}
	printf("%s",wel);
}
