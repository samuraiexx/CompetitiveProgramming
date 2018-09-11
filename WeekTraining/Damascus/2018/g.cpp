#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
ll pg[N], sg[N];
ll pl[N], sl[N];
ll v[N];
ll n, x, y;

ll mmc(ll a, ll b){
  return a*b/__gcd(a, b);
}

bool canbe(int i){
  ll gcd = __gcd(pg[i - 1], sg[i + 1]);
  ll lcm  = mmc(pl[i - 1], sl[ i + 1]);

  return __gcd(gcd, y/lcm) == 1;
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--){
    cin >> n >> x >> y;

    vector<int> err;
    pg[0] = 0, sg[n + 1] = 0;
    pl[0] = 1, sl[n + 1] = 1;

    for(int i = 1; i <= n; i++){
      cin >> v[i];

      if(v[i]%x == 0 and y%v[i] == 0){
        pg[i] = __gcd(pg[i - 1], v[i]/x);
        pl[i] = mmc(pl[i - 1], v[i]/x);
      } else err.pb(i);
    }

    if(y%x != 0 or n == 1 and x != y){
      cout << -1 << '\n';
      continue;
    }

    if(err.size() >= 2) { cout << err.size() << '\n'; continue; }

    for(int i = n; i > 0; i--){
      if(v[i]%x == 0 and y%v[i] == 0){
        sg[i] = __gcd(sg[i + 1], v[i]/x);
        sl[i] = mmc(sl[i + 1], v[i]/x);
      }
    }

    y/=x;
    x = 1;

    if(err.size() == 0 and pg[n] == x and pl[n] == y){
      cout << 0 << '\n';
      continue;
    }

    if(err.size() == 1)
      if(canbe(err[0])) cout << 1 << '\n';
      else cout << 2 << '\n';
    else {
      int pos = 0;
      for(int i = 1; i <= n; i++)
        if(canbe(i)) pos = i;
      if(pos > 0) cout << 1 << '\n';
      else cout << 2 << '\n';
    }
  }
}
