#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e3 + 10;
const ll mod = 1e9 + 7;
ll dp[N][N];

int main(){
    ll n;
    ll ans = 0;
    bool must = false;
    cin >> n;
    dp[0][0] = 1;
    for(ll i = 1; i <= n; i++){
        char c;
        cin >> c;

        if(must){
            if(c == 's') {
                for(ll j = 0; j <= n; j++) dp[i][j] = dp[i - 1][j];
                must = false;
            } else {
                for(ll j = 0; j <= n; j++) dp[i][j + 1] = dp[i - 1][j];
                dp[i][0] = 0;
            }
            continue;
        }

        for(ll j = n; j >= 0; j--)
            dp[i][j] = (dp[i - 1][j] + dp[i][j + 1])%mod;
        
        if(c == 'f'){
            must = true;
            for(ll j = n - 1; j >= 0; j--) dp[i][j + 1] = dp[i][j];
            dp[i][0] = 0;
        }
}

    for(ll i = 0; i <= n; i++)
        ans = (ans + dp[n][i])%mod;

    cout << ans << endl;
}
