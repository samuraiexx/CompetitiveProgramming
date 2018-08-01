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

  int amt = 0;
  for(ll i = 2; i*i <= n; i++){
    if(n%i == 0) amt++;
    while(n%i == 0) n /= i;
  }
  if(n > 1) amt++;

  cout << (1ll << amt) - amt - 1 << endl;

}
