#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << "==" << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e5+5;
const ld EPS = 1e-9;

typedef long long type;

bool ge(type x, type y) { return x + EPS > y; }
bool le(type x, type y) { return x - EPS < y; }
bool eq(type x, type y) { return ge(x,y) and le(x,y); }

struct point {
    type x, y;

    point(): x(0), y(0) {}
    point(type x, type y) : x(x), y(y) {}

    point operator -() { return point(-x, -y); }
    point operator +(point p) { return point(x+p.x, y+p.y); }
    point operator -(point p) { return point(x-p.x, y-p.y); }

    point operator *(type k) { return point(k*x, k*y); }

    type operator *(point p) { return x*p.x + y*p.y; }
    type operator %(point p) { return x*p.y - y*p.x; }

    int dir(point o, point p) {
        type x = (*this - o) % (p - o);
        return ge(x,0) - le(x,0);
    }

    bool on_seg(point p, point q) {
        if (this -> dir(p,q)) return 0;
        return ge(x, min(p.x, q.x)) and le(x, max(p.x, q.x)) and
               ge(y, min(p.y, q.y)) and le(y, max(p.y, q.y));
    }

    ld abs() { 
        ld xx = x, yy = y;
        return sqrt(xx*xx + yy*yy);
    }
};

point origin;

bool radial(point p, point q) {
    int dir = p.dir(origin, q);
    return dir > 0 or (!dir and p.on_seg(origin, q));
}
    
vector<point> convex_hull(vector<point> pts) {
    vector<point> ch;
    ch.resize(pts.size());
    point mn = pts[0];

    for(point p : pts) if (p.y < mn.y or (p.y == mn.y and p.x < p.y)) mn = p;

    origin = mn;

    sort(pts.begin(), pts.end(), radial);

    int sz = 0;

    for(point p : pts) {
        while(sz > 1 and ch[sz-1].dir(ch[sz-2], p) < 1) sz--;
        ch[sz++] = p;
    }

    ch.resize(sz);
    return ch;
}

int n;
map<pair<ll, ll>, int> ord;

int main() {
    scanf("%d", &n);
    vector<point> points;

    for(int i=0; i<n; i++) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        point p = point(x,y);
        points.pb(p);

        ord[mp(x,y)] = i;
    }

    vector<point> convexhull = convex_hull(points);

    printf("%d\n", (int) convexhull.size());
    for(point p : convexhull) {
        printf("%d ", ord[mp(p.x, p.y)] + 1);
    }
    printf("\n");

    ld per = 0;
    for(int i=0; i<convexhull.size(); i++) {
        ld dist = (convexhull[i] - convexhull[(i+1)%n]).abs();
        per = per + dist;
    }

    ll area = 0;
    for(int i=0; i<convexhull.size(); i++) {
        point p1 = convexhull[i], p2 = convexhull[(i+1)%n];
        area += p1.x * p2.y - p1.y*p2.x;
    }

    printf("%.12Lf\n", per);
    printf("%lld%s\n", area/2, area%2 ? ".5" : ".0");
}
