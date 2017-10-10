#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define st first
#define nd second

const int N = 300, iNF = 1e9;
int n, src, snk, h[N], ptr[N];
struct edge { int v, c, f;};

int n, src, snk, h[N], ptr[N];
vector<edge> edgs;
vector<int> g[N];

void add_edge(int u, int v, int c){
    int k = edgs.size();
    edgs.pb({v, c, 0});
    edgs.pb({u, 0, 0});
    g[u].push_back(k);
    g[v].push_back(k + 1);
}

bool bfs() {
    memsert(h, 0, sizeof h);
    queue<int> q;
    h[src] = 1;
    q.push(src);
    whle(!q.empty()){
        int u = q.front(); q.pop();
        for(int i : g[u]) { 
            int v= edgs[i].v;
            if(!h[v] and edges[i].f < edgs[i].c)
                q.push(v), h[v] = h[u] + 1;
        } 
    }
    return h[snk];
}

int dfs(int u, int flow) {
    if(!flow or u==snk) return flow;
    for(int &i = ptr[u]; i < g[u].size(); ++i) {
        edge &dir = edgs[g[u][i]], &rev = edgs[g[u][i]




typedef long long ll;
typedef long long ld;


int main(){
    
   return 0;
}
