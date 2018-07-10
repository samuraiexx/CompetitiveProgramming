#include<bits/stdc++.h>
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
using namespace std;
const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];
vector<int> ans;

bool dfs(int n, int f, bool br){
  bool has = false;
  for(auto x : adj[n])
    if(x.st != f){
      has |= dfs(x.st, n, x.nd == 2);
    }

  if(br == true and has == false){
    ans.push_back(n);
    return true;
  }

  return has;
}

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n - 1; i++){
    int a, b, t;
    cin >> a >> b >> t;
    adj[a].push_back({b, t});
    adj[b].push_back({a, t});
  }

  dfs(1, 0, false);

  cout << ans.size() << endl;
  for(auto x : ans)
    cout << x << ' ';
  cout << endl;
}
