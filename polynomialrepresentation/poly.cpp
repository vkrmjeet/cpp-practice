#include<bits/stdc++.h>
using namespace std;

struct term
{
	int coeff;
	int exp;
};

struct poly
{
	int n;
	struct term *t;
};

void setpo(struct poly &p)
{
	for(int i = 0 ; i<p.n ; i++)
	{
		cout<< "please enter coefficient : ";
		cin>>p.t[i].coeff;
		cout<< "please enter exponent : ";
		cin>>p.t[i].exp;
	}
}

int getpo(struct poly p)
{
	int x = 9;
	int result = 0;
	for(int i = 0 ; i < p.n ; i++)
	{
		result += p.t[i].coeff * pow(x,p.t[i].exp);
		cout<< "\n "<<result<< " = " <<p.t[i].coeff<< " * "<<x<< " ^ "<<p.t[i].exp<<endl;
	}
	return result;
}

int main()
{
	struct poly p;
	cout<< "please enter size of polynomial : ";
	cin>>p.n;

	p.t = new term[p.n];

	setpo(p);

	int res = getpo(p);

	cout<<res<<endl;

	return 0;
}
