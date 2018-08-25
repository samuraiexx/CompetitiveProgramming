#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int h[N], f[N];

int add(int x, int y){
  int ans = x + y;
  if(ans > MOD) ans -= MOD;
  return ans;
}

int mult(ll x, ll y){
  return (x*y)%MOD;
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> h[i], h[i]--;

  f[n - 1] = min(h[n - 1], h[n]);

  for(int i = n - 2; i >= 1; i--)
    f[i] = add(mult(f[i + 1], min({h[i], h[i + 1], h[i + 2]})), min(h[i], h[i + 1]));

  int ans = 0;
  for(int i = 1; i <= n; i++)
    ans = add(ans, h[i]);

  for(int i = 1; i <= n - 1; i++)
    ans = add(ans, mult(min(h[i], h[i + 1]), f[i]));

  cout << ans << endl;
}
