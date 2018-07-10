#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll INF = 1e10;
const ll N = 105;
ll v[N];

int main(){
  ll n, d;
  cin >> n >> d;
  for(ll i = 1; i <= n; i++)
    cin >> v[i];

  v[0] = -INF, v[n + 1] = INF;

  ll ans = 0;
  for(ll i = 1; i <= n; i++){
    ll ant = v[i] - v[i - 1];
    ll pos = v[i + 1] - v[i];
    ans += (ant >= 2*d) + (pos > 2*d);
  }
  cout << ans << endl;
}
