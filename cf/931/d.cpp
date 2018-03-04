#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " << 
const int N = 1e5 + 5;
vector<int> adj[N];

int main(){
  int n, ans = 0;
  cin >> n;
  for(int i = 2, a; i <= n; i++)
    cin >> a, adj[a].pb(i);

  queue<pair<int, int>> q;
  q.push({1, 0});
  int dist = 0;
  int amt = 0;
  
  while(q.size()){
    auto p = q.front();
    q.pop();
    //db(p.st _ p.nd _ ans _ amt);
    if(p.nd > dist)
      dist = p.nd, ans += amt%2, amt = 0;

    amt++;

    for(auto a : adj[p.st])
      q.push({a, p.nd + 1});
  }

  ans += amt%2;

  cout << ans << endl;
}
