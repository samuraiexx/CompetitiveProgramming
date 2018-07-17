#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int gr[105][105];
int cap[105];
int par[105];
int n;

int bfs()
{
	memset(cap, 0, 105*sizeof(cap[0]));
	cap[0] = 0x3f3f3f;
	queue<int> q;
	q.push(0);
	while(q.size())
	{
		auto p = q.front();
		q.pop();
		for(int i = 0; i < 105; i++)
			if(gr[p][i] && !cap[i])
			{
				cap[i] = min(cap[p], gr[p][i]), par[i] = p, q.push(i);
				if(i == 104)
					return cap[i];
			}
	}
	return 0;
}

int main(){
	int ans = 0;
	vector<pair<int, int>> votes;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		votes.push_back(make_pair(x, y));
	}
	for(int i = 1; i <= n; i++)
	{
		int vw= 0;
		int maxf = 0;
		for(int i = 0; i < 105; i++)
			for(int j = 0; j < 105; j++)
				gr[i][j] = 0;
		for(int i = 1; i <= n; i++)
		{
			int x = votes[i - 1].first, y = votes[i - 1].second;
			gr[i][n + x] = 1;
			gr[i][n + y] = 1;
		}
		for(int i = 0; i < 105; i++)
			gr[0][i] = 0;
		for(int k = 1; k <= n; k++)
			if(gr[k][n + i])
				vw++;
			else if(k != i)
				gr[0][k] = 1;
		for(int k = 1; k <= n; k++)
			if(gr[i][n + k])
				gr[n + k][104] = vw - 2;
			else
				gr[n + k][104] = vw - 1;
		while(int m = bfs())
		{
			maxf += m;
			int i = 104;
			while(i)
			{
				gr[i][par[i]] += m;
				gr[par[i]][i] -= m;
				i = par[i];
			}
		}
		if(maxf != n - vw - 1)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
