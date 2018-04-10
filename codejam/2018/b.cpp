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
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    int n;
    vector<int> v, e, o, v2;
    cin >> n;
    for(int i = 0; i < n; i++){
      int x;
      cin >> x;
      if(i&1) o.pb(x);
      else e.pb(x);
      v.pb(x);
    }
    int ans = -1;
    sort(v.begin(), v.end());
    sort(e.begin(), e.end());
    sort(o.begin(), o.end());
    
    for(int i = 0; i < n; i++)
      if(i&1) v2.pb(o[i/2]);
      else v2.pb(e[i/2]);
    for(int i = 0; i < n; i++)
      if(v[i] != v2[i]){
        ans = i;
        break;
      }
    cout << "Case #" << t << ": ";
    if(ans == -1) cout << "OK" << '\n';
    else cout << ans << '\n';
  }
}
