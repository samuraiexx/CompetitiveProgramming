#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n, q;
int ps[N];
bool ans[N];

template<class T>
T clamp(T v, T mn, T mx){
  v = min(v, mx);
  v = max(v, mn);
  return v;
}

struct Point{
  ll x, y;
  int i;
  Point(ll x = 0, ll y = 0): x(x), y(y) {}
  ll operator%(Point p)const{ return x*p.y - y*p.x; }
  Point operator+(Point p)const{ return Point(x + p.x, y + p.y); }
  Point operator-(Point p)const{ return Point(x - p.x, y - p.y); }
  Point operator-()const{ return Point(-x, -y); }
  ll operator!()const{ return x*x + y*y; }
  void toFirst(){ 
    if(y < 0 or y == 0 and x < 0)
      x *= -1, y *= -1;
  }

  bool operator<(Point p) const { return *this%p > 0; }
} pnt[N], qry[N];

void ch(){
  vector<Point> ch(n);

  int mn = 0;
  for(int i = 1; i < n; i++)
    if(pnt[i].x < pnt[mn].x or pnt[i].x == pnt[mn].x and pnt[i].y < pnt[mn].y)
      mn = i;

  int sz = 0;

  for(int j = 0; j < n; j++){
    int i = (j + mn)%n;

    auto p = pnt[i];

    while(n > 1 and (ch[sz - 1] - ch[sz - 2])%(p - ch[sz - 2]) < 0){
      Point lp = clamp(ch[sz - 1] - ch[sz - 2], Point(-INF, 1), Point(1, 0));
      Point rp = clamp(p - ch[sz - 2], Point(-INF, 1), Point(1, 0));

      int l = upper_bound(qry, qry + q, lp) - qry;
      int r = lower_bound(qry, qry + q, rp) - qry - 1;
      db(l _ r);

      if(l <= r) ps[l]++, ps[r + 1]--; // [l, r]
      else ps[0]++, ps[l + 1]--, ps[r]++;

      lp = clamp(-(ch[sz - 1] - ch[sz - 2]), Point(-INF, 1), Point(1, 0));
      rp = clamp(-(p - ch[sz - 2]), Point(-INF, 1), Point(1, 0));

      l = upper_bound(qry, qry + q, lp) - qry;
      r = lower_bound(qry, qry + q, rp) - qry - 1;
      db(lp.x _ lp.y);
      db(l _ r);

      if(l <= r) ps[l]++, ps[r + 1]--; // [l, r]
      else ps[0]++, ps[l + 1]--, ps[r]++;

      sz--;
    }

    ch[sz++] = p;
  }
}

int main(){
  cin >> n >> q;

  for(int i = 0; i < n; i++)
    cin >> pnt[i].x >> pnt[i].y;

  for(int i = 0; i < q; i++){
    cin >> qry[i].y >> qry[i].x;
    qry[i].x = -qry[i].x;
    qry[i].i = i;

    qry[i].toFirst();
  }

  sort(qry, qry + q);
  ch();

  for(int i = 0; i < q; i++){
    db(i _ qry[i].x _ qry[i].y);
    if(i > 0)
      ps[i] += ps[i - 1];

    ans[qry[i].i] = !ps[i];
  }

  for(int i = 0; i < q; i++)
    cout << (ans[i] ? "Y" : "N") << '\n';
}
