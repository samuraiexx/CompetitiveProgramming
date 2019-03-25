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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e6+5;

int n;
set<int> s;

int main() {
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        int u;
        scanf("%d", &u);
        s.insert(u);
    }

    vector<int> ans;
    for(auto i : s) ans.pb(i);
    if(n & 1) sort(ans.begin(), ans.end(), [](int a, int b){ return a < b; }); 
    else sort(ans.begin(), ans.end(), [](int a, int b){ return a > b; }); 

    for(int i : ans) printf("%d\n", i);

}
