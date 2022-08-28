#include<iostream>
using namespace std;

struct example{
  int d;
  int c;
  char b;
  unsigned long long int a;
 };

struct rectangle{
   int length;
   int breadth;
   char x; // it should take 9 bytes but it takes 12 bytes because it is easy for our machine to read 4 bytes sequential data
           // but it will use only 1 byte data , it is allocating to make it easily accessible
	double a;
}//we can declare variables here also like r1 here also and they will become global variables
;

int main()
{
	// we can declare a structure variable outside the main function also
	struct rectangle rect = {10,20};
	struct rectangle r2 ;
	r2.length = 5;
	r2.breadth = 10;
	cout<<"area of rectangle "<<rect.length*rect.breadth<<endl;
	cout<<"size of structure "<<sizeof(example)<<endl; // it will print 8 as there are two integers of 4 bytes per interger
}
