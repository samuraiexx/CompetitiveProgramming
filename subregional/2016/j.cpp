#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 1e5 + 5;
int n;

struct Point{
  ll x, y;
  Point(ll x = 0, ll y = 0):x(x), y(y) {}
  Point operator-(Point p){ return Point(x - p.x, y - p.y); }
  Point operator+(Point p){ return Point(x + p.x, y + p.y); }
  Point ccw(){ return Point(-y, x); }
  ll operator%(Point p){ return x*p.y - y*p.x; }
  ll operator*(Point p){ return x*p.x + y*p.y; }
  bool operator<(Point p) const { return x == p.x ? y < p.y : x < p.x; }
};

pair<vector<Point>, vector<Point>> ch(Point *v){
  vector<Point> hull, vecs;
  for(int i = 0; i < n; i++){
    if(hull.size() and hull.back().x == v[i].x) continue;

    while(vecs.size() and vecs.back()*(v[i] - hull.back()) <= 0)
      vecs.pop_back(), hull.pop_back();


    if(hull.size()){
      auto p = (v[i] - hull.back()).ccw();
      vecs.pb(p);
    }
    hull.pb(v[i]);
  }
  while(vecs.size() and vecs.back().x <= 0) hull.pop_back(), vecs.pop_back();
  return {hull, vecs};
}

int get(ll x) {
    Point query = {x, 1};
    auto it = lower_bound(vecs.begin(), vecs.end(), query, [](Point a, Point b) {
        return a%b > 0;
    });
    return query*hull[it - vecs.begin()];
}

int main(){
  ios_base::sync_with_stdio(false), cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> sk[i].y >> sk[i].x;
    cin >> tr[i].y >> tr[i].x;
    sk[i] = -sk[i];

    pnt[i].st = sk[i], pnt[i].nd = tr[i];
  }
  sort(tr, tr + n), sort(sk, sk + n);

  auto ch1 = ch(sk), ch2 = ch(tr);

  int ans = 0;
  for(int i = 0; i < n; i++){
    int x = lower_bound(ch1.st.begin(), ch1.st.end(), pnt[i].st) - ch1.st.begin();
    int y = lower_bound(ch2.st.begin(), ch2.st.end(), pnt[i].nd) - ch2.st.begin();

    if(ch1.st[x] != pnt[i].st or ch2.st[y] != pnt[i].nd) continue;

    if(x == 0 or y == 0)
      if(x == 0 and y == 0) ans++;
      else if(x == 0) ans += (ch1.nd.size() == x or ch1.nd[x]%ch2.nd[y - 1] < 0);
      else ans += (ch2.nd.size() == y or ch1.nd[x - 1]%ch2.nd[y] > 0);
    else if(ch1.nd[x - 1]%ch2.nd[y - 1] == 0) ans++;
    else if(ch1.nd[x - 1]%ch2.nd[y - 1] > 0)
      ans += (ch1.nd.size() == x or ch1.nd[x]%ch2.nd[y - 1] < 0);
    else if(ch1.nd[x - 1]%ch2.nd[y - 1] < 0) 
      ans += (ch2.nd.size() == y or ch1.nd[x - 1]%ch2.nd[y] > 0);
  }

  cout << ans << '\n';
}
