#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
const int N = 1e3 + 5;

struct point{
  int x, y;
  point(int x = 0, int y = 0):x(x), y(y){}
  point operator-(point p){ return point(x - p.x, y - p.y); }
  point operator+(point p){ return point(x + p.x, y + p.y); }
  point operator!(){ 
    int g = __gcd(abs(x), abs(y));
    point p = *this;
    p.x /= g, p.y /= g;
    if(p.y < 0) p.x *= -1, p.y *= -1;
    return p;
  }
  point operator*(int k) const { return point(x*k, y*k); }
  bool operator!= (point p) const { return x != p.x or y != p.y; }
  bool operator== (point p) const { return !(*this !=  p); }
  int dist(point p){ return abs(x - p.x) + abs(y - p.y); }
  bool operator<(point p) const { return x == p.x ? y < p.y : x < p.x; }
} pnt[N];

int rad[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> pnt[i].x >> pnt[i].y >> rad[i];

  map<point, vector<int>> type;

  for(int i = 1; i < n; i++){
    point norm = !(pnt[i] - pnt[0]);
    point p = (pnt[i] - pnt[0]);
    type[norm].pb(i);
  }

  if(type.size() == 1 and
     (type.begin()->st == point(1, 1) or
      type.begin()->st == point(-1, 1))){

    map<point, int> cnt;
    for(int i = 0; i < n; i++)
      cnt[pnt[i] + type.begin()->st*rad[i]]++;

    for(auto p : cnt)
      if(p.nd == n) return cout << "uncertain" << '\n', 0;
    cout << "impossible" << '\n';
  } else {
    int a, b;
    auto it = type.begin();
    a = it->nd.front();
    if(++it != type.end()) b = it->nd.front();
    else b = 0;

    vector<point> ans;
    for(int i = -rad[a]; i <= rad[a]; i++){
      point p1 = pnt[a] + point(i, rad[a] - i);
      point p2 = pnt[a] + point(i, i - rad[a]);
      if(pnt[b].dist(p1) == rad[b]) ans.pb(p1);
      if(pnt[b].dist(p2) == rad[b]) ans.pb(p2);
    }

    vector<point> ans2;
    for(auto p : ans){
      bool ok = true;
      for(int i = 0; i < n and ok; i++)
        if(pnt[i].dist(p) != rad[i])
          ok = false;

      if(ok) ans2.pb(p);
    }

    if(ans2.size() == 0) cout << "impossible\n";
    else if(ans2.size() > 1) cout << "uncertain\n";
    else cout << ans2.front().x << ' ' << ans2.front().y << '\n';
  }
}
