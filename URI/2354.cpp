#include <bits/stdc++.h>
using namespace std;

const int N = 300, INF = 1e9;
struct edge {int v, c, f;};

int n, src, snk, h[N], ptr[N];
vector<edge> edgs;
vector<int> g[N];
int votos[N][2];

void add_edge (int u, int v, int c) {
  int k = edgs.size();
  edgs.push_back({v, c, 0});
  edgs.push_back({u, 0, 0});
  g[u].push_back(k);
  g[v].push_back(k+1);
}

bool bfs() {
  memset(h, 0, sizeof h);
  queue<int> q;
  h[src] = 1;
  q.push(src);
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int i : g[u]) {
      int v = edgs[i].v;
      if (!h[v] and edgs[i].f < edgs[i].c)
        q.push(v), h[v] = h[u] + 1;
    }
  }
  return h[snk];
}

int dfs (int u, int flow) {
  if (!flow or u == snk) return flow;
  for (int &i = ptr[u]; i < g[u].size(); ++i) {
    edge &dir = edgs[g[u][i]], &rev = edgs[g[u][i]^1];
    int v = dir.v;
    if (h[v] != h[u] + 1)  continue;
    int inc = min(flow, dir.c - dir.f);
    inc = dfs(v, inc);
    if (inc) {
      dir.f += inc, rev.f -= inc;
      return inc;
    }
  }
  return 0;
}

int dinic() {
  int flow = 0;
  while (bfs()) {
    memset(ptr, 0, sizeof ptr);
    while (int inc = dfs(src, INF)) flow += inc;
  }
  return flow;
}
int main(){
        src = 0; 
        while(cin >> n) 
        { 
                int ans = 0; 
                for(int i = 1; i <= n; i++) 
                        cin >> votos[i][0] >> votos[i][1]; 
                for(int i = 1; i <= n; i++) 
                { 
                        int k = 0; 
                        edgs.clear(); 
                        snk = 2*n + 1; 
                        for(int i = 0; i < N; i++) 
                                g[i].clear(); 
                        for(int j = 1; j <= n; j++) 
                        { 
                                add_edge(j, n + votos[j][0], 1); 
                                add_edge(j, n + votos[j][1], 1); 
                                if(votos[j][0] == i or votos[j][1] == i) 
                                        k++; 
                                else if(i != j) 
                                        add_edge(0, j, 1); 
                        } 
                        for(int j = 1; j <= n; j++) 
                                if(i != j) add_edge(n + j, 2*n + 1, k - 1 - (votos[i][0] == j || votos[i][1] == j)); 
                        if(dinic() == n - k - 1) 
                                ans++; 
                } 
                cout << n - ans << endl; 
        } 
} 


