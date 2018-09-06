#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e3;
int v[N];

int main(){
  int n, a, b;
  cin >> n >> a >> b;

  for(int i = 0; i < n; i++)
    cin >> v[i];

  int ans = 0;
  for(int i = 0; i < n/2; i++){
    if(v[i] < v[n - i - 1]) swap(v[i], v[n - i - 1]);

    if(v[i] == 2)
      if(v[n - i - 1] == 2) ans += 2*min(a, b);
      else ans += v[n - i - 1] == 0 ? a : b;
    else if(v[i] != v[n - i - 1])
      return cout << -1 << endl, 0;
  }
  if(n&1 and v[n/2] == 2)
    ans += min(a, b);

  cout << ans << endl;
}
