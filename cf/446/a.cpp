#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int v[N], inc[N], rinc[N];

int main(){
  int n;
  cin >> n;

  for(int i = 0; i < n; i++)
    cin >> v[i];

  v[n++] = -1e9 - 5;

  int ans = 0;
  for(int i = 1, cnt = 1; i < n; i++){
    if(v[i] > v[i - 1]) cnt++;
    else{
      for(int j = i - cnt; j < i; j++)
        inc[j] = i - j, rinc[j] = j - i + cnt + 1;

      ans = max(ans, cnt + 1);
      cnt = 1;
    }
  }
  n--;
  if(ans > n) ans = n;

  for(int i = 1; i < n - 1; i++)
    if(v[i - 1] + 1 < v[i + 1])
      ans = max(ans, rinc[i - 1] + inc[i + 1] + 1);

  cout << ans << endl;
}
