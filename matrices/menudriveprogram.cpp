#include<iostream>
using namespace std;


class matric{
private:
	int *a;
	int n;
public:
	matric(int x)
	{
		n = x;
		a = new int[n];
	}

	void setsize(int x)
	{
		n = x;
		a = new int[n];
	}

void setm(int i , int j ,int x)
{
	if(i==j)
	{
		a[i-1] = x;
	}
}

int get(int i , int j)
{
	if(i==j)
		return a[i-1];
	else
		return 0;
}

void display()
{
	int i , j;
	for(i = 0 ; i<n ; i++)
	{
		for(j = 0 ; j<n ; j++)
		{
			if(i==j)
				cout<<a[i];
			else
				cout<<0;
		}cout<<endl;
	}
}
};


int main()
{
	matric m(1);

	int n=1;
	do{
		cout<<endl;
		cout<< " 1. Set Size of array \n 2. Set elements \n 3. display elements \n 4. get element \n 5. Exit"<<endl;
		int x=0;
		cin>>x;
		int posx = 0 , posy = 0 , ele = 0;
		int sizee=0;
		switch(x)
		{
			case 1 : cout<< "Set size : ";
						cin>>sizee;
						m.setsize(sizee);
						break;
			case 2 : cout<< " Set elements \n ";
						cout<< "\n Enter Row : ";
						cin>>posx;
						cout<< "\n Enter column : ";
						cin>>posy;
						cout<< "\n Enter Value : ";
						cin>>ele;
						m.setm(posx,posy,ele);
						break;
			case 3 : cout<< " Display Elements \n";
						m.display();
						break;
			case 4 : cout<< " Get elements \n ";
						cout<< "\n Enter Row : ";
						cin>>posx;
						cout<< "\n Enter column : ";
						cin>>posy;
						cout<<m.get(posx,posy);
						break;
		}
	}while(n<4);


	return 0;
}
