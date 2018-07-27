#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1505;
const ll INF = 0x3f3f3f3f3f3f3f3f;
tuple<ll, ll, ll> cl[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  freopen("parabolas.in", "r", stdin);

  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    cout << "Case " << t << ":\n";

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
      int a, b, c;
      cin >> a >> b >> c;
      cl[i] = {a, b, c};
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
      ll x;
      cin >> x;


      ll ans = -INF;
      int pos;
      for(int i = 0; i < n; i++){
        int a, b, c;
        tie(a, b, c) = cl[i];

        ll y = a*x*x + b*x + c;
        if(y > ans) pos = i, ans = y;
      }

      cout << pos << ' ' << ans << '\n';
    }
  }
}
