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
    ll dist(point p){ return (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y); }

};

point points[N];

pair<point, point> closest_pair_util(point p[], int n) {
    if (n <= 3) {
        point ans1 = p[0], ans2 = p[1];
        for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) {
            if(p[i].dist(p[j]) < ans1.dist(ans2)) {
                ans1 = p[i], ans2 = p[j];
            }
        }
        return {ans1, ans2};
    }

    int mid = n/2;
    point mp = p[mid];

    pair<point, point> pp1 = closest_pair_util(p, mid);
    pair<point, point> pp2 = closest_pair_util(p+mid, n-mid);

    pair<point, point> pp;
    if ( pp1.first.dist(pp1.second) < pp2.first.dist(pp2.second) ) pp = pp1;
    else pp = pp2;

    ll d = pp.first.dist(pp.second);

    point strip[n];
    int sz = 0;
    for(int i=0; i<n; i++) if((p[i].x - mp.x) * (p[i].x - mp.x) < d) strip[sz++] = p[i];

    sort(strip, strip+sz, [](point s, point t){ return s.y > t.y; });

    for(int i=0; i<sz; i++) for(int j = i+1; j < sz and (strip[i].y - strip[j].y) * (strip[i].y - strip[j].y) < d; j++) {
        if(strip[i].dist(strip[j]) < d) {
            pp = { strip[i], strip[j] };
            d = strip[i].dist(strip[j]);
        }
    }

    return pp;
}

pair<point, point> closest_pair(point p[], int n) {
    sort(p, p+n, [](point s, point t){ return s.x < t.x; });
    return closest_pair_util(p, n);
}

int main() {
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);

        points[i] = {a, b};
    }

    pair<point, point> ans = closest_pair(points, n);
    printf("%lld %lld\n%lld %lld\n", ans.first.x, ans.first.y, ans.second.x, ans.second.y);

    return 0;
}
