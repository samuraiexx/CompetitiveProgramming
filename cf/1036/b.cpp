#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  int q;
  cin >> q;

  while(q--){
    ll n, m, k;
    cin >> n >> m >> k;
    
    ll ans, need;

    if(((n + m)&1)) ans = k - 1, need = ((k&1) != (max(n, m)&1)) + max(n, m);
    else if((max(n, m)&1) != (k&1))
      ans = k - 2, need = (abs(n - m) <= 1) + max(n, m);
    else ans = k, need = max(n, m); 

    if(k < need) cout << -1 << endl;
    else cout << ans << endl;
  }
}
