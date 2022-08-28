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
	int x = 0;
	cout<< "enter value of variable : ";
	cin>>x;
	int result = 0;
	for(int i = 0 ; i < p.n ; i++)
	{
		result += p.t[i].coeff * pow(x,p.t[i].exp);
		cout<< "\n "<<result<< " = " <<p.t[i].coeff<< " * "<<x<< " ^ "<<p.t[i].exp<<endl;
	}
	return result;
}

void dispo(struct poly p)
{
	for ( int i = 0 ; i<p.n ; i++)
	{
		cout<< "coefficient : "<<p.t[i].coeff << " exponent : "<<p.t[i].exp<<endl;
	}
}

void dispo(struct poly p,int x)
{
	static int y = 0;
	for ( int i = 0 ; i<x ; i++)
	{
		cout<<y++<< "traversal "<<endl;
		cout<< "*****coefficient : "<<p.t[i].coeff << " exponent : "<<p.t[i].exp<<endl;
	}
}

void addpo(struct poly p , struct poly p2)
{
	struct poly p3;
	p3.n = p.n+p2.n;
	p3.t = new term[p3.n];

	int i = 0 , j = 0 , k = 0;
	while(i<p.n && j<p2.n)
	{
		if(p.t[i].exp > p2.t[j].exp)
		{
			p3.t[k++] = p.t[i++];
		}
		else if(p.t[i].exp < p2.t[j].exp)
		{
			p3.t[k++] = p2.t[j++];
		}
		else
		{
			p3.t[k] = p.t[i];
			p3.t[k++].coeff = p2.t[j++].coeff + p.t[i++].coeff;
		}
		dispo(p3,k);
	}
	for(;i<p.n ; i++)
	{
		p3.t[k++] = p.t[i];
	}
	for(;j<p2.n ; j++)
	{
		p3.t[k++] = p2.t[j];
	}
	p3.n = k;
	dispo(p); cout<< " + "; dispo(p2); cout<< " = "; dispo(p3);
}

int main()
{
	struct poly p;
	cout<< "please enter size of first polynomial : ";
	cin>>p.n;
	struct poly p2;
	cout<< "please enter size of second polynomial : ";
	cin>>p2.n;

	p.t = new term[p.n];
	p2.t = new term[p2.n];

	setpo(p);
	setpo(p2);

	addpo(p,p2);

	return 0;
}
