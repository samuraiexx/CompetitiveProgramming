#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 

int main(){
  ll n;
  vector<ll> v;
  cin >> n;
  for(ll i = 0, a; i < n; i++)
    cin >> a, v.pb(a);

  sort(v.begin(), v.end());

  for(ll i = 1; i < v.size() - 1; i++)
    if(v[i - 1] + v[i] > v[i + 1]) return cout << "possible" << endl, 0;
  cout << "impossible" << endl;
}
