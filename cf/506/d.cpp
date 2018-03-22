#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;

map<int, vector<int>> adj[N];
map<int, vector<int>> vis[N];

int main(){
  int n, m;
  cin >> n >> m;

  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    adj[a][c].pb(b), adj[b][c].pb(a);
  }
}
