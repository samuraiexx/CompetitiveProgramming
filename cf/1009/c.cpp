#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  ll n, m;
  cin >> n >> m;

  ll ans = 0;
  for(ll i = 0; i < m; i++){
    ll x, d;
    cin >> x >> d;
    ll f;
    if(d < 0) f = n/2 - 1;
    else f = n - 1;

    ans += x*n;
    ans += (0 + d*f)*(f + 1)/2;

    f = n - f - 1;
    ans += (0 + d*f)*(f + 1)/2;
  }

  printf("%.12lf\n", ans/(double)n);
}
