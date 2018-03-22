#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 2e9 + 5;
vector<ll> tt;
vector<ll> m2, m3;

int main(){
  ll l, r;
  cin >> l >> r;

  ll a = 1, b = 1;
  while(a < N) m2.pb(a), a *= 2;
  while(b < N) m3.pb(b), b*=3;

  for(auto x : m2)
    for(auto y : m3)
      tt.pb(x*y);

  sort(tt.begin(), tt.end());

  cout << (upper_bound(tt.begin(), tt.end(), r) - lower_bound(tt.begin(), tt.end(), l)) << endl;
}
