#include <iostream>
#include <vector>

using namespace std;

int dt[501][501];
int fw[501][501];
int mt[501];
int vis[501];
int x;

struct {
	int s, f, t;
} fly[501];


bool match(int n, vector<vector<int>> &adj)
{
	if(vis[n] == x)
		return 0;
	vis[n] = x;
	for(int a : adj[n])
		if(!mt[a] or match(mt[a], adj)) return mt[a] = n;
	return 0;
}

int main()
{
	int n, m;
	while(cin >> n >> m)
	{
		vector<vector<int>> adj(m + 1);
		for(int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			for(int j = 1; j <= n; j++)
				if(i != j)
					fw[j][i] = dt[j][i] = x;
		}
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{
				int t;
				cin >> t;
				dt[i][j] += t;
				fw[i][j] += t;
			}
		for(int k = 1; k <= n; k++)
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++)
					fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
		for(int i = 1; i <= m; i++)
			cin >> fly[i].s >> fly[i].f >> fly[i].t;
		for(int i = 1; i <= m ; i++)
			for(int j = 1; j <= m; j++)
				if(i != j && fly[i].t + dt[fly[i].s][fly[i].f] + fw[fly[i].f][fly[j].s] <= fly[j].t)
					adj[i].push_back(j);
		int ans = 0;
		x = 0;
		for(int i = 0; i <= m; i++)
			vis[i] = mt[i] = 0;
		for(int i = 1; i <= m; i++)
			++x, ans += match(i, adj);
		cout << m - ans << '\n';
	}
	return 0;
}

