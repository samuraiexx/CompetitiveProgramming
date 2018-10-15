#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 75;
ll dp[N][10][2];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  for(ll i = 0; i < 10; i++)
    dp[1][i][true] = 1;

  for(ll i = 2; i < N; i++){
    for(ll j = 0; j < 10; j++){
      for(ll k = 0; k < 10; k++){
        if(k <= j)
          dp[i][j][true] += dp[i - 1][k][true];
        else dp[i][j][false] += dp[i - 1][k][true] + dp[i - 1][k][false];
        if(k == j) dp[i][j][false] += dp[i - 1][k][false];
      }
    }
  }

  ll t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;


    bool dec = false;
    bool nok = false;
    ll ans = 0;
    for(ll i = 0; i < s.size(); i++){
      if(i > 0 and s[i] < s[i - 1]) dec = true;
      if(i > 0 and dec and s[i] > s[i - 1]) nok = true;

      ll x = s[i] - '0';
      ll sz = s.size() - i;

      if(sz == 1) { ans += x; continue; }

      for(ll j = 0; j < x; j++){
        for(ll k = 0; k < 10; k++){
          if(dec or (i > 0 and s[i - 1] - '0' > j)){
            if(k <= j) ans += dp[sz - 1][k][true];
          } else {
            ans += dp[sz - 1][k][true];
            if(k >= j) ans += dp[sz - 1][k][false];
          }
        }
      }
    }

    if(nok) cout << -1 << '\n';
    else cout << ans << '\n';
  }
}
