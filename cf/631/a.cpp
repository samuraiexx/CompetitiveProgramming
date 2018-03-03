#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int a[N], b[N];
int xa[N][N], xb[N][N];

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];

  int mx = 0;
  for(int i = 0; i < n; i++)
    for(int j = i; j < n; j++)
      if(i == j) xa[i][j] = a[i], xb[i][j] = b[i];
      else xa[i][j] = xa[i][j - 1]|a[j],
           xb[i][j] = xb[i][j - 1]|b[j];
  
  for(int i = 0; i < n; i++)
    for(int j = i; j < n; j++)
      mx = max(mx, xa[i][j] + xb[i][j]);
  cout << mx << endl;
}
