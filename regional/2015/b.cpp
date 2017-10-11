#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 101;

int x, vis[N], b[N], ans;
vector<int> adjt[N], adj[N];

bool match(int u) {
    if(vis[u] == x) return 0;
    vis[u] = x;
    for(int v : adj[u])
        if(!b[v] or match(b[v])) return b[v] = u;
    return 0;
}

int main(){
    int n, q;
    cin >> n >> q;
    bool can_0 = true;
    for(int i = 1; i <= n; i++){
        int b, ci;
        cin >> b;
        if(b == n) can_0 = false;
        for(int j = 0; j < b; j++)
            cin >> ci, adjt[i].push_back(ci);
    }
    for(int i = 0; i < q; i++){
        int bs;
        set<int> tb;
        cin >> bs;
        if(bs == 0){
            if(can_0) cout << "Y\n";
            else cout << "N\n";
            continue;
        }
        x = 0, ans = 0;
        for(int i = 1; i <= n; i++) adj[i].clear();
        memset(b, 0, sizeof b);
        memset(vis, 0, sizeof vis);
        for(int i = 0, c; i < bs; i++) cin >> c, tb.insert(c);
        for(int i = 1; i <= n; i++)
            for(auto bi : adjt[i])
                if(tb.count(bi)) adj[i].push_back(bi);
        for(int i = 1; i <= n; i++) ++x, ans += match(i);
        if(ans == tb.size()) cout << "Y\n";
        else cout << "N\n";
    }
   return 0;
}
