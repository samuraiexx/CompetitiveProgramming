#include <bits/stdc++.h>

using namespace std;

int chutes[50000];

bool vis[50000];
pair<int, int> best;

int main(){
	int n, s, x;
	srand(time(0));
	cin >> n >> s >> x;
	for(int i = 0; i < n; i++)
		chutes[i] = i + 1;
	random_shuffle(chutes, &chutes[n]);
	cout << "? " << s << endl;
	int nxt, v;
	cin >> v >> nxt;
	vis[s] = 1;
	best = {nxt, v};
	int mx = min(n, 1500) + 1;
	for(int i = 0; i < mx && i < n; i++)
	{
		if(vis[chutes[i]])
		{
			mx++;
			continue;
		}
		cout << "? " << chutes[i] << endl;
		cin >> v >> nxt;
		if(v > best.second && v <= x)
			best = {nxt, v};
		if(nxt != -1)
			 vis[nxt] = 1;
		vis[chutes[i]] = 1;

	}
	for(int i = 0; i < 500; i++)
	{
		if(best.second >= x)
			return cout << "! " <<  best.second << endl, 0;
		if(best.first == -1)
			return cout << "! -1" << endl, 0;
		cout << "? " << best.first << endl;
		cin >> best.second >> best.first;
	}
	return cout << "! " <<  best.second << endl, 0;
	return 0;
}
