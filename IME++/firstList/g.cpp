#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll r;
  cin >> r;
  ll ans = 1;
  for(ll i = 0; i < r; i++) ans *= 3;
  cout << ans << endl;
}
