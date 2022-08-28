#include<iostream>
using namespace std;

struct rectangle {
int length;
int breadth;
};

void initialize(struct rectangle *p,int len,int bre)
{
	p->length=len;
	p->breadth=bre;
}

int area(struct rectangle r)
{
	return r.length*r.breadth;
}

void changelength(struct rectangle *p,int len)
{
	p->length=len;
}

int main()
{
	struct rectangle r;

	initialize(&r,10,20);
	cout<<area(r)<<endl;
	changelength(&r,40);
	cout<<area(r)<<endl;

	return 0;
}
