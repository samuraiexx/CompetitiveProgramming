#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 1e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll n, m, k;
ll a, b, d;

void euclid(ll a, ll b, ll &x, ll &y, ll &d) {
  if (b) euclid(b, a%b, y, x, d), y -= x*(a/b);
  else x = 1, y = 0, d = a;
}

ll tim(ll x, ll y){
  if(abs(x - y)%d != 0) return INF;

  ll t = a;

  t = t*(y - x)*n/d;
  t = (t%(m*n/d) + m*n/d)%(m*n/d);

  return t + x;
}

int main(){
  cin >> n >> m >> k;

  n*=2, m*=2;
  euclid(n, m, a, b, d);

  for(ll i = 0; i < k; i++){
    ll x, y;
    cin >> x >> y;

    ll ans = min({tim(x, y), tim(n - x, y),
                   tim(n - x, m - y), tim(x, m - y)});

    if(ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
  }
}
