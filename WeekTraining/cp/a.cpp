#include<bits/stdc++.h>

using namespace std;

list<long long> adj[400000];
long long rootd[400000];
long long ltree[600000];
long long lti[400000];
pair<long long, long long> sparse[600000][30]; // first nv, second tree label

long long na = 0;

void build(long long node, long long &i, long long nv)
{
	lti[node] = i;
	sparse[i++][0] = make_pair(nv, node);
	for(auto a:adj[node])
	{
		build(a, i, nv + 1);
		sparse[i++][0] = make_pair(nv, node);
	}
	na = i;
}

long long lca(long long a, long long b)
{
	a = lti[a], b = lti[b];
	if(a > b)
		swap(a, b);
  	if(a == b)
    	return sparse[a][0];
	long long d = b - a;
	for(long long i = na; i >= 0; i--)
		if((1 << i) & d)
		{
			d = i;
			break;
		}
	return  min(sparse[a][d], sparse[b - (1<<d) + 1][d]).second;
}

int main()
{
	long long n;
	cin >> n;
	while(n != 0)
	{
		for(long long i = 1; i < n; i++)
		{
			long long a, l;
			cin >> a >> l;
			adj[a].push_back(i);
			rootd[i] = rootd[a] + l;
		}
		long long tmp = 0;
		build(0, tmp, 0);
		for(long long j = 1; (1 << j) < na; j++)
			for(long long i = 0; i <= na - (1 << j); i++)
				sparse[i][j] =	min(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
		long long q;
		cin >> q;
		for(long long i = 0; i < q; i++)
		{
			long long s, t;
			cin >> s >> t;
			cout << rootd[s] + rootd[t] - 2*rootd[lca(s, t)] << endl;
		}
		cin >> n;
	}
    return 0;
}
