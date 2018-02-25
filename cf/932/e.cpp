#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
typedef long long ll;

const int N = 4e5 + 2;
const int MOD = 1e9 + 7;

int fat[N];

ll fexp(ll a, ll b, ll m = MOD) {
  ll r=1;
  for (a %= m; b; b>>=1, a=(a*a)%m) if (b&1) r=(r*a)%m;
  return r;
}

int main(){
  fat[0] = 1;
  for(int i = 1; i < 100; i++) fat[i] = i*fat[i - 1];

  int i = 2;
  for(int k = 0; k < 30; k++){
    int ans = 0;
    for(int j = 1; j <= i; j++)
      ans += fat[i]/fat[j]/fat[i - j]*fexp(j, k);
    cout << k << ' ' <<  ans << endl;
  }
}
