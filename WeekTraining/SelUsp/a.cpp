#include <bits/stdc++.h>

using namespace std;

const int N = 5e4+5;

int n, m, k, color[N], vis[N];
vector<int> adj[N];

int dfs(int u)
{
	vis[u] = 1;
	for(auto v : adj[u])
		if(!vis[v])
			color[v] = (color[u] + 1)%k, dfs(v);
}

bool nope;

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0;i<m;i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v), adj[v].push_back(u);
	}
	for(int i=1;i<=n;i++) if(!vis[i]) color[i] = 0, dfs(i);

	if(k == 1 && m > 0)
		return cout << "-1\n", 0;

	for(int i=1;i<=n;i++) printf("%d\n", color[i] + 1);
	return 0;
}
