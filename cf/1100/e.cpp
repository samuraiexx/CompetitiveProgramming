#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];
vector<int> id[N];
int mx;

int t = 0;
int tv[N];
int vis[N];
int cnt[N];
int n, m;

bool dfs(int u){
  if(vis[u] == 1) return false;
  else if(vis[u] == 2) return true;
  bool ret = true;

  vis[u] = 1;
  for(auto v : adj[u]) if(v.nd > mx)
    ret &= dfs(v.st);
  
  vis[u] = 2;
  return ret;
}

bool test(){
  int ans = true;
  t = 0;
  memset(vis, 0, sizeof vis);
  for(int i = 1; i <= n; i++)
    ans &= dfs(i);

  return ans;
}

void test2(){
  vector<int> v;
  for(int i = 1; i <= n; i++)
    for(auto p : adj[i])
      if(p.nd > mx) cnt[p.st]++;

  stack<int> st;
  for(int i = 1; i <= n; i++)
    if(cnt[i] == 0) st.push(i);

  t = 0;
  while(st.size()){
    auto x = st.top();
    st.pop();
    v.pb(x);
    tv[x] = t++;
    for(auto p : adj[x]) if(p.nd > mx){
      cnt[p.st]--;
      if(!cnt[p.st]) st.push(p.st);
    }
  }
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  cin >> n >> m;

  for(int i = 1; i <= m; i++){
    int a, b, cs;
    cin >> a >> b >> cs;
    adj[a].pb({b, cs});
    id[a].pb(i);
  }

  int i = 0, j = 1e9 + 5;
  while(i != j){
    mx = (i + j)/2;

    if(!test()) i = mx + 1;
    else j = mx;
  }

  mx = i;
  test2();

  int ans = 0;
  for(int i = 1; i <= n; i++)
    for(auto p : adj[i])
      ans += p.nd <= mx && tv[p.st] < tv[i];

  cout << mx << ' ' << ans << '\n';

  for(int i = 1; i <= n; i++){
    for(int j = 0; j < adj[i].size(); j++){
      auto p = adj[i][j];
      if(p.nd <= mx && tv[p.st] < tv[i])
        cout << id[i][j] << ' ';
    }
  }

  if(ans > 0) cout << endl;
}
