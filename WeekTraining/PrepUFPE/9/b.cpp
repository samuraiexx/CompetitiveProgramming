#include<bits/stdc++.h>
using namespace std;

map<pair<bool, int>, pair<int, pair<bool, int>>> adj[300000];

int main(){
    int n, m, f, s, t;
    priority_queue<pair<int, pair<bool, int>>> q;
    cin >> n >> m >> f >> s >> t;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a, 0].push_back({c, {0, b}});
        adj[a, 1].push_back({c, {1, b}});
        adj[b, 0].push_back({c, {0, a}});
        adj[b, 1].push_back({c, {1, a}});
    }



}
