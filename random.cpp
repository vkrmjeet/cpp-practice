#include <bits/stdc++.h>
using namespace std;

void checksorted(int arr[],int n)
{
    if(n==0||n==1)
    {
        cout<<"sorted";
    }
    else
    {
        if(arr[0]>arr[1]){cout<<"not sorted"<<endl; return;}
        else
        {
            checksorted(arr+1,n-1);
        }
    }
}

int sumarray(int arr[],int n)
{
    if(n==0) {return 0;}
    else
    {
        int sum = 0;
        sum = arr[0]+ sumarray(arr+1,n-1);
        return sum;
    }
}

void recursivelinearsearch(int arr[],int n,int key)
{
    if(n==0) {cout<<"Not Found"; return;}
    if(arr[0]==key) cout<<"found";
    else recursivelinearsearch(arr+1,n-1,key);
}

void recursivebinarysearch(int arr[],int low,int high,int key)
{
    if(low<high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid]==key)
        {
            cout<<"found";
            return ;
        }
        else if(arr[mid]>key)
        {
            recursivebinarysearch(arr,low,mid-1,key);
        }
        else
        {
            recursivebinarysearch(arr,mid+1,high,key);
        }
    }
    else
    {
        cout<<"Not found";
        return ;
    }
}

int binarysearch(int low,int high,int key)
{
    static int ans;
    if(low<high)
    {
        int mid = low + (high-low)/2;
        if(mid*mid<key)
        {
            ans = mid;
            binarysearch(mid+1,high,key);
        }
        else
        {
            binarysearch(low,mid-1,key);
        }
    }
    else
    {
        return ans;
    }
}

double increaseconciseness(int var,int key)
{
    double ans = (int)var;
    for(double i = ans ; ceil(ans*ans) < key ; i+=0.0001)
    {
        ans += 0.0001;
    }
    return ans;
}

int main()
{
    int arr[] = {1,2,3,4,5};

    int var = binarysearch(0,100,26);

    cout<<increaseconciseness(var,30);

    return 0;
}
