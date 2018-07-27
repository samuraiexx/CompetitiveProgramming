#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int MOD = 1e9 + 7;
const int N = 2e3 + 5;

int par[N], sz[N];

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite(int a, int b) {
  if ((a = find(a)) == (b = find(b))) return;
  if (sz[a] < sz[b]) swap(a, b);
  par[b] = a; sz[a] += sz[b];
}

int lc[N], rc[N];

int cnt;
int lb1[N], lb2[N];

void dfs1(int n){
  if(n == 0) return;
  lb1[cnt++] = n;
  dfs1(lc[n]);
  dfs1(rc[n]);
}

void dfs2(int n){
  if(n == 0) return;
  dfs1(lc[n]);
  dfs1(rc[n]);
  lb2[cnt++] = n;
}

int main(){
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++)
      cin >> lc[i] >> rc[i], par[i] = i, sz[i] = 1;

    dfs1(1);
    cnt = 0, dfs2(1);

    for(int i = 0; i < cnt; i++)
      if(lb1[i] != 0 and lb2[i] != 0)
        unite(lb1[i], lb2[i]);

    map<int, int> diff;
    int cnt = 1;
    for(int i = 1; i <= n; i++){
      int x = find(i);
      if(!diff.count(x))
        if(cnt <= k)
          diff[x] = cnt++;
        else 
          diff[x] = cnt;
    }

    cout << "Case #" << t << ": ";
    if(diff.size() < k){ cout << "Impossible" << endl; continue;}
    for(int i = 1; i <= n; i++)
      cout << diff[find(i)] << ' ';
    cout << endl;

  }
}
