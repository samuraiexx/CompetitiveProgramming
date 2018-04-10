#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 1e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct Ap{
  ll x, v;
  const bool operator<(const Ap b)const{
    return abs(x*b.v) < abs(b.x*v);
  }
  const bool operator==(const Ap b)const{
    return abs(x*b.v) == abs(b.x*v);
  }

  const bool operator!=(const Ap b) const{
    return x != b.x or v != b.v;
  }
};

vector<Ap> pos, neg;

ll func(Ap a, Ap b){
  ll den = b.x*a.v - a.x*b.v;
  ll div = a.x - b.x;
  if(div == 0)
    if(den != 0) return INF;
    else return 0;

  ll ans = (abs(den) + abs(div) - 1)/abs(div);
  if(den*div > 0) return ans;
  else return -ans;
}

int main(){
  ll n, w;
  ll ans = 0;
  cin >> n >> w;
  map<Ap, int> pose, nege;
  for(ll i = 0; i < n; i++){
    ll x, v;
    cin >> x >> v;
    pos.pb({x, v});
  }
  sort(pos.begin(), pos.end());

  /*
  for(auto a : pos)
    for(auto b : neg)
      cout << a.x << ' ' << a.v << " - " << b.x << ' ' << b.v << " = " <<  func(a, b) << endl;
      */

  for(auto a : pos){
    /*
    ll i = 0, j = pos.size();
    while(i != j){
      ll mid = (i + j)/2;
      if(a == pos[mid]) j = mid;
      else if(abs(func(a, pos[mid])) < w) j = mid;
      else i = mid + 1;
    }

    ll g = i;

    i = 0, j = pos.size();
    while(i != j){
      ll mid = (i + j)/2;
      if(abs(func(a, pos[mid])) <= w) j = mid;
      else i = mid + 1;
      //db(func(a, pos[mid]) _ mid);
    }
    ans += g - i;
    */

    for(auto b : pos) if(abs(func(a, b)) <= w) ans++;
    ans -= 1;

    //db(a.x _ a.v _ g _ i);
  }

  cout << ans/2 << endl;
}
