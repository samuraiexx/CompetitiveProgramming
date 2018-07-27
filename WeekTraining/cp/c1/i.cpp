#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	string s;
	while(!(cin >> s).eof())
	{
		map<char, int> cnt;
		int mx1 = 0, mx2 = mx1; //mx1 > mx2
		for(auto c : s)
			cnt[c]++;
		for(auto a : cnt)
		{
			if(a.second > mx2)
				if(a.second > mx1)
					mx2 = mx1, mx1 = a.second;
				else
					mx2 = a.second;
		}
		cout << s.size() - mx1 - mx2 << endl;
	}
}
