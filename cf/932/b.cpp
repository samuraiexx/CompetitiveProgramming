#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
typedef long long ll;

const ll N = 2e6 + 2;
ll g[N];
ll ps[N][10];

ll prod(ll x){
  ll ans = 1;
  while(x){
    if(x%10) ans *= x%10;
    x /= 10;
  }
  return ans;
}

int main(){
  ll q;
  cin >> q;
  for(ll i = 0; i < 10; i++) g[i] = i;
  for(ll i = 10; i < N; i++) g[i] = g[prod(i)];
  for(ll i = 1; i < N; i++)
    ps[i][g[i]]++;
  for(ll i = 2; i < N; i++)
    for(ll j = 1; j < 10; j++)
      ps[i][j] += ps[i - 1][j];

  for(ll i = 0; i < q; i++){
    ll l, r, k;
    cin >> l >> r >> k;
    cout << ps[r][k] - ps[l - 1][k] << endl;
  }
}
