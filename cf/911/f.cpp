#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 1;
vector<int> adj[N];

int dist1[N];
int dist2[N];
int mx;
int n;
int v1, v2;
long long ans = 0;
int vis[N];
vector<int> lfs;

bool dfs2(int n, int f){
    int ret = 0;
    if(n == v2) return vis[n] = 2;
    for(auto a : adj[n])
        if(a != f and dfs2(a, n)){
            ret = true;
            vis[n] = 2;
            break;
        }
    return ret;
}

void dfs3(int n){
    if(n == v2) return;
    vis[n] = true;
    lfs.push_back(v2), lfs.push_back(n);
    ans += dist2[n];
    for(auto a : adj[n])
        if(vis[a] == 2) dfs3(a);
}

void dfs(int n, int f, int d, int* dist){
    for(auto a : adj[n])
        if(a != f) dfs(a, n, d + 1, dist);
    mx = max(mx, d);
    dist[n] = d;
}

int main(){
    priority_queue<pair<int, int>> d1, d2;
    cin >> n;
    for(int i = 1, a, b; i < n; i++)
        cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);

    dfs(1, -1, 0, dist1);
    for(int i = 1; i <= n; i++)
        if(dist1[i] == mx) { v1 = i; break; }
    mx = 0;
    dfs(v1, -1, 0, dist1);
    for(int i = 1; i <= n; i++)
        if(dist1[i] == mx) { v2 = i; break; }

    dfs(v2, -1, 0, dist2);
    for(int i = 1; i <= n; i++)
        d1.push({dist1[i], i}), d2.push({dist2[i], i});

    dfs2(v1, -1);

    while(d1.size() and d2.size()){
        if(vis[d1.top().second]) { d1.pop(); continue; }
        if(vis[d2.top().second]) { d2.pop(); continue; }
        pair<int, int> p;
        int n;
        if(d1.top().first > d2.top().first)
            p = d1.top(), d1.pop(), n = v1;
        else
            p = d2.top(), d2.pop(), n = v2;

        ans += p.first, lfs.push_back(n), lfs.push_back(p.second);
        vis[p.second] = 1;
    }
    dfs3(v1);

    cout << ans << endl;
    for(int i = 0; i < lfs.size(); i += 2)
        printf("%d %d %d\n", lfs[i], lfs[i + 1], lfs[i + 1]);

    return 0;

}
