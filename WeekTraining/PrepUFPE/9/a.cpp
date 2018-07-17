#include<bits/stdc++.h>

#define st first
#define nd second
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int N = 1e3+5;

map<vector<int>, int> rg;
ll n, m, r;

ll x[N], y[N];
ll a[N], b[N], c[N];
set<vector<int>> regions;

bool inside_cake(ll x, ll y) { return x*x + y*y <= r*r ; }

bool exists(vector<int> rg) {
    int ct = 0;
    for(ii p : ip) {
        for(int i=0; i<rg.size(); i++) {
            ll t = a[i]*p.st + b[i]*p.nd + c[i];
            if(rg[i] and t >= 0 and inside_cake(p.st, p.nd)) ct++;
            if(!rg[i] and t <= 0 and inside_cake(p.st, p.nd)) ct++;
        }
        if(ct == r) return true;
    }
    return false;
}

void place(ll x, ll y) {
    vector<int> ans;
    for(int i=0; i<m; i++) {
        ans.push_back( a[i] * x + b[i] * y + c[i] >= 0 );
    }
    rg[ans]++;
}

int main(){
    scanf("%lld %lld %lld", &n, &m, &r);

    for(int i=0; i<n; i++) scanf("%lld %lld", &x[i], &y[i]);
    for(int i=0; i<m; i++) scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);

    for(int i=0; i<m; i++) for(int j=i+1; j<m; j++) {
        
    }

    for(int i=0; i<n; i++) place(x[i], y[i]);

    for(int i=0; i < ((1 << (r+1)) - 1); i++) {
        vector<int> v;
        for(int j=0; j<r; j++) v.pb(((1 << j) & i) > 0);
        if(exists(v)) regions.insert(v);
    }

    for(auto it : rg) if(it.second != 1) return printf("no\n"), 0;
    printf("%s\n", regions.size() == n ? "yes" : "no");

    return 0;
}
