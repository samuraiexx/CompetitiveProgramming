#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> adj[200001];
ll val[200001];
ll bt[200001];
set<ll> allBefore[200001];
ll wwe[200001];

ll gcd(ll a, ll b) {	return b ? gcd(b, a%b) : a;	}

void dfs(ll n, ll f)
{
	if(f != -1)
	{
		bt[n] = wwe[f];
		allBefore[n].insert(bt[n]);
		wwe[n] = gcd(val[n], wwe[f]);
		for(auto a : allBefore[f])
				bt[n] = max(gcd(val[n], a), bt[n]), allBefore[n].insert(gcd(val[n], a));
		wwe[n] = gcd(wwe[f], val[n]);
	}
	else
		wwe[n] = bt[n] = val[n], allBefore[n].insert(0);
	for(auto a : adj[n])
		if(a != f)
			dfs(a, n);
}

int main(){
	ll n;
	cin >> n;
	for(ll i = 1; i <= n; i++)
		cin >> val[i];
	for(ll i = 1; i < n; i++)
	{
		ll x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, -1);
	for(ll i = 1; i < n; i++)
		cout << bt[i] << ' ';
	cout << bt[n] << endl;	
	return 0;
}
