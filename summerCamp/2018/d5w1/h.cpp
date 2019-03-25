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

ll n, a[N], ord[N], ans[N];
int main() {
    freopen("hell.in", "r", stdin);
    freopen("hell.out", "w", stdout);

    scanf("%lld", &n);
    for(int i=0; i<n; i++) scanf("%lld", &a[i]), ord[i] = i;

    sort(ord, ord+n, [](int i, int j){ return a[i] < a[j]; });

    ll sum = 0;
    for(int i=n-1; i>=0; i--) {
        if(sum > 0) sum -= a[ord[i]], ans[ord[i]] = -1;
        else sum += a[ord[i]], ans[ord[i]] = 1;
    }

    if(sum) printf("No\n");
    else {
        printf("Yes\n");
        for(int i=0; i<n; i++) printf("%lld ", ans[i]);
        printf("\n");
    }

    return 0;
}
