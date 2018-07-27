#include <iostream>
#include <vector>

using namespace std;

bool vis[5000];

int dfs(int n, vector<int> *adj)
{
	int cnt = 0;
	vis[n] = true;
	for(auto a : adj[n])
		if(!vis[a])
			cnt += dfs(a, adj) + 1;
	return cnt;
}

int main()
{
	int a, b, e, p;
	while(!(cin >> a >> b >> e >> p).eof())
	{
		int ansa = 0, ansb = 0, ansn = 0;
		vector<int> *adj = new vector<int>[e];
		vector<int> *iadj = new vector<int>[e]; 
		for(int i = 0; i < p; i++)
		{
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			iadj[y].push_back(x);
		}
		for(int i = 0; i < e; i++)
		{
			for(int i = 0; i < e; i++)
				vis[i] = false;
			int inf = dfs(i, adj);
			for(int i = 0; i < e; i++)
				vis[i] = false;
			int sup = dfs(i, iadj);
			if(inf + a >= e)
				ansa++;
			if(inf + b >= e)
				ansb++;
			if(sup >= b)
				ansn++;
		}
		delete[] adj, iadj;
		cout << ansa << '\n' << ansb << '\n' << ansn << '\n';
	}
	return 0;
}
