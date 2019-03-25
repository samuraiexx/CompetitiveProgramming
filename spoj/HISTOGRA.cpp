#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
int v[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int n;
  while(cin >> n && n){
    for(int i = 1; i <= n; i++)
      cin >> v[i];

    v[0] = v[n + 1] = 0;
    n += 2;

    ll ans = 0;
    stack<pair<int, ll>> s;
    for(int i = 0; i < n; i++){
      while(s.size() and v[i] < s.top().nd){
        auto p = s.top(); s.pop();
        ans = max(ans, p.nd*(i - s.top().st - 1));
      }
      s.push({i, v[i]});
    }

    cout << ans << endl;
  }
}
