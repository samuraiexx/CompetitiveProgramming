#include<bits/stdc++.h>

using namespace std;

const int N = 1001;
vector<int> adj[N];
int val[N];
int cost[N];

int main(){
    int n, m, ans = 0;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i ++) cin >> val[i];
    for(int i = 0, x, y; i < m; i++)
        cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);

    for(int i = 1; i <= n; i++)
        for(auto v : adj[i]) cost[i] += val[v];

    for(int i = 0; i < n; i++){
        int mincost = -1, mini;
        for(int i = 1; i <= n; i++)
            if(mincost < val[i]) mincost = val[i], mini = i;
        
        for(auto v : adj[mini])
            cost[v] -= val[mini];
        val[mini] = -2;
        ans += cost[mini];
    }

    cout << ans << endl;
}
