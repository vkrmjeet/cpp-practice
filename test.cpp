#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pascal(int n)
{
    vector<vector<int>>res(n);
    for(int i = 0 ; i < n ; i++)
    {
        res[i].resize(i+1);
        res[i][0] = res[i][i] = 1;
        for(int j = 1 ; j<i ; j++)
        {
            res[i][j] = res[i-1][j] + res[i-1][j-1];
        }
    }
    return res;
}

vector<int> specificrowpascal(int n)
{
    vector<int> res (n);
    res[0] = 1;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i ; j>=1 ; j--)
        {
            res[j] += res[j-1];
        }
        for(int j = 0 ; j < n ; j++)
        {
            cout<<res[j]<<" ";
        }cout<<endl;
    }
    return res;
}

int main()
{
    vector<vector<int>> res = pascal(5);

    /*for(int i = 0 ; i < res.size() ; i++ )
    {
        for(int j = 0 ; j < res.size()-i+1 ; j++)
        {
            cout<<" ";
        }
        for(int j = 0 ; j<res[i].size() ; j++)
        {
            cout<<res[i][j]<<" ";
        }cout<<endl;
    }*/

    vector<int> re = specificrowpascal(5);
    for(int i = 0 ; i < re.size() ; i++)
    {
        cout<<re[i]<<" ";
    }

    return 0;
}
