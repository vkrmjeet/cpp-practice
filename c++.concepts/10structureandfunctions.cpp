#include<iostream>
using namespace std;

struct rectangle {
    int length;
    int breadth;
};

int area(rectangle r)
{
	return r.length*r.breadth;
}

int perimeter(rectangle r)
{
	return 2*(r.length*r.breadth);
}

int main()
{
	rectangle r = {10,20};

	cout<<area(r)<<endl;
	cout<<perimeter(r)<<endl;

	return 0;
}
