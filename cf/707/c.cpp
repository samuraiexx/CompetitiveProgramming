#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  ll n;
  cin >> n;
  if(n == 1 or n == 2) return cout << -1 << endl, 0;
  
  n = n*n;

  ll ans;
  if(n%2 == 1) ans = 1;
  else ans = 2;

  ll x = n/ans, y = ans;
  cout << (x + y)/2 << ' ' << (x - y)/2 << endl;
}
