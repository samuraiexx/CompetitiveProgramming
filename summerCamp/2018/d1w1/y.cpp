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

ll n, fib[N];

int main() {
    scanf("%lld", &n);

    fib[0] = 0, fib[1] = 1, fib[2] = 1;
    for(int i=3; i<=n; i++) fib[i] = fib[i-1] + fib[i-3];

    printf("%lld\n", fib[n]);
    return 0;
}
