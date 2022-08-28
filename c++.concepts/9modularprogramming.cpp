#include<iostream>
using namespace std;

class rectangle{
private:
	int length;
	int breadth;

public:
	rectangle(int len, int bre)
	{
		length=len;
		breadth=bre;
	}

	int area()
	{
		return length*breadth;
	}

	int perimeter()
	{
		return 2*(length+breadth);
	}
};


int main()
{
	rectangle r(10,20);
	cout<<r.area()<<endl;
	cout<<r.perimeter()<<endl;

	return 0;
}
