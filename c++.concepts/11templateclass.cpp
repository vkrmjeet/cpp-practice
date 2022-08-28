#include<iostream>
using namespace std;

template <class t>
class arit
{
private:
	t a;
	t b;
public:
	arit(t a,t b)
	{
		this->a=a;
		this->b=b;
	}
	t add();
	t sub();
};

template<class t>
t arit<t>::add()
{
	t c;
	c=a+b;
	return c;
}

template<class t>
t arit<t>::sub()
{
	t c;
	c = a-b;
	return c;
}

int main()
{
	arit<float> ar(10.1,5);
	cout<<ar.add()<<endl;
	cout<<ar.sub()<<endl;


	arit<char> arr('a','b');
	cout<<arr.add()<<endl;
	cout<<arr.sub()<<endl;

	return 0;
}
