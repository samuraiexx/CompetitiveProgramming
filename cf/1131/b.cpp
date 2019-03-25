#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int n;
  cin >> n;

  int a = 0, b = 0;
  int mn = -1;
  ll ans = 0;
  for(int i = 0; i < n; i++){
    int a2, b2;
    cin >> a2 >> b2;
    ans += max(min(a2, b2) - max({a, b, mn + 1}) + 1, 0);
    mn = min(a2, b2);
    a = a2, b = b2;
  }

  cout << ans << endl;
}
