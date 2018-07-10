#include<bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
using namespace std;
const int N = 2e3 + 1;
const int INF = 0x3f3f3f3f;
int n, h;
double p;
int tr[N];

float dp[N][N][3][2][2];

float dpf(int l, int r, int state, int fl, int fr){ //state: not falling, fallirng l, falling r
  if(l > r) return 0;
  if(dp[l][r][state][fl][fr] != 0) 
    return dp[l][r][state][fl][fr];

  if(l == r and state != 0){
    if(state == 1){
      dp[l][r][state][fl][fr] = min(h, tr[r + 1] - tr[r] - h*fr);
    }else if(state == 2){
      dp[l][r][state][fl][fr] = min(h, tr[l] - tr[l - 1] - h*fl);
    }
  } else if(state == 0){
    dp[l][r][state][fl][fr] += 0.5*((1 - p)*dpf(l, r, 1, false, fr) +
                                    p*(dpf(l + 1, r, 0, false, fr) +
                                             min(h, tr[l] - tr[l - 1] - h*fl)));
    dp[l][r][state][fl][fr] += 0.5*(p*dpf(l, r, 2, fl, false) +
                                    (1 - p)*(dpf(l, r - 1, 0, fl, false) +
                                             min(h, tr[r + 1] - tr[r] - h*fr)));
  } else if(state == 1){
    dp[l][r][state][fl][fr] = min(h, tr[l + 1] - tr[l]) +
                              dpf(l + 1, r, (tr[l + 1] - tr[l]) < h, true, fr);
  } else if(state == 2){
    dp[l][r][state][fl][fr] = min(h, tr[r] - tr[r - 1]) +
                              dpf(l, r - 1, ((tr[r] - tr[r - 1]) < h)*2, fl, true);
  }

  //db(l _ r _ state _ fl _ fr _ dp[l][r][state][fl][fr]);

  return dp[l][r][state][fl][fr];
}

int main(){
  cin >> n >> h >> p;
  for(int i = 1; i <= n; i++)
    cin >> tr[i];
  tr[0] = -INF, tr[n + 1] = INF;

  sort(tr, tr + n + 2);

  printf("%.12lf\n", dpf(1, n, 0, 0, 0));
}
