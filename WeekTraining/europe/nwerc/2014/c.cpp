#include<bits/stdc++.h>
using namespace std;

int n, d;
int p[2002];
int dp[2002][21];
int ps[2002];

int arr(int v)
{
    return v - v%10 + (v%10 < 5 ? 0 : 10);
}

int main(){
    cin >> n >> d;
    memset(dp, 0x3f, sizeof dp);
    for(int i = 1; i <= n; i++)
        cin >> p[i], ps[i] = ps[i - 1] + p[i];
    for(int p = 0; p <= n; p++)
            dp[p][0] = arr(ps[p]);
    for(int p = 1; p <= n; p++)
        for(int j = 1; j <= d; j++)
            for(int i = 0; i < p; i++)
            {
                dp[p][j] = min(dp[p][j], dp[i][j - 1] + arr(ps[p] - ps[i]));
            }
    int ans = dp[n][0];
    for(int i = 1; i <= d; i++)
        ans = min(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}
