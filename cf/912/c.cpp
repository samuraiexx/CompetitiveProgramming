#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 3e9;
const ll N = 3e5;
ll en[N][3];
set<pair<ll, ll>> reg[N];
vector<pair<ll, ll>> inter;
vector<ll> times;

ll bit[N];

void add(ll bg, ll ed, ll v) {
    if(ed < bg) return;
    ll p = bg;
    for (p+=2; p<N; p+=p&-p) bit[p] += v;
    p = ed;
    for (p+=2; p<N; p+=p&-p) bit[p] -= v;
}

ll query(ll p) {
    ll r = 0;
    for (p+=2; p; p-=p&-p) r += bit[p];
    return r;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m;
    ll b, inc, d;
    cin >> n >> m;
    cin >> b >> inc >> d;

    for(ll i = 1; i <= n; i++)
        cin >> en[i][0] >> en[i][1] >> en[i][2];

    for(ll i = 0; i < m; i++){
        ll t, e, h;
        cin >> t >> e >> h;
        reg[e].insert({t, h});
    }

    for(ll i = 1; i <= n; i++){
        if(en[i][0] <= d and inc) return cout << -1 << endl, 0;
        reg[i].insert({0, en[i][1]});
        for(auto it = reg[i].begin(); it != reg[i].end(); it++){
            auto a = *it;
            ll t = INF;
            if(d < a.second) continue;
            if(en[i][2]) t = a.first + (d - a.second)/en[i][2];
            else if(a.second <= d and inc) return cout << -1 << endl, 0;
            if(next(it) != reg[i].end()) t = min(t, next(it)->first - 1);
            times.push_back(t);
            inter.push_back({a.first, t});
        }
    }

    times.push_back(0);
    sort(times.begin(), times.end());
    for(auto a : inter){
        ll bg = lower_bound(times.begin(), times.end(), a.first) - times.begin();
        ll ed = upper_bound(times.begin(), times.end(), a.second) - times.begin();
        add(bg, ed, 1);
    }
    
    ll mx = 0;
    for(auto a : times){
        ll p = lower_bound(times.begin(), times.end(), a) - times.begin();
        mx = max(mx, (ll)query(p)*(b + a*inc));
    }

    cout << mx << endl;
}
