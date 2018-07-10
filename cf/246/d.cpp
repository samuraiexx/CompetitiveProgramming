#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

vector<int> adj[N];
set<int> diver[N];
int c[N];

int main(){
  int n, m;
  int mx = 0, col;

  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    cin >> c[i], col = min(col, c[i]);

  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i = 1; i <= n; i++)
    for(auto x : adj[i])
      if(c[i] != c[x])
        diver[c[i]].insert(c[x]);

  for(int i = 1; i < N; i++)
    if(diver[i].size() > mx)
      col = i, mx = diver[i].size();

  cout << col << endl;
}
