#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 401; const ll INF = 0x3f3f3f3f3f3f;

ll mesa[N];
ll ps[N], ips[N];

ll dp[N][N];
ll dpos[N][N];

ll cost(ll i, ll j){
    ll mid = (i + j)/2;
    return ips[mid] - ips[i] - i*(ps[mid] - ps[i]) +
        j*(ps[j] - ps[mid]) - (ips[j] - ips[mid]);
}

ll calc(ll x, ll l, ll r, ll k){
    if(dpos[x][k]) return dpos[x][k];
    ll mn = 0;
    for(ll i = l, val; i <= r; i++)
            if(dp[x][k] > (val = dp[i][k - 1] + cost(i, x)))
                dp[x][k] = val, mn = i;

    return dpos[x][k] = mn;
}

void solve(ll l, ll r, ll mn, ll mx, ll k){
    if(l > r) return;
    if(r == l + 1){ calc(l, mn, mx, k), calc(r, mn, mx, k); return; }
    ll mid = (l + r)/2;
    ll pos = calc(mid, mn, mx, k);

    if(l != r)
        solve(l, mid, mn, pos, k), solve(mid, r, pos, mx, k);
}

int main(){
    ll n, k;
    ll ans = INF;

    cin >> n >> k;
    for(ll i = 1; i <= n; i++){
        cin >> mesa[i], ps[i] = mesa[i] + ps[i - 1];
        ips[i] = i*mesa[i] + ips[i - 1];
    }

    memset(dp, 0x3f, sizeof dp);

    for(ll i = 1; i <= n; i++)
        dp[i][1] = i*ps[i] - ips[i];
    
    for(ll j = 2; j <= k; j++)
        for(ll i = 1; i <= j; i++)
            dp[i][j] = 0, dpos[i][j] = i;


    for(ll i = 2; i <= k; i++) solve(1, n, 1, n, i);

    for(ll i = 1; i <= n; i++) 
        ans = min(ans, dp[i][k] + ips[n] - ips[i] - i*(ps[n] - ps[i]));
    
    cout << ans << endl;
    return 0;
}
