#include <bits/stdc++.h>

using namespace std;

int main(){
	int k;
	set<char> l;
	string s;
	cin >> s >> k;
	for(auto c : s)
		l.insert(c);
	if(s.size() < k)
		cout << "impossible\n";
	else if(k > l.size())
		cout << k - l.size() <<'\n';
	else
		cout << 0 << '\n';
	return 0;
}
