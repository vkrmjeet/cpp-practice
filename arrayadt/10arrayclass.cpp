#include<iostream>
using namespace std;

template<class t>
class array{
private :
	t *a;
	int size;
	int length;
public:
	array()
	{
		size = 10;
		a = new t[10];
		length=0;
	}
	array(t sz)
	{
		size = sz;
		length = 0 ;
		a = new t[size];
	}
	~array()
	{
		delete []a;
	}
	void display();

	void swap(t *x, t *y);

	void insert(int index,t x);


	//if these functions were to be declared outside the class then we have to mention template<class t> before the function init
	t del(int index);
};

template<class t>
void array<t>::swap(t *x , t *y)
{
		t temp;
		temp = *x;
		*x = *y;
		*y = temp;
	}

template<class t>
void array<t>::display()
	{
		for(int i = 0 ; i<length ; i++)
		{
			cout<<a[i]<< " ";
		}cout<<endl;
	}

template<class t>
void array<t>::insert(int index,t x)
{
		length++;
		a[length] = x;
		for(int i = length ; i>index ; i--)
		{
			swap(&a[i],&a[i-1]);
		}
}

template<class t>
t array<t>::del(int index)
{
		t x = 0;
		if(index>=0 && index<length)
		{
			x = a[index];
			for(int i = index ; i<length-1;i++)
			{
				a[i] = a[i+1];
			}length--;
		}return x;
	}

int main()
{
	array<char> ar1(10);
	ar1.insert(0,'a');
	ar1.insert(1,'b');
	ar1.insert(2,'v');
	ar1.display();
	cout<< ar1.del(0)<< " is deleted"<<endl;

	ar1.display();

	return 0;
}
