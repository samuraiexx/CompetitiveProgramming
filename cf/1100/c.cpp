#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const double pi = acos(-1);

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int n, r;
  cin >> n >> r;

  double w = pi/n;
  double ans = r/(1/sin(w) - 1);

  cout << fixed << setprecision(12) << ans << endl;
}
