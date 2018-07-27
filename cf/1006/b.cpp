#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 2e3 + 5;
pair<ll, ll> v[N];

int main(){
  ll n, k;
  cin >> n >> k;
  for(ll i = 0; i < n; i++)
    cin >> v[i].st, v[i].nd = i;

  sort(v, v + n);
  ll ans = 0;
  vector<ll> ans2;

  for(ll i = n - 1, j = 0; j < k; j++, i--)
    ans += v[i].st, ans2.push_back(v[i].nd);

  sort(ans2.begin(), ans2.end());
  cout << ans << endl;

  ll prev = -1;
  for(ll i = 0; i < ans2.size(); i++){
    if(i == ans2.size() - 1) cout << n - prev - 1 << endl;
    else{
      ll x = ans2[i];
      cout << x - prev << ' ';
      prev = x;
    }
  }
}
