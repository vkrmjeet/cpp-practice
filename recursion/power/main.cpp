#include <iostream>

using namespace std;

int power(int m,int n)
{
	if(n==0)
		return 1;
	if(n%2==0)
	{
		return power(m*m,n/2);
	}
	else
		return m*power(m*m,(n-1)/2);
}

int main()
{
    int n;


    cout<<"power of 3 raise to 4 is "<<power(3,5)<<endl;;
    cout<<"power of 3 raise to 4 is "<<power(3,4);




    return 0;
}
