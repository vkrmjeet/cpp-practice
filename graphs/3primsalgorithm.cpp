#include<bits/stdc++.h>
#define i INT_MAX
using namespace std;

 int cost[][8] = {
 	              {i,i,i,i,i,i,i,i} ,
 	              {i,i,25,i,i,i,15,i} ,
 	              {i,25,i,12,i,i,i,10} ,
 	              {i,i,12,i,8,i,i,i} ,
 	              {i,i,i,8,i,16,i,14} ,
 	              {i,i,i,i,16,i,20,18} ,
 	              {i,5,i,i,i,20,i,i} ,
 	              {i,i,10,i,14,18,i,i} ,
                  };
int near[8] = {i,i,i,i,i,i,i,i};
int t[2][6];



int main()
{
	int I,j,k,u,v,n=7,min=i;
	for( I = 1 ; I < n ; I++ )
	{
		for( j = I ; j < n ; j++)
		{
			if(cost[I][j]<min)
			{
				min = cost[I][j];
				u = I;
				v = j;
			}
		}
    }
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;

    for( I = 1 ; I < n ; I++)
	{
		if(near[I]!=0)
		{
		if(cost[I][u]<cost[I][v])
		{
			near[I] = u;
		}
		else
		{
			near[I] = v;
		}
		}
	}

    for(I = 1 ; I < n - 1 ; I++)
	{
		min = I;
		for(j = 1 ; j <= n ; j++)
		{
			if(near[j]!=0&&cost[j][near[j]]<min)
			{
				k = j;
				min = cost[j][near[j]];
			}
		}
		t[0][I] = k;
		t[1][I] = near[k];
		near[k] = 0;
		for(j = 1 ; j <=n ; j++)
		{
			if(near[j]!=0 && cost[j][near[k]]>cost[j][k])
			{
				near[j] = k;
			}
		}
	}

	for(I = 0 ; I < n-1 ; I++)
	{
		cout<<"( "<<t[0][I]<<" , "<<t[1][I]<<" )"<<endl;
	}


	return 0;
}
