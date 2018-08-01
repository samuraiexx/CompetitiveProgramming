#include<bits/stdc++.h>
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

using namespace std;
const int N = 1e5 + 5;
int c[N];
vector<int> adj[N];

int cnt;
int euler[N];
int sz[N];
pair<int, int> bg[N];

int amt[N];
int dom;
ll ans[N];
ll sum[N];

int dfs(int n, int f){
  euler[cnt] = c[n];
  bg[n].st = cnt++;
  sz[n] = 1;

  for(auto x : adj[n]) if(x != f)
    sz[n] += dfs(x, n);

  bg[n].nd = cnt - 1;
  return sz[n];
}

void add(int col){
  sum[amt[col]] -= col;
  amt[col]++;
  sum[amt[col]] += col;
  if(amt[col] > dom) dom++;
}

void rem(int col){
  sum[amt[col]] -= col;
  amt[col]--;
  sum[amt[col]] += col;
  if(sum[dom] == 0) dom--;
}

void smallToLarge(int n, int f, bool keep){
  int mx = -1, big;
  for(auto x : adj[n]) if(x != f)
    if(sz[x] > mx) mx = sz[x], big = x;

  for(auto x : adj[n]) if(x != f and x != big)
    smallToLarge(x, n, false);

  if(mx != -1) smallToLarge(big, n, true);

  add(c[n]);

  for(auto x : adj[n]) if(x != f and x != big)
    for(int i = bg[x].st; i <= bg[x].nd; i++)
      add(euler[i]);

  ans[n] = sum[dom];

  if(!keep)
    for(int i = bg[n].st; i <= bg[n].nd; i++)
      rem(euler[i]);
}

int main(){
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> c[i];

  for(int i = 1; i < n; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1, -1);
  smallToLarge(1, -1, 0);

  for(int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
  cout << endl;
}
