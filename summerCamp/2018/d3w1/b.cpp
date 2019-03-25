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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, D = 1e5+5, N = 1e3+5;

int f[D], a, b, c;
int n, m, id[N][N], ord[D], inv[D], d;
map<int, int> aux;
map<int, set<int>> bck;
int cnt[D], ans[D], bck2[D];

int main() {
    memset(f, -1, sizeof f);
    scanf("%d %d %d %d", &f[0], &a, &b, &c);

    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &id[i][j]);
            aux[id[i][j]]++;
        }
    }

    for(auto p : aux) {
        bck[p.second].insert(p.first);
    }

    int it = 0;
    for(auto p : bck) {
        for(auto i : p.second) {
            cnt[it] = aux[i];
            it++;
        }
    }

    d = aux.size();
    for(int i=1; i<d; i++) f[i] = ((f[i-1]*a + b) % c) + 1, ord[i] = i;

    sort(ord, ord+d, [](int a, int b){ return f[a] < f[b]; } );
    sort(cnt, cnt+d);

    for(int i=0; i<d; i++) {
        int cur = ord[i];
        int num = cnt[i];
        int actualnum = *(bck[num].begin());
        ans[cur] = *(bck[num].begin());
        bck[num].erase(bck[num].begin());
    }

    printf("%d\n", d);
    for(int i=0; i<d; i++) printf("%d ", ans[i]);
    printf("\n");

    return 0;
}
