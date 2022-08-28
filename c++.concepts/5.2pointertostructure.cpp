#include<iostream>
using namespace std;

struct rectangle {
    int length;
    int breadth;
};

int main()
{
	// in c we have to write struct keyword while creating an instance of the structure but in c++ we can directly create by using
	// the name of the structure

	rectangle r = {10,20};
	cout<<r.length<<" "<<r.breadth<<endl;

	rectangle *p = &r;
	cout<<p->length<<" "<<p->breadth<<endl;



	//creating all the above things again but in heap(dynamically allocated memory)
	rectangle *q;
	q = new rectangle; // we can also use "new struct rectangle" but as we have learn struct keyword is not neccessary
	q->length=40;
	q->breadth = 80;
	cout<<q->length<<" "<<q->breadth<<endl;


	return 0;
}
