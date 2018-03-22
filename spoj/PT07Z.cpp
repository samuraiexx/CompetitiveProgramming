#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
vector<int> adj[N];

int md = 0;
int x;

void dfs(int n, int f, int d){
  if(d > md) md = d, x = n;
  for(auto a : adj[n])
    if(a != f) dfs(a, n,  d + 1);
}

int main(){
  int n;
  cin >> n;
  for(int i = 0, a, b; i < n - 1; i++)
    cin >> a >> b, adj[a].pb(b), adj[b].pb(a);

  dfs(1, -1, 0);
  dfs(x, -1, 0);

  cout << md << endl;
}
