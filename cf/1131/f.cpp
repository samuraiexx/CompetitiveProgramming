#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e5 + 5;

// Disjoint Set Union / Union-find
int par[N], sz[N];
pair<int, int> p[N];
pair<int, int> ans[N];

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite(int a, int b) {
  if ((a = find(a)) == (b = find(b))) return;
  if (sz[a] < sz[b]) swap(a, b);
  par[b] = a; sz[a] += sz[b];
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) par[i] = i, sz[i] = 1, p[i] = {i, i};
  for(int i = 0; i < n - 1; i++){
    int a, b;
    cin >> a >> b;
    a = find(a), b = find(b);
    pair<int, int> tmp = {p[a].st, p[b].nd};

    ans[p[a].nd].nd = p[b].st;
    ans[p[b].st].st = p[a].nd;

    unite(a, b);
    p[find(a)] = tmp;
  }

  int k;
  for(k = 1; k <= n; k++)
    if(!ans[k].st) break;

  while(k) cout << k << ' ', k = ans[k].nd;
  cout << endl;
}
