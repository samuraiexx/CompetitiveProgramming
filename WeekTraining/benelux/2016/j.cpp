#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
const int N = 1e2 + 5;

pair<int, int> p[N], s[N];

int x, vis[N], b[N];
int l, r, mid;
vector<int> vdist;

vector<pair<int, int>> adj[N];

bool match(int u) {
  if (vis[u] == x) return 0;
  vis[u] = x;
  for (auto p : adj[u]){
    int v = p.nd;
    if(p.st <= vdist[mid])
      if (!b[v] or match(b[v])) return b[v]=u;
  }
  return 0;
}

int main(){
  int n;
  cin >> n;
  set<int> dists;
  for(int i = 1, x, y; i <= n; i++)
    cin >> x >> y, s[i] = make_pair(x, y);
  for(int i = 1, x, y; i <= n; i++)
    cin >> x >> y, p[i] = make_pair(x, y);

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      adj[i].pb({abs(s[i].st - p[i].st) + abs(s[i].nd - p[i].nd), j}),
      dists.insert(abs(s[i].st - p[i].st) + abs(s[i].nd - p[i].nd));

  for(auto a : dists) vdist.pb(a);

  l = 0, r = vdist.size() - 1;
  while(l != r){
    memset(vis, 0, sizeof vis);
    memset(b, 0, sizeof b);
    int ans = 0;
    mid = (l + r)/2;
    x = 0;
    for (int i = 1; i <= n; ++i) ++x, ans += match(i);
    if(ans == n) r = mid;
    else l = mid + 1;
  }
  cout << vdist[l] << endl;
}
