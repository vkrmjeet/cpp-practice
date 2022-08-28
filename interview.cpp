#include<bits/stdc++.h>
using namespace std;

void numberofchar(string s)
{
	unordered_map<char,int> mp;
	for(auto i : s)
	{
		mp[i]++;
	}
	unordered_map<char,int>::iterator itr;

	for(itr = mp.begin() ; itr!=mp.end() ; itr++ )
	{
		cout<<itr->first<< " " << itr->second<<endl;
	}

}

int main()
{
	string st = "tothenew";
	numberofchar(st);
	return 0;
}
