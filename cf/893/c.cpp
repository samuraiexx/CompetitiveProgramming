#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
vector<int> adj[N];
int gold[N];
bool vis[N];

int dfs(int n){
    int mn = gold[n];
    vis[n] = true;
    for(auto v : adj[n])
        if(!vis[v]) mn = min(mn, dfs(v));
    return mn;
}

int main(){
    int n, m;
    ll ans = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &gold[i]);
    for(int i = 0, a, b; i < m; i++)
        scanf("%d%d", &a, &b), adj[a].push_back(b), adj[b].push_back(a);

    for(int i = 1; i <= n; i++)
        if(!vis[i]) ans += (ll)dfs(i);

    printf("%lld\n", ans);
    return 0;
}
