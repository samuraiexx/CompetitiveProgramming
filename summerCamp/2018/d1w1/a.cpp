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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e6;

ld pnt[N][2];

int main() {
    int n;
    cin >> n;
    ld ans = 0;
    for(int i = 0; i < n; i++)
        cin >> pnt[i][0] >> pnt[i][1];

    ans += pnt[n - 1][0]*pnt[0][1];
    ans -= pnt[n - 1][1]*pnt[0][0];
    for(int i = 0; i < n - 1; i++) ans += pnt[i][0]*pnt[i + 1][1];
    for(int i = 0; i < n - 1; i++) ans -= pnt[i][1]*pnt[i + 1][0];

    ans = ans > 0 ? ans : -ans;
    
    ans /= 2;

    printf("%.6lf\n", (double) ans);
    return 0;
}
