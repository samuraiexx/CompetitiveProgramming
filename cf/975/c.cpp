#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll mod = 1e9 + 9;
const ll N = 2e5 + 5;
ll v[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  ll n, q;
  cin >> n >> q;
  for(ll i = 0; i < n; i++)
    cin >> v[i];
  for(ll i = 1; i < n; i++)
    v[i] += v[i - 1];

  ll sum = 0;
  for(ll i = 0; i < q; i++){
    ll w;
    cin >> w;
    sum += w;

    ll amt = upper_bound(v, v + n, sum) - v + 1;
    if(amt <= n and v[amt - 1] != sum) amt--;
    if(amt >= n) sum = 0, amt = 0;
    cout << n - amt << '\n';
  }
}
