#include<iostream>
using namespace std;

struct rectangle{
  int length;
  int breadth;
};

int area(struct rectangle r1)
{
	return r1.length*r1.breadth;
}

int areabyreference(struct rectangle &s1)
{
	return s1.length*s1.breadth;
}

void changelengthbyaddress(struct rectangle *t ,int len)
{
	t->length = len;
}

int main()
{
	//call by value
	struct rectangle r = {10,20};
	cout<<area(r)<<endl;


	// call by reference
	struct rectangle s = {10,20};
	cout<<areabyreference(s)<<endl;

	//change length by address
	struct rectangle t = {10,20};
	int new_len = 40;
	changelengthbyaddress(&t,new_len);
	cout<<"new length and breadth : "<<t.length<<" "<<t.breadth;

	return 0;
}
