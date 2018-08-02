#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e3 + 5;
const int M = N*N;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int a[N][N];
int id[N][N];
bool ans[N][N];
pair<int, pair<int, int>> v[M];

int par[M], sz[M];

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite(int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
      if (sz[a] < sz[b]) swap(a, b);
        par[b] = a; sz[a] += sz[b];
}

int amt;
void dfs(int x, int y, int idn){
  id[x][y] = find(id[x][y]);

  if(amt == 0 or id[x][y] != idn or ans[x][y]) return;
  ans[x][y] = true;
  amt--;

  for(int i = 0; i < 4; i++)
    dfs(x + dx[i], y + dy[i], idn);
}

int main(){
  ios_base::sync_with_stdio(false), cin.tie(0);

  for(int i = 1; i < M; i++)
    sz[i] = 1, par[i] = i;

  int n, m;
  ll k;
  cin >> n >> m >> k;

  int cnt = 0;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <=m; j++){
      cin >> a[i][j];
      v[cnt++] = {a[i][j], {i, j}};
    }

  sort(v, v + cnt, greater<pair<int, pair<int, int>>>());

  for(int i = 0; i < cnt; i++){
    ll h = v[i].st;
    auto pos = v[i].nd;
    id[pos.st][pos.nd] = i + 1;

    for(int j = 0; j < 4; j++){
      int nid = id[pos.st + dx[j]][pos.nd + dy[j]];
      if(nid) unite(nid, i + 1);
    }

    int idi = find(i + 1);

    if(k%h == 0 and k/h <= sz[idi]){
      amt = k/h;
      db(amt);
      dfs(pos.st, pos.nd, idi);

      cout << "YES" << '\n';
      for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
          if(ans[i][j])
            cout << h;
          else cout << 0;
          cout << ' ';
        }
        cout << '\n';
      }
      return 0;
    }
  }

  cout << "NO" << '\n';
}
