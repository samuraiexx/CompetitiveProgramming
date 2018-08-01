#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ",  " << 

using namespace std;

const int N = 4e5+1, SQ = 450;
const int INF = 0x3f3f3f3f;

vector<int> g[N];

int mn[N], nxt[N];
int bit[N];
int ans[N];

void add(int p) { 
  for(;p < N; p += p&-p)
    bit[p]++;
}
void rem(int p) { 
  for(;p < N; p += p&-p)
    bit[p]--;
}

int get(int p){
  int ans = 0;
  for(;p > 0; p -= p&-p)
    ans += bit[p];
  return ans;
}

struct query { int i, l, r, ans; } qs[N];

bool c1(query a, query b) {
  if(a.l/SQ != b.l/SQ) return a.l < b.l; 
  else if((a.l/SQ)&1) return a.r > b.r;
  else return a.r < b.r;
}

bool c2(query a, query b) { return a.i < b.i; }

void dfs(int u, int r) {
  if (mn[u]) return;
  mn[u] = r;
  for(int v : g[u]) dfs(v, r);
}

int main(){
  int n, q;
  cin >> n >> q;
  for(int i = 1; i <= n; i++)
    cin >> nxt[i], g[nxt[i]].push_back(i);

  for(int i = 1; i <= n; i++)
    dfs(i, i);

  for(int i = 0; i < q; i++){
    int l, r;
    cin >> l >> r;
    qs[i] = { i, l, r, 0};
  }

  int l = 1, r = 0;
  sort(qs, qs+q, c1);
  for (int k = 0; k < q; ++k) {
    query &q = qs[k];
    while (r < q.r) r++, add(mn[r]);
    while (l > q.l) l--, add(mn[l]);
    while (r > q.r) rem(mn[r]), r--;
    while (l < q.l) rem(mn[l]), l++;

    int i = 1, j = n;
    while(i != j){
      int mid = (i + j + 1)/2;
      int x = get(mid);

      if(2*x <= r - l + 1) i = mid;
      else j = mid - 1;
    }

    int val = get(i);


    i = 1, j = n;
    while(i != j){
      int mid = (i + j)/2;
      int x = get(mid);

      if(2*x < r - l + 1) i = mid + 1;
      else j = mid;
    }

    int val2 = get(i);

    if((r - l + 1) - val2 > val)
      val = val2;

    i = 1, j = n;
    while(i != j){
      int mid = (i + j)/2;
      int x = get(mid);

      if(x < val) i = mid + 1;
      else j = mid;
    }

    ans[q.i] = i;

  }

  for(int i = 0; i < q; i++)
    cout << ans[i] << '\n';
}
