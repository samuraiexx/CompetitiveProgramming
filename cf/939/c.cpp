#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " <<
typedef long long ll;
const ll N = 1e5 + 5;
ll np[N];


int main(){
  ll n, s, f;
  cin >> n;
  for(ll i = 0; i < n; i++) cin >> np[i];

  cin >> s >> f;
  s--, f--;
  ll sum = 0;
  for(ll i = 0; i < f - s; i++)
    sum += np[i];

  ll mx = sum;
  ll p = 0;
  for(ll i = f - s; i < 2*n; i++){
    sum = sum + np[i%n] - np[(i - f + s)%n];
    if(sum >= mx){
      int pt = (i - (f - s) + 1)%n;
      if(sum > mx or (s + (n - pt)%n)%n < (s + (n - p)%n)%n)
        mx = sum, p = pt;
    }
  }

  cout << (s + (n - p)%n)%n + 1 << endl;
}
