#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 

int main(){
  ll k, d, t;
  cin >> k >> d >> t;
  if(k%d == 0) return cout << t << endl, 0;
  d = (d + k - 1)/d*d;

  t = t*2;
  ll t2 = t/(k + d);
  ll t3 = t - t2*(k + d);
  long double ans = t2*d;
  bool dotfive = 0;
  if(t3 <= k*2){ 
    ans += t3/2.0;
  } else {
    t3 -= 2*k;
    ans += k + t3;
  }
  printf("%.12Lf\n", ans);
}
