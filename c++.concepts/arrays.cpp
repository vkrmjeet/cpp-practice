#include<iostream>

using namespace std;

int main()
{
	// the size of integers depends upon compilers , it takes 4bytes
	int A[5]; // this will create an array of size 5 integers
	A[1] = 10;
	A[0] = 22;
	//we can initialize the whole aray with 0 : int B[10] = {0};

	//let us check the size of our array with 5 integers
	cout<<sizeof(A)<<endl; //it will print 20 which means 4 bytes into 5 times
	cout<<A[0];

	printf("\n%d\n",A[0]); // we have used C code here

	int c[5] = {1,2,3,4};
	for(int i=0 ; i<5 ; i++)
	{
		cout<<c[i]<<endl;
	}
	for(int x:c) // for each function in c++
	{
		cout<<x<<endl;
	}


	return 0;
}
