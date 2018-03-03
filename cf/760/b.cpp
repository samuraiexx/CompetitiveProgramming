#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 

ll n, m, k;

ll calc(ll mid){
    ll lm = max(1ll, mid - k + 1), rm = max(1ll, mid - (n - k));
    return (rm + mid)*(mid - rm + 1)/2 + (lm + mid)*(mid - lm + 1)/2 - mid;
}

int main(){
  cin >> n >> m >> k;
  m -= n;

  ll x;
  ll i = 0, j = m;
  while(i != j){
    ll mid = (i + j + 1)/2;
    if(calc(mid) > m) j = mid - 1;
    else i = mid;
  }
  cout << i + 1 << endl;
}
