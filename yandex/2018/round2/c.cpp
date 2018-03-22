#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
typedef long long ll;
const int N = 105;
int mst[N];

int main(){
  int ans = 0;
  int n, m, ds, cs, da, ca;
  cin >> n >> m >> ds >> cs >> da >> ca;

  for(int i = 0; i < n; i++) cin >> mst[i];
  sort(mst, mst + n);

  for(int i = 0; i <= 100; i++){
    int dmg = i*da, amt = i*ca;
    if(amt > m) break;

    int ns = (m - amt)/cs;

    int x = upper_bound(mst, mst + n, dmg) - mst;
    for(int i = x; i < n; i++){
      int n2 = (mst[i] - dmg + ds - 1)/ds;
      if(n2 > ns) break;
      ns -= n2;
      x++;
    }

    ans = max(ans, x);
  }

  cout << ans << endl;
}
