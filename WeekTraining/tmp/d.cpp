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
  ll n, x1, y1, x2, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;

  ll d = abs(x1 - x2) + abs(y1 - y2);
  if(d > n) cout << 0 << '\n';
  else cout << (n - d + 2)/2 - (d == 0) << '\n';
}
