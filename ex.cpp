#include<bits/stdc++.h>
using namespace std;

void simplesieve(vector<int> &p,int n)
{
    vector<bool> isprime(n,true);
    int upto = sqrt(n);
    for(int i = 2 ; i < n ; i++)
    {
        if(isprime[i]==true)
        {
            cout<<i<<" ";
        }
        if(upto<i) continue;
        for(int j = i*2 ; j<n ; j+=i)
        {
            isprime[j] = false;
        }
    }
    for(int i = 2 ; i < n ; i++)
    {
        if(isprime[i]==true)
        {
            p.push_back(i);
        }
    }
}

void segmentedsieve(int n)
{
    vector<int> prime;
    int limit = floor(sqrt(n));
    simplesieve(prime,n);
    int low = limit;
    int high = limit*2;
    while(low<n)
    {
        if(high>n)
        {
            high = n;
        }
        vector<bool> segment(limit,true);
        for(int i = 0 ; i < prime.size() ; i++)
        {
            int lonum = round(low/prime[i])*prime[i];
            if(lonum<low) lonum += prime[i];

            for(int j=lonum ; j<high ; j+=prime[i])
            {
                segment[j] = false;
            }
        }
        for(int i = low ; i<high ; i++)
        {
            if(segment[i]==true)
            {
                cout<<i<<" ";
            }
        }
        low += limit;
        high += limit;
    }
}

int main()
{
    segmentedsieve(1000000);


    return 0;
}
