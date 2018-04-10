#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 1e5 + 5;
ll v[N], mn[N];

int main(){
  ll n;
  ll ans = 0;
  cin >> n;
  for(ll i = 0; i < n; i++) cin >> v[i];

  for(ll i = 0; i < n; i++) mn[i] = v[i] + 1;
  for(ll i = 1; i < n; i++) mn[i] = max(mn[i - 1], mn[i]);
  for(ll i = n - 2; i >= 0; i--) mn[i] = max(mn[i], mn[i + 1] - 1);
  for(ll i = 0; i < n; i++) ans +=  mn[i] - v[i] - 1;

  cout << ans << endl;
}
