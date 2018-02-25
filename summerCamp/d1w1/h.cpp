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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e2+5;

int m, n, xi, yi, xf, yf, p, q;

int vis[N][N], parx[N][N], pary[N][N];

int print(int x, int y, int cont) {
    if(parx[x][y] != 0 and pary[x][y] != 0) {
        print(parx[x][y], pary[x][y], cont+1);
    }
    else {
        printf("%d\n", cont);
    }
    printf("%d %d\n", x, y);
}

int main() {
    scanf("%d%d%d%d%d%d%d%d", &m, &n, &p, &q, &xi, &yi, &xf, &yf);
    int dx[] = {p, p, q, q, -p, -p, -q, -q},
        dy[] = {q, -q, p, -p, q, -q, p, -p};

    queue<pii> q;

    q.push(mp(xi, yi));
    vis[xi][yi] = 1;

    while(!q.empty()) {
        int x = q.front().st, y = q.front().nd;
        q.pop();
        if(x == xf and y == yf) {
            print(x, y, 0);
            return 0;
        }
        for(int i=0; i<8; i++) {
            int a = x+dx[i], b = y+dy[i];
            if(a <= 0 or a > m or b <= 0 or b > n) continue;
            if(vis[a][b]) continue;

            q.push(mp(a, b));
            parx[a][b] = x;
            pary[a][b] = y;
            vis[a][b] = 1;
        }

    }

    printf("-1\n");
    return 0;
}
