#include<iostream>
#include<queue>
#define V 8
#define I 32767
using namespace std;

void printmst(int t[][V-2] , int g[V][V])
{
	cout<<"Minimum Spanning tree edges with cost : "<<endl;
	int sum {0};
	for(int i {0} ; i<V-2 ; i++)
	{
		int c = g[t[0][i]][t[1][i]];
		cout<<" [ "<<t[0][i]<<" ------ "<<t[1][i]<<" ] cost :  "<<c<<endl;
		sum += c;
	}
	cout<<endl;
	cout<< " total cost of mst : "<< sum << endl;
}

void printarray(int a[],int n)
{
	cout<<endl;
	for(int i = 0 ; i < n ; i++)
	{
		cout<<a[i]<<" ";
	}cout<<endl;
}

void primsmst(int g[V][V],int n)
{
	int min = I;
	int track[V];
	int t[2][V-2] {0};
	int u , v;
	for(int i = 1 ; i < V ; i++)
	{
		track[i] = I;
		for(int j = i ; j < V ; j++)
		{
			if(g[i][j]<min)
			{
				u = i , v = j ,
				min = g[i][j];
			}
		}
	}
	t[0][0] = u;
	t[1][0] = v;
	track[u] = track[v] = 0;
	for(int j = 1 ; j < V ; j++)
	{
		if(track[j]!=0)
		{
			if(g[u][j]<g[v][j])
			{
				track[j] = u;
			}
			else
			{
				track[j] = v;
			}
		}
	}
	for(int i = 1 ; i < V-2 ; i++)
	{
		min = I;
		int k;
		for(int j = 1 ; j< V ; j++)
		{
			if(track[j] !=0 && g[j][track[j]]<min)
			{
				k = j;
				min = g[j][track[j]];
			}
		}
		t[0][i] = k;
		t[1][i] = track[k];
		track[k] = 0;

		for(int j = 1 ; j < V ; j++)
		{
			if(track[j]!=0 && g[j][k]<g[j][track[k]])
			{
				track[j] = k;
			}
		}
	}
	printmst(t,g);
}

int bfs(int g[V][V],int start,int n)
{
	int track[n] = {0};
	int i = start;
	queue<int> q;
	q.push(i);
	cout<<i<<" ";
	track[i] = 1;
	while(!q.empty())
	{
		i = q.front();
		q.pop();
		for(int j = 1 ; j < V ; j++)
		{
			if(track[j]==0 && g[i][j]<I)
			{
				cout<<j<<" ";
				track[j] = 1;
				q.push(j);
			}
		}
	}
	cout<<endl;
}

void dfs(int g[V][V],int start , int n)
{
	static int visited[V] = {0};
	if(visited[start]==0)
	{
		cout<<start<<" ";
		visited[start] = 1;
		for(int j = 1 ; j < V ; j++)
		{
			if(g[start][j]<I && visited[j]==0)
			{
				dfs(g,j,n);
			}
		}
	}
}

int main()
{
	int cost [V][V] {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };

    int n = sizeof(cost[0])/sizeof(cost[0][0]) - 1;
    bfs(cost,2,8);
    cout<<"\n\n\n";
    dfs(cost,2,8);
    cout<<endl;
    primsmst(cost, n);

    return 0;

}
