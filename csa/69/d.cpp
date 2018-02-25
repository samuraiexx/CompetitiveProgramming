#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5 + 1;
vector<int> adj[N];

int dist1[N];
int dist2[N];
set<pair<int, int>> s1, s2;

int md1, md2;
int d1, d2;

void dfs1(int n, int f, int dist, int &md, int &d){
  if(d < dist) d = dist, md = n;
  for(auto a : adj[n])
    if(a != f) dfs1(a, n, dist + 1, md, d);
}

void dfs2(int n, int dist, int vis[]){
  if(!vis[n]) vis[n] = dist;
  else return;

  for(auto a : adj[n])
    dfs2(a, dist + 1, vis);
}

int main(){
  int n;
  cin >> n;
  for(int i = 0, a, b; i < n - 1; i++)
    cin >> a >> b, adj[a].pb(b), adj[b].pb(a);

  dfs1(1, -1, 0, md1, d1);
  dfs1(md1, -1, 0, md2, d2);
  dfs2(md1, 0, dist1);
  dfs2(md2, 0, dist2);

  set<int> leaf;
  for(int i = 1; i <= n; i++)
    if(adj[i].size() == 1) leaf.insert(i);

  for(auto i : leaf)
    if(dist1[i] > dist2[i]) s1.insert({dist1[i], i});
    else if(dist1[i] == dist2[i]) continue;
    else s2.insert({dist2[i], i});

  for(auto i : leaf)
    if(dist1[i] == dist2[i])
      if(s1.size() > s2.size()) s2.insert({dist2[i], i});
      else s1.insert({dist1[i], i});

  cout << (leaf.size() + 1)/2 << endl;

  if(leaf.size()%2)
    if(s1.size() > s2.size() or 
       s1.size() == s2.size() and s1.begin()->first < s2.begin()->first)
      cout << s1.begin()->second << ' ' << md1 << endl, s1.erase(s1.begin());
    else
      cout << s2.begin()->second << ' ' << md2 << endl, s2.erase(s2.begin());

  while(s1.size() > s2.size()){
    cout << s1.begin()->second << ' ' << s1.rbegin()->second << endl;
    s1.erase(s1.begin());
    s1.erase(--s1.end());
  }
  while(s2.size() > s1.size()){
    cout << s2.begin()->second << ' ' << s2.rbegin()->second << endl;
    s2.erase(s2.begin());
    s2.erase(--s2.end());
  }
  while(s1.size()){
    cout << s1.begin()->second << ' ' << s2.begin()->second << endl;
    s1.erase(s1.begin());
    s2.erase(s2.begin());
  }
}
