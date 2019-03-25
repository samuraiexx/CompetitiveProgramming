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

typedef pair<ll, ll> pii;
typedef pair<ll, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

typedef ll type;

const ll INF = 0x3f3f3f3f, MOD = 1e9+7, N = 2e5+5;
const long double EPS = 1e-9;

bool ge(type x, type y) { return x + EPS > y; }
bool le(type x, type y) { return x - EPS < y; }
bool eq(type x, type y) { return ge(x, y) and le(x, y); }


int n, m, k;
int cont;

struct point {
    ll x, y;

    point(){ x = 0; y = 0; }
    point(ll x1, ll y1){ x = x1; y = y1; }
    point(const point &p){ x = p.x; y = p.y;}
    ll operator*(point b){ return x*b.x + y*b.y; }
    ll operator^(point b){ return x*b.y - y*b.x; }
    point operator-(point b){ return point(x - b.x, y - b.y); }
    point operator+(point b){ return point(x + b.x, y + b.y); }

    type operator %(point p) {return x*p.y - y*p.x; }
    const bool operator<(point b)const{ return x != b.x ? x < b.x : y < b.y; }
    double operator~(){ return hypot(x, y); }

};
vector<point> points;

ll double_of_triangle_area(point p1, point p2, point p3) {
    return abs((p2-p1)%(p3-p1));
}

bool point_inside_triangle(point p, point p1, point p2, point p3) {
    ll a1, a2, a3, a;
    a = double_of_triangle_area(p1, p2, p3);
    a1 = double_of_triangle_area(p, p2, p3);
    a2 = double_of_triangle_area(p1, p, p3);
    a3 = double_of_triangle_area(p1, p2, p);

    return a == a1 + a2 + a3;
}

bool point_inside_convex_poly(int l, int r, vector<point>& v, point p) {
    ll p1 = (p - points[0]) % (points[1] - points[0]);
    ll p2 = (p - points[0]) % (points[n-1] - points[0]);
    if(p1 > 0 or p2 < 0) return false;

    while(l < r) {
        int m = (l+r+1)/2;
        point a = points[m];
        ll prod = (p-points[0])%(a-points[0]);
        if(prod < 0) l = m;
        else r = m-1;
    }

    return point_inside_triangle(p, v[0], v[l], v[l+1]);
}

int main() {
    scanf("%d%d%d", &n, &m, &k);

    for(int i=0; i<n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        points.push_back(point((ll)a, (ll)b));
    }
    points.pb(points[0]);
    for(int i=0; i<m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        point p = {(ll) a, (ll)b};

        if(point_inside_convex_poly(1, n-2, points, p)) cont++;
    }


    printf("%s\n", cont >= k?"YES":"NO");

    return 0;
}
