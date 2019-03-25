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

vector<pair<ll, int>> v;
int n;

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v.pb(mp(b,-1)); v.pb(mp(a,1));
    }
    sort(v.begin(), v.end());
    ll cnt = 0, ans = 0, last = v[0].first;
    for(auto p : v) {
        if(cnt) ans += p.first - last;
        cnt += p.second; last = p.first;
    }
    printf("%lld\n", ans);
    return 0;
}
