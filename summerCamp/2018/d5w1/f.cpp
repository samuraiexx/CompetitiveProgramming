#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
define mp make_pair
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

ll f[N], nones[N], ps[N], pf[N];
ll n;

ll solve_for_some(ll num, int howmany) {
    ll c = 0, ans = 0, cnt = 0;
    int i=0;
    while(f[i+1] < num ) i++;
    printf("calling the count on %lld %d\n", num, howmany);
    if(howmany == 0) return 0;
    while(num and cnt <= howmany) {
        printf("%lld %d ", num, i);
        if(num >= f[i+1]) {
            ans++;
            num -= f[i];
            printf(" isso");
        }
        printf("\n");
        cnt++; i--;
    }
    return ans;
}

int main() {
    //freopen("fibonacci.in", "r", stdin);
    //freopen("fibonacci.out", "w", stdout);


    scanf("%lld", &n);
    f[0] = 0, f[1] = 1, f[2] = 1;
    pf[0] = 0, pf[1] = 2, pf[2] = 3;
    nones[1] = 1, nones[2] = 1;
    ps[0] = 0, ps[1] = 1, ps[2] = 2;

    if(n == 0) return printf("0\n"), 0;
    if(n == 1) return printf("1\n"), 0;
    if(n == 2) return printf("2\n"), 0;
    if(n == 3) return printf("2\n"), 0;

    ll i=3, ans = 2, curnumb = 3;

    n -= 3;
    while(n) {
        f[i] = f[i-1] + f[i-2];
        pf[i] = pf[i-1] + f[i];
        nones[i] = f[i] + ps[i-2];
        ps[i] = ps[i-1] + nones[i];

        if(i*f[i] <= n) {
            ans += nones[i];
            n -= i*f[i];
            curnumb += f[i];
        } else {
            ll k = 1;
            while(n > 2*i) {
                ll j = 1;
                printf("start: %lld %lld\n", n, curnumb);
                while(pf[j] * i <= n) {
                    ans += ps[j] + k*f[j];
                    n -= pf[j]*i;
                    curnumb += pf[j];
                    j++;
                }
                printf("end: ");
                printf("%lld %lld %lld\n", n, j, curnumb);
                k++;
            }
            if(n and n <= 2*i) {
                if(n > i) {
                    ans += solve_for_some(curnumb, i);
                    n -= i;
                    if(n > 0 and n <= i) ans += solve_for_some(curnumb+1, n);
                    n = 0;
                }
                else {
                    ans += solve_for_some(curnumb, n);
                    n = 0;
                }
                break;
            }
        }
        if(n <= i) {
            ans += solve_for_some(curnumb, n);
            n = 0;
        }

        i++;
    } 

    if(n) {
        ans += solve_for_some(curnumb, n);
        n = 0;
    }
    printf("%lld\n", ans);
}
