#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e3 + 5;
const int MOD = 1e9 + 7;
char m[5][N];
int dp[5][N][3]; // < ^ v

int add(int a, int b){
  return (a + b)%MOD;
}

int main(){
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    memset(dp, 0, sizeof dp);
    int n;
    cin >> n;
    for(int i = 1; i <= 3; i++)
      for(int j = 1; j <= n; j++)
        cin >> m[i][j];

    if(m[1][1] == '.') 
      dp[1][1][0] = 1;

    for(int j = 1; j <= n; j++){
      for(int i = 1; i <= 3; i++){
        if(m[i][j] == '#' or i == 1 and j == 1) continue;
        dp[i][j][0] = add(dp[i][j - 1][1], dp[i][j - 1][2]);
      }
      for(int i = 1; i <= 3; i++){
        if(m[i][j] == '#') continue;
        dp[i][j][1] = dp[i - 1][j][0];
        dp[i][j][2] = dp[i + 1][j][0];
      }
    }

    cout << "Case #" << t << ": ";
    cout << add(dp[3][n][1], dp[3][n][2]) << endl;
  }
}
