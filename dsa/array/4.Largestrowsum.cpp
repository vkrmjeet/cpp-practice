#include<bits/stdc++.h>
using namespace std;

int commonele(int arr[][5],int m , int n)
{
	unordered_map<int,int> mp;
	for( int j = 0 ; j < n ; j++ )
	{
		mp[arr[0][j]] = 1;
	}

	for(int i = 1 ; i < m ; i++ )
	{
		for( int j = 0 ; j < n ; j++ )
		{
			if(mp[arr[i][j]]==i)
			{
				mp[arr[i][j]]+=1;
				if(i==m-1 && mp[arr[i][j]]==m)
				{
					cout<<arr[i][j]<<" ";
				}
			}
		}
	}
}

int main()
{
	int arr[4][5] = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9},
            };
	commonele(arr,4,5);
	return 0;
}
