#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e5 + 5;

vector<int> ch[N];
pair<int, int> se[N];
int v[N];
int cnt;

void dfs(int n){
  se[n].st = cnt;
  v[cnt++] = n;
  for(auto c : ch[n])
    dfs(c);

  se[n].nd = cnt - 1;
}

int main(){
  int n, q;
  cin >> n >> q;

  for(int i = 2; i <= n; i++){
    int s;
    cin >> s;
    ch[s].pb(i);
  }
  dfs(1);

  while(q--){
    int u, k;
    cin >> u >> k;
    k--;

    auto p = se[u];
    if(p.nd - p.st < k){
      cout << -1 << endl;
    } else {
      cout << v[p.st + k] << endl;
    }
  }
}
