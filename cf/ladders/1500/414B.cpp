#include<bits/stdc++.h>

using namespace std;

const int N = 2001;
vector<int> divis[N];
const int mod = 1e9 + 7;

int dp[N][N];

int main(){
    int n, k;
    cin >> n >> k;
    int ans = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 2*i; j <= n; j += i)
            divis[j].push_back(i);
    
    for(int i = 1; i <= k; i++) dp[1][i] = 1;
    for(int i = 1; i <= n; i++) dp[i][1] = 1;
    
    for(int i = 2; i <= n; i++)
        for(int j = 2; j <= k; j++) {
            dp[i][j] = dp[i][j - 1];
            for(int d : divis[i])
                dp[i][j] = (dp[i][j] + dp[d][j - 1])%mod;
        }

    for(int i = 1; i <= n; i++)
        ans = (ans + dp[i][k])%mod;

    cout << ans << endl;
    return 0;
}
