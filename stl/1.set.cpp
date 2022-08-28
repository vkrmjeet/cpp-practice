#include<iostream>
#include<set>
using namespace std;

int main()
{
	set<int> s; // set<int , greater<int>> s   :- for descending order set
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);

	set<int>::iterator itr;

	for(itr = s.begin() ; itr !=s.end() ; itr++ )
	{
		cout<<*itr<<" ";
	}



	return 0;
}
