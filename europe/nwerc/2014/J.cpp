#include<bits/stdc++.h>
using namespace std;

int main(){
	map<string, int> cnt;
	int n;
	string s;
	int ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> s, cnt[s]++;
	
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		if(cnt[s])
			cnt[s]--, ans++;
	}
	cout << ans << endl;
	return 0;
}
