#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define st first
#define nd second

typedef long long ll;
typedef pair <ll, ll> pii;

set <pii> s, p;

ll n, x, y, ans;

int main () {
    for (ll i = 0; i <= 2018; i++) for (ll j = 0; j <= 2018; j++)
        if (i*i + j*j == 2018*2018) {
            s.insert(mp(i, j));
            s.insert(mp(i, -j));
            s.insert(mp(-i, j));
            s.insert(mp(-i, -j));
        }
    scanf("%lld\n", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &x, &y);
        p.insert(mp(x, y));
    }
    for (auto u : p) for (auto v : s) { 
        if (p.count(mp(u.st+v.st, u.nd+v.nd))) ans++;//, printf("ok");
    }
    printf("%lld\n", ans/2);
    return 0;
}
