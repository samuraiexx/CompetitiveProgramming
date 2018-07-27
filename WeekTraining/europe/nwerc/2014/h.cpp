#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
int vis[10001][2];

int main(){
	int n;
	queue<int> q;
	cin >> n;
	for(int i = 1, a, b; i < n; i++)
		cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);
	int p = 1;
	int cnt = 3;
	vis[p][0] = 1, vis[p][1] = 2;
	int v = adj[p][0];
	vis[v][1] = vis[p][0];
	vis[v][0] = cnt++;
	q.push(v);
	for(int i=1;i<adj[p].size();i++){
		int v = adj[p][i];
		vis[v][1] = vis[p][1];
		vis[v][0] = cnt++;
		q.push(v);
	}
	while(q.size())
	{
		int n = q.front(); q.pop();
		for(int v : adj[n]){
			if(!vis[v][0])
			{
				vis[v][1] = vis[n][0];
				vis[v][0] = cnt++;
				q.push(v);
			}
		}
	}
	if(n > 2)
		for(int i = 1; i <= n; i++)
			cout << vis[i][0] << ' ' << vis[i][1] << '\n';
	else 
		cout << "1 2\n2 1\n";
	return 0;
}
