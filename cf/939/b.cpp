#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " <<

typedef long long ll;

int main(){
  ll n, k;
  ll mn = 0x3f3f3f3f3f3f3f3f, b, ind;
  cin >> n >> k;
  for(ll i = 0; i < k; i++){
    ll a;
    cin >> a;
    if(n%a < mn) mn = n%a, b = a, ind = i + 1;
  }

  cout << ind << ' ' << n/b << endl;
}
