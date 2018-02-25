#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
typedef long long ll;
const ll mod = 1e9 + 7;

ll fexp(ll a, ll b){
  ll ans = 1;
  while(b)
    if(b%2) ans = (ans*a)%mod, b--;
    else a = (a*a)%mod, b /= 2;
  return ans;
}

int main(){
  ll n;
  ll ans = 0;
  cin >> n;
  
  cout << fexp(n, (n-1)*(n-1)) << endl;
}
