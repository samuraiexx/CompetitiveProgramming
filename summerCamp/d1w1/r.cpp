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

long double a, b, c;

bool positive(ld x) {
    return a*x*x + b*x + c > -EPS;
}

bool negative(ld x) {
    return a*x*x + b*x + c < EPS;
}

bool check(ld x) {
    return positive(x) and negative(x);
}

bool iszero(ld x) {
    return x < EPS and x > -EPS;
}

bool same(ld x, ld y) {
    return (positive(x) and positive(y)) or (negative(x) and negative(y));
}

ld ans(ld l, ld r, bool lf) {
    ld m;
    for(int i=0; i<50000; i++) {
        m = (l + r)/2;
        if(lf) {
            if(positive(m)) l = m;
            else r = m;
        }
        else {
            if(positive(m)) r = m;
            else l = m;
        }
    }
    return m;
}

double aa, bb, cc;
int main() {
    scanf("%lf %lf %lf", &aa, &bb, &cc);
    a = aa, b = bb, c = cc;
    if(iszero(a)) {
        if(iszero(b)) {
            return printf("%d\n", iszero(c) ? -1 : 0), 0;
        }
        else {
            return printf("1\n%.12lf\n", (double) (- c/b)), 0;
        }
    }
    long double div = (-b) / 2*a;

    if(check(div)) {
        return printf("1\n%.12lf\n", (double) div), 0;
    }

    if(same(div, -INF)) return printf("0\n"), 0;
    
    ld ans1 = ans(-INF, div, true);
    ld ans2 = ans(div, INF, false);

    printf("2\n%.12lf\n%.12lf\n", (double) ans1, (double) ans2);

    return 0;
}
