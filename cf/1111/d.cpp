#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 2e5 + 5;
const ll M = 300;
const ll mod = 1e9 + 7;
ll cnt[M];
ll fat[N], ifat[N];

string s;
ll n;
ll pi = 1;

ll fexp(ll a, ll b){
  ll ans = 1;
  while(b)
    if(b&1) ans = (a*ans)%mod, b--;
    else a = (a*a)%mod, b/=2;
  return ans;
}

ll inv(ll x){
  return fexp(x, mod - 2);
}

ll calc(ll amt, ll amt2 = 0){
  ll cont = (fat[amt]*fat[amt2])%mod;
  if(amt + amt2 > s.size()/2) return 0;

  ll ans = (((inv(pi)*cont)%mod)*fat[s.size() - amt - amt2])%mod;
  ll ans2 = ((((
           fat[s.size()/2]*
           ifat[amt])%mod)*
           ifat[amt2]%mod)*
           ifat[s.size()/2 - amt - amt2])%mod;

  return (((2*ans)%mod)*ans2)%mod;
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  fat[0] = ifat[0] = 1;
  for(ll i = 1; i < N; i++){
    fat[i] = (i*fat[i - 1])%mod;
    ifat[i] = (inv(i)*ifat[i - 1])%mod;
  }

  cin >> s >> n;
  for(auto c : s)
    cnt[c]++;

  for(ll i = 0; i < M; i++)
    pi = (pi * fat[cnt[i]])%mod;

  while(n--){
    ll x, y;
    cin >> x >> y;
    x--, y--;

    if(s[x] == s[y]){
      cout << calc(cnt[s[x]]) << '\n';
    } else {
      ll amt1 = cnt[s[x]], amt2 = cnt[s[y]];
      cout << calc(amt1, amt2) << '\n';
    }
  }
}
