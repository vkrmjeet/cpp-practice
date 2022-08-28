#include<iostream>
using namespace std;

void print(int arr[][4],int m , int n)
{
	cout << " The array : "<<endl;
	for(int i = 0 ; i < m ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			cout<<arr[i][j]<<" ";
		}cout<<endl;
	}
}

void spiralprint(int arr[][4],int m , int n)
{
	int rowstart,rowend,colstart,colend;
	rowstart = colstart = 0;
	rowend = m-1;
	colend = n-1;
	int total = m*n;
	int row,column;
	while(total>0)
	{
		row = rowstart ; column = colstart;
		while(column<=colend)
		{
			cout<<arr[row][column]<<" ";
			total--; column++;
		}rowstart++;
		row = rowstart; column = colend;
		while(row<=rowend)
		{
			cout<<arr[row][column]<<" ";
			row++;
			total--;
		}colend--;
		row = rowend; column = colend;
		while(column>=colstart)
		{
			cout<<arr[row][column]<<" ";
			column--;
			total--;
		}rowend--;
		row = rowend; column = colstart;
		while(row>=rowstart)
		{
			cout<<arr[row][column]<<" ";
			row--;
			total--;
		}colstart++;
	}

}

void revspiralprint(int arr[][4],int n,int m)
{
	int rowstart,colstart,rowend,colend;
	rowstart = colstart = 0;
	rowend = m-1; colend = n-1;
	int row,col;
	int total = m*n;
	while(total>0)
	{
		row = rowstart , col = colstart;
		while(row<=rowend)
		{
			cout<<arr[row][col]<<" ";
			row++; total--;
		}colstart++;
		row = rowend , col = colstart;
		while(col<=colend)
		{
			cout<<arr[row][col]<<" ";
			col++ ; total--;
		}rowend--;
		row = rowend; col = colend;
		while(row>=rowstart)
		{
			cout<<arr[row][col]<<" ";
			row-- ; total--;
		}colend--;
		row = rowstart , col = colend;
		while(col>=colstart)
		{
			cout<<arr[row][col]<<" ";
			col-- ; total--;
		}rowstart++;
	}
}

int main()
{
	int g[][4] = {
	              {1,2,3,4},
	              {5,6,7,8},
	              {9,10,11,12},
	              {13,14,15,16}
	};

	print(g,4,4);
	cout<<endl;
	spiralprint(g,4,4);
	cout<<endl;
	revspiralprint(g,4,4);

	return 0;
}
