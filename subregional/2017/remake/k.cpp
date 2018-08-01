#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int MOD = 1e6;
const double EPS = 1e-8;
ll a, b, n, k;

pair<ll, ll> fexp(pair<ll, ll> a, ll e){
  pair<ll, ll> ans({1, 0});
  while(e){
    if(e&1){
      ans = {(ans.st*a.st + ans.nd*a.nd*b)%MOD, 
             (ans.st*a.nd + ans.nd*a.st)%MOD};
      e--;
    }else{
      a = {(a.st*a.st + a.nd*a.nd*b)%MOD, 
           (a.st*a.nd + a.nd*a.st)%MOD};
      e /= 2;
    }
  }

  return ans;
}

int main(){
  cin >> a >> b >> n >> k;

  auto p = fexp({a, 1}, n);

  int ans = 2*p.st;
  if(a*a - b > 0 or n%2 == 0 && a*a != b)
    ans = (ans + MOD - 1)%MOD;

  for(int i = 1; i < k; i++)
    ans /= 10;

  cout << ans%10 << endl;
}
