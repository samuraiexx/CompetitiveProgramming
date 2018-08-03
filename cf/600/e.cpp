#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5+5, SQ = 450;

vector<int> adj[N];
int v[N];
int c[N];

int amt[N];
ll sum[N];

int dom;
int cnt;
int l = 0, r = -1;

void add(int p) {
  sum[amt[p]] -= p;
  amt[p]++;
  sum[amt[p]] += p;
  if(dom < amt[p]) 
    dom = amt[p];
}

void rem(int p) { 
  sum[amt[p]] -= p;
  amt[p]--;
  sum[amt[p]] += p;
  if(sum[dom] == 0) 
    dom--;
}

struct query { int i, l, r; ll ans; } qs[N];

bool c1(query a, query b) {
  if(a.l/SQ != b.l/SQ) return a.l < b.l;
  return a.l/SQ&1 ? a.r > b.r : a.r < b.r;
}

bool c2(query a, query b) { return a.i < b.i; }

void dfs(int n, int f){
  v[cnt] = c[n];
  qs[n - 1].l = cnt++;

  for(auto x : adj[n]) if(x != f)
    dfs(x, n);
  qs[n - 1].r = cnt - 1;
}

int main(){
  ios_base::sync_with_stdio(false), cin.tie(0);

  int n;
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> c[i], qs[i].i = i;

  for(int i = 1; i < n; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1, -1);

  sort(qs, qs+n, c1);
  for (int i = 0; i < n; ++i) {
    query &q = qs[i];
    while (r < q.r) add(v[++r]);
    while (l > q.l) add(v[--l]);
    while (r > q.r) rem(v[r--]);
    while (l < q.l) rem(v[l++]);


    q.ans = sum[dom];
  }

  sort(qs, qs+n, c2); // sort to original order

  for(int i = 0; i < n; i++)
    cout << qs[i].ans << ' ';
  cout << '\n';
}
