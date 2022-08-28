#include<iostream>
using namespace std;

class rectangle {
private:
int length;
int breadth;

public:
void initialize(int len,int bre)
{
	length=len;
	breadth=bre;
}

int area()
{
	return length*breadth;
}

void changelength(int len)
{
	length=len;
}
};
int main()
{
	rectangle r;

	r.initialize(10,20);
	cout<<r.area()<<endl;
	r.changelength(40);
	cout<<r.area()<<endl;

	return 0;
}
