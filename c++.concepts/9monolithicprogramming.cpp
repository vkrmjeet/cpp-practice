#include<iostream>
using namespace std;

int main()
{
	int length=0,breadth=0;
	cout<<"Enter length of rectangle : ";
	cin>>length;
	cout<<"Enter breadth of rectangle : ";
	cin>>breadth;

	int area=length*breadth;
	int perimeter = 2*(length+breadth);

	cout<<"Area : "<<area<<"\nPerimeter : "<<perimeter<<endl;

	return 0;
}
