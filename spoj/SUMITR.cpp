#include<bits/stdc++.h>
using namespace std;
int dp[100], t, n, mx, x;

int main(){
  cin >> t;
  while(t--){
    mx = 0;
    memset(dp, 0, sizeof dp);
    cin >> n;
    for(int i = 0; i < n; i++)
      for(int j = i; j >= 0; j--){
        cin >> x;
        dp[j] = x + max(dp[j], dp[max(0, j - 1)]);
        mx = max(mx, dp[j]);
      }
    cout << mx << endl;
  }
}
