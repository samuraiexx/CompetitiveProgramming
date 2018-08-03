#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll v[N];

int main(){
  int n;
  cin >> n;

  multiset<ll> xs, ys;
  for(int i = 0; i < 2*n; i++)
    cin >> v[i];

  sort(v, v + 2*n);

  for(int i = 0; i < 2*n; i++)
    if(i < n) xs.insert(v[i]);
    else ys.insert(v[i]);

  auto bg1 = xs.begin(), bg2 = ys.begin();
  auto ed1 = xs.end(), ed2 = ys.end();
  ed1--, ed2--;

  ll ans = (*ed1 - *bg1)*(*ed2 - *bg2);

  for(int i = 0; i < n; i++){
    xs.erase(xs.find(v[i]));
    xs.insert(v[i + n]);
    ys.erase(ys.find(v[i + n]));
    ys.insert(v[i]);

    auto bg1 = xs.begin(), bg2 = ys.begin();
    auto ed1 = xs.end(), ed2 = ys.end();
    ed1--, ed2--;

    ans = min(ans, (*ed1 - *bg1)*(*ed2 - *bg2));
  }

  cout << ans << endl;

}
