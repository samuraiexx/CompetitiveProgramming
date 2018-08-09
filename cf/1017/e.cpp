#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
typedef double type;
const int N = 2e5 + 5;
const double EPS = 1e-9;

struct point{
  type x, y;

  point(type x = 0, type y = 0) : x(x), y(y) {}
  point operator -() { return point(-x, -y); }
  point operator +(point p) { return point(x+p.x, y+p.y); }
  point operator -(point p) { return point(x-p.x, y-p.y); }

  point operator *(type k) { return point(k*x, k*y); }
  point operator /(type k) { return point(x/k, y/k); }

  type operator *(point p) { return x*p.x + y*p.y; }
  type operator %(point p) { return x*p.y - y*p.x; }
  type operator !() {return (*this)*(*this); };
};

point origin;
bool radial(point a, point b) {
  double cp = (a - origin)%(b - origin);
  return abs(cp) < EPS ? !(a - origin) < !(b - origin) : cp > 0;
}

vector<point> e1, e2;

vector<point> convex_hull(vector<point> &pts) {
  vector<point> ch(pts.size());
  point mn = pts[0];

  for(point p : pts) if (p.y < mn.y or (p.y == mn.y and p.x < p.y)) mn = p;
  origin = mn;
  sort(pts.begin(), pts.end(), radial);

  int n = 0;

  for(point p : pts) {
    while (n > 1 and (ch[n - 1] - ch[n-2])%(p - ch[n - 2]) < EPS) n--;
    ch[n++] = p;
  }

  ch.resize(n);
  return ch;
}

vector<pair<double, double>> s, p;

inline bool operator!=(pair<double, double> p1, pair<double, double> p2){
  return abs(p1.st - p2.st) > EPS or abs(p1.nd - p2.nd) > EPS;
}

int b[N], n, m; // n = strlen(s), m = strlen(p);

void kmppre() {
  b[0] = -1;
  for (int i = 0, j = -1; i < m; b[++i] = ++j)
    while (j >= 0 and p[i] != p[j])
      j = b[j];
}

bool kmp() {
  for (int i = 0, j = 0; i < n;) {
    while (j >= 0 and s[i] != p[j]) j=b[j];
    i++, j++;
    if (j == m)
      return true;
  }
  return false;
}

int main(){
  cin >> n >> m;

  e1.resize(n), e2.resize(m);
  
  for(int i = 0; i < n; i++)
    cin >> e1[i].x >> e1[i].y;

  for(int i = 0; i < m; i++)
    cin >> e2[i].x >> e2[i].y;

  e1 = convex_hull(e1);
  e2 = convex_hull(e2);

  if(e1.size() != e2.size())
    return cout << "NO" << endl, 0;
  n = e1.size();

  point g1, g2;
  for(auto p : e1) g1 = g1 + p;
  for(auto p : e2) g2 = g2 + p;
  g1 = g1/n;
  g2 = g2/n;

  for(auto &p : e1) p = p - g1;
  for(auto &p : e2) p = p - g2;

  s.resize(2*n);
  p.resize(n);

  for(int i = 0; i < 2*n; i++){
    int k = i%n;
    int j = (i - 1 + n)%n;
    s[i] = {!e1[k], atan2(e1[j]%e1[k], e1[j]*e1[k])};
  }

  for(int i = 0; i < n; i++){
    int k = i%n;
    int j = (i - 1 + n)%n;
    p[i] = {!e2[k], atan2(e2[j]%e2[k], e2[j]*e2[k])};
  }

  m = p.size();
  n = s.size();

  kmppre();
  if(kmp()) cout << "YES" << endl;
  else cout << "NO" << endl;
}
