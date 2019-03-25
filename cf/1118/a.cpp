#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  ll q;
  cin >> q;
  while(q--){
    ll n, a, b;
    cin >> n >> a >> b;
    if(2*a <= b) cout << n*a << '\n';
    else cout << n/2*b + n%2*a << '\n';
  }
}
