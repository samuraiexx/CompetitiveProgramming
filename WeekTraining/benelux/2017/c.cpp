#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
const int N = 5e5 + 5;
ll v[N];

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main(){
  cin.tie(0), ios_base::sync_with_stdio(0);
  int n;
  set<ll> ans, gcdi;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> v[i];

  for(int i = 0; i < n; i++){
    set<ll> gcdii;
    if(i > 0) for(auto a : gcdi)
      gcdii.insert(gcd(a, v[i])), ans.insert(gcd(a, v[i]));
    gcdii.insert(v[i]);
    ans.insert(v[i]);

    gcdi = gcdii;
  }

  cout << ans.size() << endl;
}
