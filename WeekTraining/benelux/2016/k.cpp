#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
const ll N = 1e6 + 5;
ll dp[N];
const ll m = 123456789;

int main(){
  ll l, s;
  cin >> l >> s;

  ll as = 0, sum = 0;
  dp[0] = 1, as++;
  for(ll i = 1; i < s; i++)
    dp[i] = as, as = (as + dp[i])%m;

  for(ll i = s; i < l; i++)
    dp[i] = as, as = (as + dp[i] - dp[i - s] + m)%m;

  for(ll i = l - s + 1; i < l; i++)
    dp[i] = (dp[i] + dp[i - 1])%m;

  for(ll i = l - s; i < l; i++)
    sum = (sum + dp[i])%m;

  cout << sum << endl;
}
