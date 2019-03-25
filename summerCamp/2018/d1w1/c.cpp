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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e3+5;

int lcs[N][N];
pair<vector<int>, vector<int>> lcss[N][N];
string a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b;
    int na = a.size(), nb = b.size();

    lcs[0][0] = 0;
    for(int i=1; i<=nb; i++) lcs[0][i] = 0;

    for(int i=1; i<=na; i++) {
        lcs[i][0] = 0;
        for(int j=1; j<=nb; j++) {
            if(a[i-1] == b[j-1]) {
                lcs[i][j] = 1 + lcs[i-1][j-1];
                lcss[i][j] = lcss[i-1][j-1];
                lcss[i][j].first.pb(i);
                lcss[i][j].second.pb(j);
            }
            if(lcs[i-1][j] > lcs[i][j]) {
                lcs[i][j] = lcs[i-1][j];
                lcss[i][j] = lcss[i-1][j];
            }
            if(lcs[i][j-1] > lcs[i][j]) {
                lcs[i][j] = lcs[i][j-1];
                lcss[i][j] = lcss[i][j-1];
            }
        }
    }
    printf("%d\n", lcs[na][nb]);
    auto p = lcss[na][nb];
    sort(p.first.begin(), p.first.end());
    for(auto i : p.first) printf("%d ", i);
    printf("\n");
    sort(p.second.begin(), p.second.end());
    for(auto i : p.second) printf("%d ", i);
    printf("\n");
}
