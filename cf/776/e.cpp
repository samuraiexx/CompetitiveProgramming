#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 1e6 + 50;

bool sieve[N];
vector<ll> primes;


ll gcd(ll a, ll b){ return a ? gcd(b%a, a) : b; }

ll f(ll n){
  // Euler phi (totient)
  ll ind = 0, pf = primes[0], ans = n;
  while (1ll*pf*pf <= n) {
    if (n%pf==0) ans -= ans/pf;
    while (n%pf==0) n /= pf;
    pf = primes[++ind];
  }
  if (n != 1) ans -= ans/n;
  return ans;
}

int main(){
  for(ll i = 2; i < N; i++)
    if(!sieve[i]){
      primes.push_back(i);
      for(ll j = i*2; j < N; j+= i)
        sieve[j] = true;
    }

  ll n, k;
  cin >> n >> k;

  for(ll i = 1; i <= k and n != 1; i+=2){
    n = f(n);
  }
  cout << n%((long long)1e9 + 7) << endl;

