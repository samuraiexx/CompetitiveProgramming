#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int trie[10000000][2];
bool isthere[300002];

int main(){
	int n, m, ts = 1;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		int s;
		cin >> s;
		isthere[s] = 1;
	}
	for(int s = 0; s <= 300001; s++)
	{
		if(isthere[s])
			continue;
		int p = 0;
		for(int i = 24; i >= 0; i--)
		{
			bool bit = (1 << i) & s;
			if(trie[p][bit])
				p = trie[p][bit];
			else
				p = trie[p][bit] = ts++;
		}
	}
	int acc = 0;
	for(int i = 0; i < m; i++)
	{
		int x, ans = 0;
		cin >> x;
		acc ^= x;
		int p = 0;
		for(int i = 24; i >= 0; i--)
		{
			bool bit = (1 << i) & acc;
			if(trie[p][bit]) p = trie[p][bit];
			else p = trie[p][!bit], ans += (1 << i);

		}
		cout << ans << '\n';
	}
	return 0;
}
