#include<bits/stdc++.h>
using namespace std;

class matrixrotation
{
public:
	vector<vector<int>> m;
	matrixrotation()
	{
		m = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	}

	void printmatrix()
    {
	for(int i = 0 ; i < m.size() ; i++ )
	{
		for(int j = 0 ; j < m[i].size() ; j++ )
		{
			cout<<m[i][j]<<" ";
		}cout<<endl;
	}
    }

void clockrotate()
{
	for(int i = 0 ; i < m.size() ; i++ )
	{
		for(int j = i ; j < m[i].size() ; j++ )
		{
			if(i!=j)
			{
				swap(m[i][j],m[j][i]);
			}
		}
	}
	for(int i = 0 ; i < m.size() ; i++ )
	{
		int j = 0;
		int k = m[i].size()-1;
		while(j<k)
		{
			swap(m[i][j],m[i][k]);
			j++;
			k--;
		}
	}
}

void anticlockrotate()
{
	for(int i = 0 ; i < m.size() ; i++ )
	{
		int j = 0;
		int k = m[i].size()-1;
		while(j<k)
		{
			swap(m[i][j],m[i][k]);
			j++;
			k--;
		}
	}
	for(int i = 0 ; i < m.size() ; i++ )
	{
		for(int j = i ; j < m[i].size() ; j++ )
		{
			if(i!=j)
			{
				swap(m[i][j],m[j][i]);
			}
		}
	}
}
};

int main()
{
	matrixrotation m;
	cout<<"Before rotation : "<<endl; m.printmatrix();
	m.clockrotate();
	cout<<"After Clockwise Rotation : "<<endl; m.printmatrix();

	matrixrotation m2;
	cout<<"Before rotation : "<<endl; m2.printmatrix();
	m2.anticlockrotate();
	cout<<"After Anticlockwise Rotation : "<<endl; m2.printmatrix();


	return 0;
}
