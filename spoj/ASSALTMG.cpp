#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 20;
int dir[N];
const int INF = 0x3f3f3f3f;
//int dp[N];

int amt_ones(int n){
  int amt = 0;
  for(int i = 0; i < 32; i++)
    if((1 << i)&n) amt++;
  return amt;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int m, d;
    map<int, int> dp;

    cin >> m >> d;

    for(int i = 0; i < d; i++){
      int amt, mask = 0;
      cin >> amt;
      for(int i = 0, x; i < amt; i++)
        cin >> x, mask |= (1 << x); 

      dir[i] = mask;
    }

    dp[0] = 0;
    for(int i = 0; i < d; i++){
      for(auto a : dp){
        int msk = a.st|dir[i];
        if(dp.count(msk))
          dp[msk] = min(dp[msk], a.nd + 1);
        else dp[msk] = a.nd + 1;
      }
    }
    int mn = INF;
    for(auto a : dp){
      if(amt_ones(a.st) >= m) mn = min(mn, a.nd);
    }

    if(mn != INF) cout << mn << endl;
    else cout << "Desastre!" << endl;
  }
}
