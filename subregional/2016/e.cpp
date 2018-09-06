#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  ll r, g, b;
  cin >> hex >> r >> g >> b;


  ll amtg = (r/g);

  ll ans = 1 + amtg*amtg*(1 + (g/b)*(g/b));

  cout << hex << ans << endl;
}
