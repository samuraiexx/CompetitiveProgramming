#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 

typedef long long ll;

const int N = 1e5+5;
const int INF = 0x3f3f3f3f;

ll f[N], n;
int t;

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a; }

void euclid(ll a, ll b, ll &x, ll &y, ll &d) {
  if(b) euclid(b, a%b, y, x, d), y -= x * (a/b);
  else x = 1, y = 0, d = a;
}

void normalize(ll &g2, ll &g1, ll a, ll b) {
  ll x = (g2-g1) * gcd(b,a);
  x /= (b-a);

  g1 += x * b / gcd(b,a);
  g2 -= x * a / gcd(b,a);
}

pair<ll, ll> get(ll a, ll b, ll term) { 
  ll g1 = 0, g2 = 0, g;
  if(term % g != 0) return {INF, INF};
  euclid(a, b, g1, g2, g);

  g1 *= N/g;
  g2 *= N/g;
  normalize(g2, g1, a, b);
  return {g1, g2};
}

int main(){
  scanf("%d", &t);
  f[1] = f[2] = 1;
  for(int i=3; i<100; i++) f[i] = f[i-1] + f[i-2];
  while(t--) {
    scanf("%lld", &n);
    pair<ll, ll> ans = {n/2, (n/2 + n&1)};
    for(ll i=2; i<100; i++) {
      pair<ll, ll> term = get(f[i], f[i-1], n);
      if(term.second < ans.second or (term.second == ans.second and term.first < ans.first)) ans = term;
    }
    printf("%lld %lld\n", ans.first, ans.second);
  }
}
