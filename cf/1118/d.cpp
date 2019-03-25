#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 2e5 + 5;
ll v[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;

  for(ll i = 0; i < n; i++)
    cin >> v[i];
  sort(v, v + n, greater<ll>());

  ll i = 1, j = n + 1;
  while(i != j){
    ll mid = (i + j)/2;

    ll mx = 0;
    for(ll i = 0; i < n; i++){
      mx += v[i] - i/mid;
      if(mx >= m) break;
    }
    
    if(mx >= m) j = mid;
    else i = mid + 1;
  }

  if(i == n + 1) return cout << -1 << endl, 0;
  else cout << i << endl;
}
