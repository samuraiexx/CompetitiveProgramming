#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;

int p[N];

vector<pair<long long, pair<int, int>>> adj[N][101];

int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> p[i];
    for(int j = 0; j < 100; j++)
      adj[i][j].push_back({p[i], {i, j + 1}});
  }

  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;

    for(int j = c; j <= 100; j++)
      adj[a][j].push_back({0, {b, j - c}}),
      adj[b][j].push_back({0, {a, j - c}});
  }

}
