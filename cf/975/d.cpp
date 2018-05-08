#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 2e5 + 5;
const ll INF = 0x3f3f3f3f;
ll n, a, b;

struct ghost{
  ll x;
  ll vx, vy;

  bool operator<(const ghost g)const{
    //return vx == g.vx ? vy < g.vy : vx < g.vx;
    ll c1 = a*vy - b*vx;
    ll c2 = a*g.vy - b*g.vx;

    if(c1 != c2) return c1 < c2;
    else return a*vx + b*vy < a*g.vx + b*g.vy;
  }
};

struct cmp{
  bool operator()(const ghost &g1, const ghost &g2){
    ll c1 = a*g1.vy - b*g1.vx;
    ll c2 = a*g2.vy - b*g2.vx;
    return c1 < c2;
  }
};

int main(){
  map<ghost, ll> st;
  map<ghost, ll, cmp> eq;

  cin >> n >> a >> b;
  b = a;
  a = 1;
  for(ll i = 0; i < n; i++){
    ghost g;
    cin >> g.x >> g.vx >> g.vy;
    st[g]++;
    eq[g]++;
  }

  ll ans = 0;
  for(auto p : st){
    ans += p.nd*(eq[p.st] - p.nd);
  }

  cout << ans << endl;
}
