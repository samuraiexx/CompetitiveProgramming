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

int x, vis[N], b[N], ans;
int n, m;
vi adj[N];

bool match(int u) {
    if(vis[u] == x) return 0;
    vis[u] = x;
    for(int v : adj[u])
        if(!b[v] or match(b[v])) return b[v] = u;
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        int t;
        while(scanf("%d", &t), t) {
            adj[i].pb(t);
        }
    }

    for(int i=1; i<=n; i++) ++x, ans += match(i);

    printf("%d\n", ans);
    for(int i=1; i<= m; i++) {
        if(b[i]) {
            printf("%d %d\n", b[i], i);
        }
    }
    return 0;
}
