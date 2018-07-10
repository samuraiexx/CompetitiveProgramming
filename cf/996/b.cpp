#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;

int main(){
  int n;
  ll mn = 0x3f3f3f3f3f3f3f3f;
  ll ans;
  cin >> n;
  for(ll i = 0; i < n; i++){
    ll x;
    cin >> x;

    int t = x%n <= i ? x/n*n + i : (x + n - 1)/n*n + i;
    if(t < mn) mn = t, ans = i + 1;
  }

  cout << ans << endl;
}
