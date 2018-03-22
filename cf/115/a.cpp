#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

const int N = 2e3 + 5;
vector<int> adj[N];

int dfs(int n){
  int mx = 0;
  for(auto a : adj[n])
    mx = max(mx, dfs(a));
  return mx + 1;
}

int main(){
  int n;
  vector<int> bg;
  cin >> n;
  for(int i = 1, a; i <= n; i++){
    cin >> a;
    if(a == -1) bg.pb(i);
    else adj[a].pb(i);
  }

  int mx = 0;
  for(auto a : bg)
    mx = max(mx, dfs(a));

  cout << mx << endl;
}
