#include<bits/stdc++.h>
using namespace std;

#define px first
#define py second
typedef long long ll;

pair<ll, pair<ll, ll>> pos[100];

long double dist(pair<ll, ll> p1, pair<ll, ll> p2){
    return hypot(p1.first - p2.first, p1.second - p2.second);
}

int main(){
    ll n, dt;
    cin >> n >> dt;
    for(ll i = 0, x, y, t;i < n; i++) 
        cin >> x >> y >> t, pos[i] = {t, {x, y}};

    long double cDist = 0;
    pair<ll, ll> prev = pos[0].second;
    pair<ll, ll> now;
    for(ll i = 1; i < n; i++){
        now = pos[i].second;
        cDist += dist(prev, now);
        prev = now;
    }

    vector<pair<ll, ll>> gps;
    gps.push_back(pos[0].second);
    ll t = 0;
    long double gDist = 0;
    for(ll t = dt, i = 0;; t += dt){
        while(pos[i].first < t && i < n) i++;
        if(t == pos[i].first and i == n - 1) break;
        if(i == n) break;
        prev = pos[i - 1].second, now = pos[i].second;
        gps.push_back({(ll) prev.px + (now.px - prev.px)*(t - pos[i - 1].first)/(ll)((ll)pos[i].first - pos[i - 1].first), 
                       (ll) prev.py + (now.py - prev.py)*(t - pos[i - 1].first)/(ll)((ll)pos[i].first - pos[i - 1].first)});
    }
    gps.push_back(pos[n - 1].second);

    prev = gps[0];
    for(auto now : gps){;
        gDist += dist(prev, now);
        prev = now;
    }

    
    printf("%.6Lf\n", 100*(cDist - gDist)/cDist);
    return 0;

}
