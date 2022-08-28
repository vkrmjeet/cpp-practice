#include<bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) {
        int n = p.length();
        vector<int> res;
        int window = p.length();
        int k = 6;
        for(int i = 0 ; i < s.length()-window+1 ; i++)
        {
            bool r=true;
			int count[26] = {0};
			int z = 0;
            for(int j = i ; j < window+i && j<s.length() ; j++)
            {
            	count[s[j]-'a']++;
            	count[p[z]-'a']--;
            	z++;
            }
            for(int j = 0 ; j < 26 ; j++)
			{
				if(count[j]>0)
				{
					r = false;
					break;
				}
			}
            if(r==true) {res.push_back(i);}
            else { continue; }
        }
        return res;
    }

int main()
{
	string s = "cbaebabacd", p = "abc";

	vector<int> re=findAnagrams(s,p);

	for(int i = 0 ; i < re.size() ; i++)
	{
		cout<<re[i]<<endl;;
	}
	return 0;
}
