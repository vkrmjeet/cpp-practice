#include<iostream>
using namespace std;
int main()
{
	// a and r will be exactly same througout the program
	// reference is not a ointer and it doesn't consume memory.
	int a=10;
	int &r = a;

	int b=20;
	r = b;
	cout<<a<<endl;
	cout<<r<<endl;
	r++;
	cout<<a<<endl;
	cout<<r<<endl;
}
