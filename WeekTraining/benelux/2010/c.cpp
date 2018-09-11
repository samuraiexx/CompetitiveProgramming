#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int mod = 1e4 + 7;
const int N = 5e3 + 5;
const int M = (1 << 9);
const int all = (1 << 9) - 1;
int dp[N][M];

int bit(int i, int j){
  return 1 << i*3 + j;
}

void bt(int i, int j, int bm, int cnt){
  if(i == 3) return bt(0, j + 1, bm, cnt);
  if(j == 3) return;
  bt(i + 1, j, bm, cnt);
  if(bit(i, j)&bm) return;
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  dp[0][0] = 1;
  for(int f = 0; f < N - 1; f++){
    for(int bm = 0; bm < M; bm++){
      dp[f + 1][all^bm] = dp[f][bm];

      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          if(bm > bit(i, j)) continue;
          int bmr = bit(i, j)|bit(i + 1, j);
          int bmd = bit(i, j)|bit(i, j + 1);

          if(i < 2 and !(bm&bmr)) 
              dp[f][bm|bmr] = (dp[f][bm|bmr] + dp[f][bm])%mod;

          if(j < 2 and !(bm&bmd)) 
              dp[f][bm|bmd] = (dp[f][bm|bmd] + dp[f][bm])%mod;
        }
      }
    }
  }

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << dp[n][0] << endl;
  }
}
