#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

vector<ll> sum(ll x){
  vector<ll> s;
  if(x == 0) return s;
  ll i = 64 - __builtin_clzll(x) - 1;
  if(x >= (1ll << i + 1) - 1) i++;
  s.pb(i);
  //db(x _ "before");
  x -= (1ll << i) - 1;
  //db(x _ "after");
  auto v = sum(x);
  for(auto a : v) s.pb(a);
}

int main(){
  vector<ll> ans;
  ll x, d;
  cin >> x >> d;
  auto v = sum(x);
  ll j = 1;
  for(auto x : v){
    for(int i = 0; i < x; i++)
      ans.pb(j);
    j += d + 1;
  }

  cout << ans.size() << endl;
  for(auto x : ans)
    cout << x << ' ';
  cout << endl;
}
