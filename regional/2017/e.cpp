#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
int dp[N][N];
int from[N][N];
int n;

int fexp(int a, int b){
  int ans = 1;
  while(b)
    if(b&1) ans = (ans*a)%n, b--;
    else a = (a*a)%n, b/=2;

  return ans;
}

int main(){
  ios_base::sync_with_stdio(false), cin.tie(0);
  string s;
  cin >> s >> n;

  memset(dp, 0x3f, sizeof dp);
  dp[s.size()][0] = 0;

  for(int i = s.size() - 1; i >= 0; i--){
    vector<int> num;
    if(s[i] == '?')
      for(int j = (i == 0 ? 1 : 0); j < 10; j++) num.pb(j);
    else num.pb(s[i] - '0');

    for(int j = 0; j < n; j++){
      if(dp[i + 1][j] == INF) continue;
      for(auto x : num){
        int k = (j + x*fexp(10, s.size() - i - 1))%n;
        if(dp[i][k] > x or dp[i][k] == x and dp[i + 1][from[i][k]] > dp[i + 1][j])
          dp[i][k] = x, from[i][k] = j;
      }
    }
  }

  if(dp[0][0] == INF) return cout << "*\n", 0;

  int j = 0;
  for(int i = 0; i < s.size(); i++)
    cout << dp[i][j], j = from[i][j];
  cout << '\n';
}
