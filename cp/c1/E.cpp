#include <iostream>
#include <queue>

using namespace std;

int dist[500][500];
int t[500][500];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main(){
	int n, m;
	while(!(cin >> n >> m).eof())
	{
		queue<pair<int, int>> q;
		int ans = -1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				char c;
				cin >> c;
				t[i][j] = c - '0';
				dist[i][j] = 0;
			}
		dist[0][0] = -1;
		if(t[0][0] < n)
			q.push(make_pair(t[0][0], 0)), dist[t[0][0]][0] = 1;
		if(t[0][0] < m)
			q.push(make_pair(0, t[0][0])), dist[0][t[0][0]] = 1;
		while(!q.empty())
		{
			auto p = q.front();
			q.pop();
			if(p.first == n - 1 && p.second == m - 1)
			{
				ans = dist[p.first][p.second];
				break;
			}
			for(int i = 0; i < 4; i++)
			{
				int nx = p.first + dx[i]*t[p.first][p.second];
				int ny = p.second + dy[i]*t[p.first][p.second];
				if(nx >= n || ny >= m || nx < 0 || ny < 0 || dist[nx][ny])
					continue;
				dist[nx][ny] = dist[p.first][p.second] + 1;
				q.push(make_pair(nx, ny));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
