#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 1e5 + 5;
ll v[N], ps[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  ll n, k, m;
  cin >> n >> k >> m;
  for(ll i = 0; i < n; i++)
    cin >> v[i];

  sort(v, v + n);
  for(ll i = 0; i < n; i++)
    ps[i] = v[i] + (i > 0 ? ps[i - 1] : 0);

  double ans = 0;
  for(ll i = 0; i < n and i <= m; i++){
    ll bg = ps[n - 1] - (i > 0 ? ps[i - 1] : 0);
    double t = (bg + min((n - i)*k, m - i))/(double)(n - i);
    ans = max(ans, t);
  }

  cout << fixed << setprecision(12) << ans << endl;
}
