#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e2 + 5;
const int INF = 0x3f3f3f3f;
string l1, l2;

int dp[N][3];

bool can(int i){
  if(i >= l1.size() - 1) return false;
  return (l1[i] == '0') + (l1[i + 1] == '0') + 
         (l2[i] == '0') + (l2[i + 1] == '0') >= 3;
}

int main(){
  cin >> l1 >> l2;
  int n = l1.size();

  int x = (l1[0] == 'X') + (l2[0] == 'X');
  if(x > 0) dp[0][0] = -INF;
  if(x > 1) dp[0][1] = -INF;

  for(int i = 1; i < n; i++){
    int x = (l1[i] == 'X') + (l2[i] == 'X');

    if(x > 0) dp[i][0] = -INF;
    else
      dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});

    if(x > 1) dp[i][1] = -INF;
    else {
      if(x == 0) 
        dp[i][1] = max({dp[i - 1][2], dp[i - 1][1], 1 + dp[i - 1][0]});
      else
        dp[i][1] = max({dp[i - 1][2], dp[i - 1][1], dp[i - 1][0]});
    }

    if(x == 0)
      dp[i][2] = max({dp[i - 1][2], 1 + dp[i - 1][1], 1 + dp[i - 1][0]});
    else if(x == 1)
      dp[i][2] = max({dp[i - 1][2], dp[i - 1][1], 1 + dp[i - 1][0]});
    else
      dp[i][2] = max({dp[i - 1][2], dp[i - 1][1], dp[i - 1][0]});
  }

  cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;
}
