#include<bits/stdc++.h>
using namespace std;

bool search(vector<vector<int>> &m ,int key)
{
	int i = 0;
	int j = m.size()-1;
	int mid;
	while(i<=j)
	{
		bool iterate = true;
		int low = 0;
		int high = m[i].size()-1;
		while(low<=high)
		{
			mid = (low+high)/2;
			if(m[mid][i]==key)
			{
				return true;
				iterate = false;
				break;
			}
			else if(key<m[mid][i])
			{
				high = mid - 1;
			}
			else
			{
				low = mid+1;
			}
		}
		if(iterate==false)
		{
			break;
		}
		i++;
	}
	return false;
}

int main()
{
	vector<vector<int>> m = {{1,1}};
	int key = 5;
	cout<<search(m,0);

	return 0;
}
