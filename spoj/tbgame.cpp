#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const double EPS = 1e-9;

bool ge(ld x, ld y) { return x + EPS > y; }
bool le(ld x, ld y) { return x - EPS < y; }
bool eq(ld x, ld y) { return ge(x, y) and le(x, y); }

struct point {
  ld x, y;

  point() : x(0), y(0) {}
  point(ld x, ld y) : x(x), y(y) {}

  point operator -() { return point(-x, -y); }
  point operator +(point p) { return point(x+p.x, y+p.y); }
  point operator -(point p) { return point(x-p.x, y-p.y); }

  bool operator ==(point p) { return p.x == x && p.y == y; }
  point operator *(ld k) { return point(k*x, k*y); }
  point operator /(ld k) { return point(x/k, y/k); }

  ld operator *(point p) { return x*p.x + y*p.y; }
  ld operator %(point p) { return x*p.y - y*p.x; }

  // o is the origin, p is another point
  // dir == +1 => p is clockwise from this
  // dir ==  0 => p is colinear with this
  // dir == -1 => p is counterclockwise from this
  int dir(point o, point p) {
    ld x = (*this - o) % (p - o);
    return ge(x, 0) - le(x, 0);
  }

  bool on_seg(point p, point q) {
    if (this->dir(p, q)) return 0;
    return ge(x, min(p.x, q.x)) and le(x, max(p.x, q.x)) and
           ge(y, min(p.y, q.y)) and le(y, max(p.y, q.y));
  }

  ld abs() { return sqrt(x*x + y*y); }
  ld dist(point x) { return (*this - x).abs(); }

  point project(point y) { return y * ((*this * y) / (y * y)); }

  ld dist_line(point x, point y) {
    point t = *this-x;
    return dist(t.project(y-x) + x);
  }

  ld dist_seg(point x, point y) {
    return min(dist_line(x, y), min(dist(x), dist(y)));
  }

  point rotate(ld a) {
    return point(cos(a)*x-sin(a)*y, sin(a)*x+cos(a)*y);
  }

  point rotate(point p) { // rotate around the argument from vector p
    ld hyp = (p.x+p.y) * (p.x+p.y);
    ld c = p.x / hyp;
    ld s = p.y / hyp;
    return point(c*x-s*y, s*x+c*y);
  }
};


int direction(point o, point p, point q) { return p.dir(o, q); }

bool segments_intersect(point p, point q, point a, point b) {
  int d1, d2, d3, d4;
  d1 = direction(p, q, a);
  d2 = direction(p, q, b);
  d3 = direction(a, b, p);
  d4 = direction(a, b, q);
  if (d1*d2 < 0 and d3*d4 < 0) return 1;
  return p.on_seg(a, b) or q.on_seg(a, b) or
         a.on_seg(p, q) or b.on_seg(p, q);
}

// Sorting points in counterclockwise order.
// If the angle is the same, closer points to the origin come first.
point origin;
bool radial(point p, point q) {
  int dir = p.dir(origin, q);
  return dir > 0 or (!dir and p.on_seg(origin, q));
}

// Graham Scan
vector<point> convex_hull(vector<point> pts) {
  vector<point> c;
  c.resize(pts.size());

  point mn = pts[0];

  for(point p : pts)
    if (p.y < mn.y or (p.y == mn.y and p.x < p.y))
      mn = p;

  origin = mn;
  sort(pts.begin(), pts.end(), radial);

  int n = 0;
  for(point p : pts) {
    while (n > 1 and c[n-1].dir(c[n-2], p) < 1) n--;
    c[n++] = p;
  }

  c.resize(n);
  return c;
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int n;
		vector<point> pnt;
		vector<point> ch;
		cin >> n;
		pnt.resize(n);
		for(int i = 0; i < n; i++)
			cin >> pnt[i].x >> pnt[i].y;
		point t1 = pnt[0], s1 = pnt[1], t2 = pnt[2], s2 = pnt[3];
		ch = convex_hull(pnt);	
		int cnt = 0;
		for(int i = 0; i < n; i++)
			if(ch[i] == t1 || ch[i] == t2 || ch[i] == s1 || ch[i] == s2) cnt++;
		if(cnt == 4 && segments_intersect(t1, s1, t2, s2))
			cout << "IMPOSSIBLE\n";
		else
			cout << "POSSIBLE\n";
	}
	return 0;
}
