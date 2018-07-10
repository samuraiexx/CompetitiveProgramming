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

  ll i = 1, j = n;
  while(i != j){
    ll mid = (i + j)/2;

    ll z = n, t = 0;
    while(z)
      t += min(z, mid), z = max(z - mid, 0ll), z = z - z/10;

    if(t >= (n + 1)/2)
      j = mid;
    else 
      i = mid + 1;
  }

  cout << i << endl;
}
