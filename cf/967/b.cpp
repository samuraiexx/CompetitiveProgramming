#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 1e5 + 5;
ll h[N];

int main(){
  ll n, a, b;
  cin >> n >> a >> b;

  ll fh, sum = 0;
  cin >> fh, sum += fh;
  n--;
  for(ll i = 0; i < n; i++)
    cin >> h[i], sum += h[i];

  sort(h, h + n, greater<ll>());

  ll ans = 0;
  for(ll i = 0; i < n; i++){
    if(a*fh/sum >= b) break;
    sum -= h[i], ans++;
  }
  cout << ans << endl;
}
