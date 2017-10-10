#include <bits/stdc++.h>
using namespace std;

#define px first
#define py second

pair<double, double> pnt[100];

vector<int> adj[100];

int d[100];

int dfs(int n)
{
	int mx = 0;
	if(d[n]) return d[n];
	for(auto a : adj[n])
		mx = max(mx, dfs(a));
	return d[n] = mx + 1;
}

int main(){
	int n;
	double a, b;
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++)
		cin >> pnt[i].px >> pnt[i].py;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(pnt[i].py > pnt[j].py &&
			(pnt[i].px - a)*pnt[j].py/pnt[i].py + a < pnt[j].px &&
			b - (b - pnt[i].px)*pnt[j].py/pnt[i].py > pnt[j].px) adj[j].push_back(i);
	
	for(int i = 0; i < n; i++)
		if(!d[i]) dfs(i);
	cout << *max_element(d, &d[n]) << endl;
}
