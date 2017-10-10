#include <iostream>
#include <queue>
#include <list>
#include <functional>
#include <set>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		list<int> adj[500];
		int n, m, smallst = 10000000;
      	int prune_level = 10000000;
		cin >> n >> m;
		for(int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		for(int i = 0; i < n; i++)
		{
			int vis[500];
			for(int i = 0; i < n; i++) vis[i] = 0;
			queue<pair<int, pair<int, int>>> q; //father, node, dist
			q.push(make_pair(-1, make_pair(i, 0)));
			while(!q.empty())
			{
				auto p = q.front();
				q.pop();
              			if(p.second.second > prune_level)
                			 break;
				if(vis[p.second.first])
				{
					int cycle = p.second.second + vis[p.second.first];
					prune_level = p.second.second;
					if(cycle < smallst)
                 				smallst = cycle;
					continue;
				}
				vis[p.second.first] = p.second.second;
				for(auto a:adj[p.second.first])
					if(a != p.first)
						q.push(make_pair(p.second.first, make_pair(a, 1 + p.second.second)));
			}
			
		}
		cout << "Case " << i + 1 << ": ";
		if(smallst == 10000000)
			cout << "impossible\n";
		else
			cout << smallst << '\n';
	}
	return 0;
}
