#include<bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5;
vector<int> adj[N];
int vis[N];
map<int, int> dn;
bool ok;
int b, c, a;

void dfs(int x, int t){
  if(vis[x] == (t^1)) ok = 0;
  if(vis[x]) return;
  vis[x] = t;
  for(auto y : adj[x])
    dfs(y, t^1);
}

bool expf(map<int, int>::iterator it, int amt, int sum){
  if(it == dn.end())
    if(sum == b or sum == c) return true;
    else return false;
  if(it->second == amt) return expf(++it, 0, sum);

  return expf(it, amt + 1, sum + it->first) or
         expf(it, amt + 1, sum);
}

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    dn.clear();
    map<int, int> dsu;
    cin >> b >> c >> a;
    int sz = b + c;

    for(int i = 1; i <= sz; i++) vis[i] = 0, adj[i].clear();

    for(int i = 0, x, y; i < a; i++)
      cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);

    ok = 1;
    for(int i = 1; i <= sz; i++) dfs(i, 2*i);
    if(!ok) { cout << "no" << endl; continue; }

    for(int i = 1; i <= sz; i++) dsu[vis[i]]++;

    for(int i = 1; i <= sz; i++){
      dn[abs(dsu[2*i] - dsu[2*i^1])]++;
      b -= min(dsu[2*i], dsu[2*i^1]);
      c -= min(dsu[2*i], dsu[2*i^1]);
    }

    dn.erase(0);

    if(b < 0 or c < 0) { cout << "no" << endl; continue; }

    for(auto &p : dn)
      if(p.second > 2) dn[p.first*2] += (p.second - 1)/2,
                       p.second  -= (p.second - 1)/2*2;

    if(expf(dn.begin(), 0, 0)) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}
