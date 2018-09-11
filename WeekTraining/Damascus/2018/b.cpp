#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e3 + 5;
map<pair<int, int>, int> id;
int idcnt;
ull a[N];
ull pot[N];
ull p = 17;

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  pot[0] = 1;
  for(int i = 1; i < N; i++)
    pot[i] = 17*pot[i - 1];

  int t;
  cin >> t;
  while(t--){
    id.clear(); idcnt = 0;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
      int u, v;
      cin >> u >> v;
      if(u > v) swap(u, v);

      if(!id.count({u, v})) id[{u, v}] = idcnt++;
      a[i] = id[{u, v}];
    }

    map<ull, ll> eq;
    for(int i = 0; i < n; i++){
      ull hs = 0;
      for(int j = i; j < n; j++){
        hs += pot[a[j]];
        eq[hs]++;
      }
    }

    ll ans = 0;
    for(auto p : eq)
      ans += p.nd*(p.nd - 1)/2;

    cout << ans << '\n';
  }
}
