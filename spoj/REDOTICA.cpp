#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e2 + 5;

int par[N], sz[N];

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite(int a, int b) {
  if ((a = find(a)) == (b = find(b))) return;
  if (sz[a] < sz[b]) swap(a, b);
  par[b] = a; sz[a] += sz[b];
}

int main(){
  int n, m;
  int t = 1;
  while(cin >> n >> m, n or m){
    vector<tuple<int, int, int>> edgs;
    cout << "Teste " << t << endl;
    for(int i = 1; i <= n; i++)
      par[i] = i, sz[i] = 1;

    for(int i = 0; i < m; i++){
      int a, b, c;
      cin >> a >> b >> c;
      edgs.pb({c, a, b});
    }

    sort(edgs.begin(), edgs.end());

    for(auto edg : edgs){
      //cout << get<0>(edg) << ' ' << get<1>(edg) << ' ' << get<2>(edg) << endl;
      int a, b;
      tie(ignore, a, b) = edg;
      if(find(a) == find(b)) continue;
      if(a > b) swap(a, b);

      cout << a << ' ' << b << endl;
      unite(a, b);
    }

    t++;
  }
}
