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

pair<int, int> pnts[N];

int main() {
    int n;
    map<pair<int, int>, int> st;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> pnts[i].st >> pnts[i].nd;
    if(n <= 3) return cout << 0 << endl, 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            st[make_pair(pnts[i].st + pnts[j].st, pnts[i].nd + pnts[j].nd)]++;

    for(auto p : st) if(p.nd > 1) return cout << 1 << endl, 0;
    cout << 2 << endl;
}
