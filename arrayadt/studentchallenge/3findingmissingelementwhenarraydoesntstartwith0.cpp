#include<iostream>
using namespace std;

struct aray{
  int a[20];
  int length;
  int size;
};

//it can also be said as the efficient approach
int findingmissingelement(struct aray ar)
{
	int diff = ar.a[0];
	for(int i = 0 ; i<ar.length ; i++)
	{
		if(ar.a[i]-i!=diff)
		{
			return i+1;
		}
	}
	return -1;
}

int main()
{
	struct aray ar = {{1,2,3,4,5,6,7,8,9,11,12},11,15};

	int res = findingmissingelement(ar);

	res == -1 ? cout<< "No element is missing"<<endl : cout<<res<< " is the missing element "<<endl;
}
