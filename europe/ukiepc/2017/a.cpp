#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e5;
int d[N];

int main(){
  int n;
  cin >> n;
  int mx = 0;

  for(int i = 0; i < n; i++){
    int h, r, t;
    cin >> h >> r >> t;
    mx = max(mx, h);
    for(int j = 0; j < N; j++)
      if(r < t){
        if(j%h <= r or j%h >= t) d[j]++;
      }else if(j%h >= t and j%h <= r) d[j]++;

  }

  int ans = -1;

  for(int i = 0; i < mx*1825; i++)
    if(d[i] == n) { ans = i; break; }

  if(ans == -1) cout << "impossible" << endl;
  else cout << ans << endl;
}
