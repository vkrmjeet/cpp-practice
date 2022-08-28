#include<iostream>
using namespace std;

struct rectangle{
   int len;
   int bre;
};

int main()
{
	int a = 10;
	int *p;
	p = &a;
	cout<<"location of a : "<<p<<endl;
	cout<<"value of a : "<<*p<<endl;

	cout<<"\n \n \n";

	//pointer to an array
	int d[4]={2,3,4,5};
	cout<<d;  //as d itself is the location of the first element in the array we don't have use ampersand in this case
	int *q;
	q = d;
	// if we want to use ampersand then we have to point it to the first value\
	// q = d[0];
	cout<<endl;
	for(int i=0 ; i<4 ; i++)
	{
		cout<<d[i]; // we can also use q in the place of d
	}

	cout<<"\n \n \n";

	int *r;
	r = new int[5];
	r[0]=1;
	r[1]=2;
	for(int i=0 ; i<5 ; i++)
		cout<<r[i]<<endl;

	// the extra values are called as garbage values
	// we should always release the dynamically allocated memory
	delete []r;



	//let us take pointer of few datatypes that we have
	int *e;
	char *f;
	float *j;
	double *h;
	struct rectangle *i;

	//every pointer take same amount of memory as it is only storing the value location
	// we can say the size of pointer is independent of the type of data is storing.
	cout<<sizeof(e)<<endl;
	cout<<sizeof(f)<<endl;
	cout<<sizeof(j)<<endl;
	cout<<sizeof(h)<<endl;
	cout<<sizeof(i)<<endl;

	return 0;
}
