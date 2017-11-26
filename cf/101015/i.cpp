#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 401;
ll mesa[N];
ll ps[N], ips[N];
ll dp[N][N];

ll cost(ll i, ll j){
    ll mid = (i + j)/2;
    return ips[mid] - ips[i] - i*(ps[mid] - ps[i]) +
           j*(ps[j] - ps[mid]) - (ips[j] - ips[mid]);
}

int main(){
    ll n, k;
    cin >> n >> k;
    for(ll i = 1; i <= n; i++){
        cin >> mesa[i], ps[i] = mesa[i] + ps[i - 1];
        ips[i] = i*mesa[i] + ips[i - 1];
    }
    
    for(ll i = 1; i <= n; i++)
        dp[i][1] = i*ps[i] - ips[i];

    for(ll i = 2; i <= n; i++)
        for(ll j = 2; j <= k; j++){
            dp[i][j] = cost(1, i);
            for(ll l = 2; l < i; l++)
                dp[i][j] = min(dp[i][j], dp[l][j - 1] + cost(l, i));
        }

    ll ans;
    memset(&ans, 0x3f, sizeof(ll));
    
    for(ll i = 1; i <= n; i++) 
        ans = min(ans, dp[i][k] + ips[n] - ips[i] - i*(ps[n] - ps[i]));

    cout << ans << endl;
    return 0;
}
