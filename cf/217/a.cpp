#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 105;

pair<int, int> pnts[N];

vector<int> adj[N];
int vis[N];

void dfs(int n){
  for(auto x : adj[n])
    if(!vis[x])
      vis[x] = true, dfs(x);
}

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> pnts[i].st >> pnts[i].nd;

  for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++)
      if(pnts[i].st == pnts[j].st or pnts[i].nd == pnts[j].nd)
       adj[i].pb(j), adj[j].pb(i); 

  int ans = 0;
  for(int i = 0; i < n; i++)
    if(!vis[i]) ans++, dfs(i);

  cout << ans - 1 << endl;
}
