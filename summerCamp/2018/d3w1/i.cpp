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

int n[2], k;
int a, b;
int coord[2][N][2];
map<int, set<pii>> f;
map<int, int> dp;
vector<int> ans;

void construct_map(int dir) {
    for(int i=1; i<=k; i++) {
        f[coord[dir][i][0]].insert(mp(coord[dir][i][1], i));
    }
}

bool match(int b, int e) {
    if(b == e) return true;
    if(b > e) return false;

    for(auto it: f[b]) {
        if(match(it.first, e)) {
            dp[b] = it.second;
            return true;
        }
    }
    return false;
}
void print_ans() {
    printf("%d\n", (int)ans.size());
    for(int i: ans) printf("%d ", i);
    printf("\n");
}
void save_dp(int dir, int b) {
    int x = dp[b];
    while(x) {
        ans.pb(x);
        b = coord[dir][x][1];
        x = dp[b];
    }
}

bool test(int dir) {
    if(coord[dir][a][0] > coord[dir][b][0]) swap(a, b);
    if(coord[dir][a][1] > coord[dir][b][0]) return false;

    ans.clear();
    dp.clear();
    f.clear();
    construct_map(dir);

    if(!match(0, coord[dir][a][0])) return false;
    save_dp(dir, 0);
    dp.clear();
    ans.pb(a);
    if(!match(coord[dir][a][1], coord[dir][b][0])) return false;
    save_dp(dir, coord[dir][a][1]);
    dp.clear();
    ans.pb(b);
    if(!match(coord[dir][b][1], n[dir])) return false;
    save_dp(dir, coord[dir][b][1]);

    print_ans();
    return true;
}

bool test2(int dir) {
    ans.clear();
    dp.clear();
    f.clear();
    construct_map(dir);
    ans.pb(a);

    if(!match(0, coord[dir][a][0])) return false;
    save_dp(dir, 0);
    dp.clear();
    if(!match(coord[dir][a][1], n[dir])) return false;
    save_dp(dir, coord[dir][a][1]);

    print_ans();
    return true;
}

int main() {
    scanf("%d%d", &n[0], &n[1]);
    scanf("%d", &k);

    for(int i=1; i<=k; i++) scanf("%d%d%d%d", &coord[0][i][0], &coord[1][i][0], &coord[0][i][1], &coord[1][i][1]);
    scanf("%d%d", &a, &b);

    if(a != b) {
        if(test(0)) return 0;
        if(test(1)) return 0;
    }
    else {
        if(test2(0)) return 0;
        if(test2(1)) return 0;
    }
    printf("-1\n");
    return 0;
}
