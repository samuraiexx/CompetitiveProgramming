#include<bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
using namespace std;
const int N = 205;

double dp[N][N];
double house[N];

int main(){
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    int h, c;
    cin >> h >> c;
    for(int i = 0; i < h; i++){
      cin >> house[i];
      for(int j = 0; j < h; j++)
        dp[i][j] = std::numeric_limits<double>::infinity();
    }

    dp[0][1] = 0;

    for(int i = 1; i < h; i++){
      for(int j = 0; j < i; j++){
        double err = 0;
        for(int k = j + 1; k < i; k++)
          err += abs(house[j] + (house[i] - house[j])*(k - j)/(double)(i - j) - house[k]);

        for(int k = 1; k <= min(c, j + 1); k++)
          dp[i][k + 1] = min(dp[i][k + 1], err + dp[j][k]);
      }
    }

    printf("%.4lf\n", dp[h - 1][c]/h);
  }
}
