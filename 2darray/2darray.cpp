#include<bits/stdc++.h>
using namespace std;

int main()
{
	//1st method
	int A[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	for(int i=0 ; i<3 ; i++)
	{
		for(int j=0 ; j<4 ; j++)
		{
			cout<<A[i][j]<<" ";
		}cout<<endl;
	}

	//2nd method create an array of pointers and then assign those to the array in heap
	int *b[3];
	b[0] = new int[4];
	b[1] = new int[4];
	b[2] = new int[4];
	for(int i=0 ; i<3 ; i++)
	{
		for(int j=0 ; j<4 ; j++)
		{
			cout<<b[i][j]<<" ";
		}cout<<endl;
	}

	//3rd method we will create a double pointer and then assign it to the 2d array in heap
	int **c;
	c = (int **)new int[3];
	c[0] = new int[4];
	c[1] = new int[4];
	c[2] = new int[4];
	for(int i=0 ; i<3 ; i++)
	{
		for(int j=0 ; j<4 ; j++)
		{
			cout<<c[i][j]<<" ";
		}cout<<endl;
	}
	//we can traverse all the arrays that are created in different ways in the same way.

	return 0;
}
