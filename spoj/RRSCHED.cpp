#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 5e4 + 5;
pair<ll, ll> reqPos[N];
ll bit[N];
ll ans[N];

ll query(ll l, ll r){
  ll ans = 0;
  for(ll i = r; i > 0; i -=i&-i)
    ans += bit[i];
  for(ll i = l - 1; i > 0; i-=i&-i)
    ans -= bit[i];
  return ans;
}

void add(ll pos, ll val){
  for(ll i = pos; i < N; i+=i&-i)
    bit[i] += val;
}

int main(){
  ll n;
  cin >> n;

  for(ll i = 1; i <= n; i++)
    cin >> reqPos[i].st, reqPos[i].nd = i;

  for(ll i = 1; i <= n; i++) add(i, 1);

  sort(reqPos + 1, reqPos + n + 1);

  ll t = 0;
  ll rounds = 0;

  for(ll i = 1; i <= n; i++){
    auto p = reqPos[i];

    t += query(1, n)*(p.first - rounds);
    rounds = p.first;
    ans[p.second] = t - query(1, n) + query(1, p.second);
    add(p.second, -1);
  }

  for(ll i = 1; i <= n; i++) cout << ans[i] << '\n';
}
