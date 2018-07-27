#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
typedef long double ld;
const ll N = 105;

struct point{
  ll x, y;
  
  point(){}
  point(ll x, ll y):x(x), y(y){}
  point operator-(point p) { return point(x - p.x, y - p.y); }
  ll operator%(point p) { return x*p.y - y*p.x; }
  ll operator!(){return x*x + y*y; }
  bool operator<(point p){ return y == p.y ? x < p.x : y < p.y; }
  //point operator=(point p){ x = p.x, y = p.y; return *this; }

  ld dist(point p1, point p2){
    return abs((p2 - p1)%(*this - p1))/(ld)sqrt(!(p2 - p1));
  }
} origin;

bool cmp(point p1, point p2){
  ll cp = (p1 - origin)%(p2 - origin);
  if(cp == 0) return !(p1 - origin) < !(p2 - origin);
  return cp > 0;
}

int main(){
  ll n;
  cin >> n;
  vector<point> pnts(n);

  for(ll i = 0; i < n; i++)
    cin >> pnts[i].x >> pnts[i].y;

  ll sz = 0;
  vector<point> ch;
  ch.resize(n);
  origin = *min_element(pnts.begin(), pnts.end());
  ch[sz++] = origin;

  sort(pnts.begin(), pnts.end(), cmp);
  for(auto p : pnts){
    while(sz > 1 and (ch[sz - 1] - ch[sz - 2])%(p - ch[sz - 2]) <= 0) sz--;
    ch[sz++] = p;
  }
  ch.resize(sz);

  ld ans = 0;
  for(ll i = 0; i < ch.size(); i++){
    ld mx = 0;
    for(ll j = 0; j < ch.size(); j++)
      mx = max(mx, ch[j].dist(ch[i], ch[(i + 1)%ch.size()]));
         //db(i _ j _ ch[j].x _ ch[j].y  _ ch[j].dist(ch[i], ch[i + 1]));
    if(ans) ans = min(ans, mx);
    else ans = mx;
  }

  printf("%.12Lf\n", ans);
}
