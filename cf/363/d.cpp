#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
int pm[N], b[N];

int main(){
  int n, m, a;
  cin >> n >> m >> a;

  for(int i = 0; i < n; i++)
    cin >> pm[i];

  for(int i = 0; i < m; i++)
    cin >> b[i];

  sort(pm, pm + n, greater<int>());
  sort(b, b + m, greater<int>());

  int i = 0, j = min(n, m) + 1;
  while(i != j){
    int mid = (i + j)/2;
    int tmp = a;

    for(int i = 0; i < mid; i++){
      tmp = tmp - max(0, b[m - mid + i] - pm[i]);
    }

    if(tmp < 0) j = mid;
    else i = mid + 1;
  }

  int ans = i - 1;
  ll mn = 0;

  for(int i = 0; i < ans; i++){
    a -= max(0, b[m - ans + i] - pm[i]);
    mn += min(pm[i], b[m - ans + i]);
  }

  cout << ans << ' ' << max(0ll, mn - a) << endl;
}
