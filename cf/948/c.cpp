#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 1e5 + 5;
ll v[N], t[N];
ll d[N];
ll d2[N];
vector<ll> d3[N];

ll ps[N];
ll pn[N];

int main(){
  ll n;
  cin >> n;
  for(ll i = 1; i <= n; i++) cin >> v[i];
  for(ll i = 1; i <= n; i++) cin >> t[i], t[i] += t[i - 1];

  for(ll i = 1; i <= n; i++){
    ll l = i, r = n + 1;
    while(l != r){
      ll mid = (l + r)/2;
      if(t[mid] - t[i - 1] < v[i])
        l = mid + 1;
      else r = mid;
    }
    d[i] = r;
    d2[r]++;
    d3[r].pb(i);
  }

  for(ll i = 1; i <= n; i++)
    ps[i] += v[i], ps[d[i]] -= v[i];

  for(ll i = 1; i <= n; i++)
    ps[i] += ps[i - 1];

  for(ll i = 1; i <= n; i++)
    d2[i] += d2[i - 1];
    
  for(ll i = 1; i <= n; i++){
    ll sum = (i - d2[i])*(t[i] - t[i - 1]);
    for(auto x : d3[i])
      sum += v[x] - (t[i - 1] - t[x - 1]);
    cout << sum << ' ';
  }
  cout << endl;
}
