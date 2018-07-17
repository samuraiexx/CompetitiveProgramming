#include<bits/stdc++.h>
using namespace std;

const int N = 3*1e4;

int x, vis[N], b[N], ans;
bool mat[N];
int mx = 1;
vector<int> freq[N];
vector<int> adj[N];

bool match(int u) {
	if(vis[u] == x) return 0;
	vis[u] = x;
	for(int v : adj[u])
		if(!b[v] or match(b[v])) return b[v] = u;
	return 0;
}

int main(){
	int n;
	cin >> n;
	for(int i = 1, a, b; i < n; i++)
		cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);
	for(int i = 1; i <= n; ++i) ++x, ans += match(i);
	
	for(int i = n; i >= 1; i--)
		if(!mat[b[i]])
			freq[i].push_back(mx), freq[b[i]].push_back(mx++), mat[b[i]] = 1;
	for(int i = 1; i <= n; i++)
		if(freq[i].size() == 0)
			cout << "1 1\n";
		else if(freq[i].size() == 1)
			cout << freq[i][0] << ' ' << "1\n";
		else
			cout << freq[i][0] << ' ' << freq[i][1] << '\n';
	return 0;
}
