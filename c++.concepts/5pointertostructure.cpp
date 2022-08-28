#include<iostream>
using namespace std;

struct rectangle{
int len;
int breadth;
};

int main()
{
	// we cannot access structure variable from pointers directly
	// there are two ways
	struct rectangle r = {10,20};
	struct rectangle *p;
	p = &r;
	cout<<(*p).len<<endl;
	p->len=15;
	cout<<p->len<<endl;
	cout<<r.len<<endl;


	// dynamically created structure
	struct rectangle *q;
	// we have to dynamically allocate memory
	// we have to typecast because malloc function returns void
	q = (struct rectangle *)malloc(sizeof(struct rectangle));
	q->len = 25;
	q->breadth = 50;
	cout<<q->len<<endl;

	cout<<"\n \n \n ";
	struct rectangle *j;
	j = new struct rectangle;
	j->len = 10;
	cout<<j->len;


}
