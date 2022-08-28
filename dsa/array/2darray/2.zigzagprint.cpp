#include<iostream>
using namespace std;
/*
00 01 02 03
10 11 12 13
20 21 22 23
30 31 32 33
 */
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

void zigzag(int arr[][4],int n , int m)
{
	int rowstart = 0, colstart = 0;
	int rowend = m-1 , colend = n-1;
	int row , col;
	int total = 15;
	int a , b;
	row = rowstart; col = colstart;
	while(total>0)
	{
		while(true)
		{
			if(row==0 && col==0)
			{
			cout<<arr[row][col]<<" ";
			total--;
		    }cout<<endl;
		if(col!=colend)
		{
			col++;
		}else {break;}
		while(col >= colstart && row <=rowend)
		{
			cout<<arr[row][col]<<" ";
				row++; col--; total--;
		}row--;col++; cout<<endl;
		if(row!=rowend) {row++; } else {break;}
		while(row>=rowstart && col<=colend)
		{
			cout<<arr[row][col]<<" ";
			row--; col++; total--;
		}row++; col--; cout<<endl;
		}


		while(true)
		{
			if(row==n && col==n)
			{
				cout<<arr[row][col]<<" ";
				break;
			}
			if(row = rowend)
			{
				if(col!=colend)
				{
					col++;
				}
				while(row>=rowstart && col<=colend)
				{
					cout<<arr[row][col]<<" ";
					row--; col++; total--;
				}row++; col--; cout<<endl;
				if(row!=rowend)
				{
					row++;
				}else {break;}
				while(row<=rowend && col>=colstart)
				{
					cout<<arr[row][col]<<" ";
					row++; col--; total--;
				}row--; col++; cout<<endl;
			}
			else
			{
				//do nothing
			}

		}
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
	zigzag(g,4,4);
	cout<<endl;

	return 0;
}
