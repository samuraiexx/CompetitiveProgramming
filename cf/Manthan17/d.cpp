#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1, M = 20;

int par[N], sz[N];
int anc[M][N], h[N];
int anc2[M][N], h2[N];
int part[N];
set<int> rt, rt2;

vector<int> adj[N], adj2[N];

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite(int a, int b) {
  if ((a = find(a)) == (b = find(b))) return;
  if (sz[a] < sz[b]) swap(a, b);
  par[b] = a; sz[a] += sz[b];
}

void dfs(int n, vector<int> *adj, int *h)
{
    for(auto a : adj[n])
        h[a] = h[n] + 1, dfs(a, adj, h);
}

bool lca(int u, int v, int anc[M][N], int *h){
    if(h[u] < h[v]) return 0;
    for(int i = M; i >= 0; --i)
        if(h[u] - (1<<i) >= h[v]) u = anc[i][u];
    if(u == v) return true;
    return false;
}

int main(){
    int n, q;
    cin >> n;
    for(int i = 1; i <= n; i++) par[i] = i;
    for(int b = 1; b <= n; b++)
    {
        int t, a;
        cin >> a >> t;
        if(t == 0)
            unite(a, b), anc2[0][b] = a, adj2[a].push_back(b);
        else if(t == 1)
            anc[0][b] = a, adj[a].push_back(b), part[b] = a;
    }
    for(int i = 1; i <= n; i++)
         if(anc[0][i]) anc[0][i] = find(anc[0][i]);
         else rt.insert(find(i));

    for(int i = 1; i <= n; i++)
         if(!anc2[0][i]) rt2.insert(i);

    for(auto r : rt)
        dfs(r, adj, h), anc[0][r] = r;

    for(auto r : rt2)
        dfs(r, adj2, h2), anc2[0][r] = r;

    for(int i = 1; (1 << i) < n; ++i)
        for(int j = 1; j <= n; j++)
            anc[i][j] = anc[i-1][anc[i-1][j]],
            anc2[i][j] = anc2[i-1][anc2[i-1][j]];
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 1)
        {
            if(lca(v, u, anc2, h2)) cout << "YES\n";
            else cout << "NO\n";
        }
        else
        {
            if(part[v] && lca(find(part[v]), find(u), anc, h)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
