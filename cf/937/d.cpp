#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
const int N = 2e5 + 5;
vector<int> adj[N];
int vis[N];

set<int> evc, odc;
set<int> ede, edo;
bool ok;

string &dfs3(int n, int f){
  if(edo.count(n)) return to_string(n);
  for(auto a : adj[n]) if(a != f){
    string s = dfs3(a, n);
    if(s.size()) {
    return s + to_string(n);
    }
  }
  return "";
}

void dfs2(int n, int f, bool oc){
  if(odc.count(n)) oc = 1;

  if(adj[n].empty() and oc) ok = 1;
  for(auto a : adj[n]) if(a != f)
    dfs2(a, n, oc);
}

pair<set<int>, set<int>> dfs(int n, int f, int p){
  set<int> r1, r2;
  if(vis[n]) {
    if(p == vis[n]) r1.insert(n);
    else r2.insert(n);
    return make_pair(r1, r2);
  }

  vis[n] = p;
  if(adj[n].empty())
    if(p == 3) edo.insert(n);
    else ede.insert(n);
  for(auto a : adj[n])if(a != f){
    auto p = dfs(a, n, p^1);
    r1.insert(p.st.begin(), p.st.end());
    r2.insert(p.nd.begin(), p.nd.end());
  }
  if(r1.st() > 0) evc.insert(n);
  if(r1.nd() > 0) odc.insert(n);
  r1.erase(n), r2.erase(n);
  return make_pair(r1, r2);
}



int main(){
  int n, m, s;
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    int c;
    cin >> c;
    if(c == 0) eds.insert(i);
    for(int i = 0; i < c; i++)
      cin >> a, adj[i].pb(a);
  }
  cin >> s;

  dfs(s, -1, 3);
  dfs2(s, -1, 0);

  if(!edo.size() and !ok and odc.empty() and evc.empty())
    return cout << "Lose" << endl;
  if(edo.size()){
    cout << dfs3(s, -1);
  }
}
