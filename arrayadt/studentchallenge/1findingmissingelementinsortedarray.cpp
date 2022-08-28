#include<iostream>
using namespace std;

struct aray{
  int a[20];
  int length;
  int size;
};

int findingmissingelement(struct aray ar)
{
	int sum = 0;
	for(int i = 0 ; i<ar.length ; i++)
	{
		sum += ar.a[i];
		cout<<sum<<endl;
	}
	cout<<ar.length-1<<" ";
	int res = (ar.a[ar.length-1]*(ar.a[ar.length-1]+1) ) /2;
	if(res!=sum)
	{
		cout<<sum << " "<<res<<endl;
		return res-sum;
	}
	else
		return -1;
}

int main()
{
	struct aray ar = {{1,2,3,4,5,6,7,8,10,11,12},11,15};

	int res = findingmissingelement(ar);

	res == -1 ? cout<< "No element is missing"<<endl : cout<<res<< " is the missing element "<<endl;
}
