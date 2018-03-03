#include<bits/stdc++.h>
using namespace std;
const int N = 3e3;
int v[4][N];
int s[N*N];

int main(){
  int n;
  long long ans = 0;
  scanf("%d", &n);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < 4; j++)
      scanf("%d", &v[j][i]);

  int sz = 0;
  for(int i = 0; i < n; i++){
    int x = v[0][i];
    for(int j = 0; j < n; j++)
      s[sz++] = -(x + v[1][j]);
  }


  sort(s, s + sz);

  for(int i = 0; i < n; i++){
    int x = v[2][i];
    for(int j = 0; j < n; j++){
      int y = v[3][j];
      ans += upper_bound(s, s + sz, x + y) -
             lower_bound(s, s + sz, x + y);
    }
  }

  printf("%lld\n", ans);
}
