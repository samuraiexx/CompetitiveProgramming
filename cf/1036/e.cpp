#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e3 + 5;

typedef long double ld;
const double EPS = 1e-9, PI = acos(-1.);

// Change long double to long long if using integers
typedef long long type;

struct point {
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

pair<point, point> seg[N];

ostream &operator<<(ostream &os, const point &p) {
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}

point rotateCCW(point p, ld t) {
  return point(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}

point projectPointOnLine(point p, point a, point b) {
  return a + (b-a)*((p-a)*(b-a))/((b-a)*(b-a));
}

point projectPointSegment(point p, point a, point b) {
  ld r = (b-a)*(b-a);
  if(abs(r) < EPS) return a;
  r = ((p-a)*(b-a))/r;
  if(r < 0) return a;
  if(r > 1) return b;
  return a + (b-a)*r;
}

ld distPointSegment(point p, point a, point b) {
  return sqrt(!(projectPointSegment(p, a, b) - p));
}

// compute distance between point (x,y,z) and plane ax+by+cz=d
ld distPointPlane(ld x, ld y, ld z,
                      ld a, ld b, ld c, ld d) {
  return abs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}

bool linesColinear(point a, point b, point c, point d) {
  return abs((a-b)%(c-d)) < EPS and
         abs((a-b)%(a-c)) < EPS;
}

ll dir(ll x){
  if(x > 0) return 1;
  if(x < 0) return -1;
  return 0;
}

bool segmentIntersect(point a, point b, point c, point d) {
  if(linesColinear(a, b, c, d)) {
    if (!(a - c) == 0 or !(a - d) == 0 or
        !(b - c) == 0 or !(b - d) == 0) return true;
    if ((c-a)*(c-b) > 0 && (d-a)*(d-b) > 0 && (c-b)*(d-b) > 0)
      return false;
    return true;
  }

  if (dir(((d-a)%(b-a))) * dir(((c-a)%(b-a))) > 0) return false;
  if (dir(((a-c)%(d-c))) * dir(((b-c)%(d-c))) > 0) return false;
  return true;
}

bool lineIntersection(point a, point b, point c, point d) {
  b = b-a; d = c-d; c = c-a;
  if(b%d == 0) return true;
  return (b*(c%d)).x%(b%d) == 0 and 
         (b*(c%d)).y%(b%d) == 0;
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  ll ans = 0;
  for(int i = 0; i < n; i++){
    cin >> seg[i].st.x >> seg[i].st.y  >> seg[i].nd.x >> seg[i].nd.y;

    int dx = abs(seg[i].st.x - seg[i].nd.x);
    int dy = abs(seg[i].st.y - seg[i].nd.y);

    ans += __gcd(dx, dy) + 1;
  }

  int amt = 0;
  for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++)
      if(segmentIntersect(seg[i].st, seg[i].nd, seg[j].st, seg[j].nd))
        if(lineIntersection(seg[i].st, seg[i].nd, seg[j].st, seg[j].nd))
          amt++;

  db(ans _ amt);
  cout << ans - amt << endl;
}
