#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << "==" << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long double ll;
typedef long double ld;

typedef pair<ll, ll> pii;
typedef pair<ll, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

const ll INF = 0x3f3f3f3f, MOD = 1e9+7, N = 2e5+5;
long double EPS = 1e-9;


struct pnt {
    ll x, y;

    pnt(){ x = 0; y = 0; }
    pnt(ll x1, ll y1){ x = x1; y = y1; }
    pnt operator*(ld b){ return {x*b, y*b}; }
    pnt operator/(ld b){ return {x/b, y/b}; }
    ll operator*(pnt b){ return x*b.x + y*b.y; }
    ll operator%(pnt b){ return x*b.y - y*b.x; }
    pnt operator-(pnt b){ return pnt(x - b.x, y - b.y); }
    pnt operator+(pnt b){ return pnt(x + b.x, y + b.y); }
    const bool operator<(pnt b)const{ return x != b.x ? x < b.x : y < b.y; }
    double operator~(){ return hypot(x, y); }

    pnt rot(pnt base, ld sena, ld cosa) {
        pnt p2 = *this - base;
        pnt ans = {cosa*p2.x - sena * p2.y, sena*p2.x + cosa * p2.y};
        ans = base + ans;
        return ans;
    }
};

typedef pnt point;

point a, b, o;
ll r;

ld dist(point a, point b) {
    return ~(a-b);
}

ld dist_seg(point p, point a, point b) {
    if((p-a)*(b-a) > 0 and (p-b)*(a-b) > 0)
        return dist(p, a+(b-a)*((p-a)*(b-a))/((b-a)*(b-a)));
    return min(dist(p, a), dist(p, b));
}


int main() {

    {
        double x, y;
        scanf("%lf%lf", &x, &y);
        a = {x,y};
        scanf("%lf%lf", &x, &y);
        b = {x,y};
        scanf("%lf%lf", &x, &y);
        o = {x,y};
        scanf("%lf", &x);
        r = (ld) x;
    }

    if(dist_seg(o, a, b) >= r) {
        return printf("%lf\n", (double)~(a-b)), 0;
    }


    ld cosa = r/(~(a-o));
    ld sena = sqrt(1 - cosa*cosa);

    point r1 = (a-o)/~(a-o)*r + o;
    point ra1 = r1.rot(o, sena, cosa);
    point ra2 = r1.rot(o, -sena, cosa);

    ld cosb = r/(~(b-o));
    ld senb = sqrt(1 - cosb*cosb);

    r1 = (b-o)/~(b-o)*r + o;
    point rb1 = r1.rot(o, senb, cosb);
    point rb2 = r1.rot(o, -senb, cosb);

    ld d1 = acos((rb1 - o)*(ra2-o)/(r*r))*r;
    ld d2 = acos((rb2 - o)*(ra1-o)/(r*r))*r;


    printf("%.12Lf\n", min(d1, d2) + ~(b-rb1) + ~(a - ra1));

    return 0;
}
