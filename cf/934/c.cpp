#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long N = 2e3 + 5;
int seq[N];
int decr[N][N];
int one[N], two[N];

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> seq[i];

  for(int k = 0; k < n; k++){
    map<int, int, greater<int>> lis;
    int mx = 0;
    for (int i=k; i<n; ++i) {
      auto p = lower_bound(seq[i]);
      if(p == lis.end() or lis.begin()->first > seq[i])
        lis[seq[i]] = 1;
      else lis[seq[i]] = p->second + 1;
      mx = max(mx, lis[seq[i]]);
      decr[k][i] = mx;
    }
  }


  for(int i = 0; i < n; i++)
    for(int j = i; j >= 0; j--)
      if(seq[j] == 1) one[i]++;

  for(int i = 0; i < n; i++)
    for(int j = i; j < n; j++)
      if(seq[j] == 2) two[i]++;

  int ans = 0;
  for(int i = 0; i < n; i++)
    for(int j = i; j < n; j++)
      if(i > 0) ans = max(ans, one[i - 1] + decr[i][j] + two[j + 1]);
      else ans = max(ans, decr[i][j] + two[j + 1]);

  cout << ans << endl;
}
