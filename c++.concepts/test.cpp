#include<iostream>
using namespace std;

struct rectangle {
int length;
int breadth;
};

struct rectangle *func()
{
	struct rectangle *p;
	p = new rectangle;

	p->length = 10;
	p->breadth = 20;
	return p;
}

int main()
{
	struct rectangle *p=func();
	cout<<"length : "<<p->length<<" , breadth : "<<p->breadth<<endl;

	return 0;
}
