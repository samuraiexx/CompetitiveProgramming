#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
const int N = 4e4 + 5;
int dp[N];
int b[N];

int main(){
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> b[i];

  for(int i = 1; i <= n; i++){
    dp[i] = dp[i - 1] + 140;
    for(int j = i - 1; j > 0; j--){
      dp[i] = min(dp[i], dp[j - 1] + max(b[i] - b[j] - 1800 + 20, 20*(i - j + 1)) + 120);
    }
  }
  cout << dp[n] << endl;
}
