#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e4 + 5;
vector<pair<int, int>> adj[N];
int g[N];
int ans;

int n, c;

int dfs(int n, int f){
  for(auto p : adj[n]) if(p.st != f){
    int gch = dfs(p.st, n);
    ans += (gch + c - 1)/c*p.nd*2;
    g[n] += gch;
  }

  return g[n];
}

int main(){
  cin >> n >> c;
  for(int i = 1; i <= n; i++)
    cin >> g[i];

  for(int i = 1; i < n; i++){
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }

  dfs(1, -1);
  cout << ans << endl;
}
