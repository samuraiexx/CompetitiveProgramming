#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
vector<int> adj[N];
int color[N];

int dfs(int n, int f){
    int t = 0;
    for(int i : adj[n])
        if(i != f){
            t += dfs(i, n);
        }
    if(color[n] != color[f]) t++;
    return t;
}

int main(){
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        adj[i].push_back(p), adj[p].push_back(i);
    }

    for(int i = 1; i <= n; i++) cin >> color[i];

    cout << dfs(1, 0) << endl;
}
