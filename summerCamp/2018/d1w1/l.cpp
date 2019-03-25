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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 200;

int dist[N][N];


int main() {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) dist[i][j] = INF;
    int n, k;
    cin >> n >> k;
    for(int i = 0, a, b, l; i < k; i++)
        cin >> a >> b >> l, dist[a][b] = l;

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    ld ans = 0;
    int cnt = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i != j and dist[i][j] != INF) ans += dist[i][j], cnt++;

    ans /= cnt;
    printf("%.6Lf\n", ans);
    return 0;
}
