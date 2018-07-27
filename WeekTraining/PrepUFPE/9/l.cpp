#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f, EPS = 1e-4;

long double d, s, l = 0, r = INF, m;

long double f (long double x) {
    return -s + x*(1-cosh(d/(2*x)));
}

long long int cnt;

int main () {
    scanf("%Lf%Lf", &d, &s);
    while (abs(l-r) > EPS and ++cnt < 100) {
        m = (l+r)/2;
        printf("l %.3Lf m %.3Lf r = %.3Lf f(r) %.3Lf\n", l, m, r, f(r));
        if (f(m) < 0) l = m;
        else r = m;
    }
    printf("%.9Lf\n", 2*m*sinh(d/(2*m)));
    return 0;
}
