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
  int n;
  cin >> n;

  vector<pair<int, int>> v;
  for(int i = 0, x, y; i < n; i++)
    cin >> x >> y, v.pb({x, y});

  sort(v.begin(), v.end());

  ll ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      int x = v[i].st + v[j].st;
      int y = v[i].nd + v[j].nd;

      if(x%2 or y%2) continue;
      x = x/2, y = y/2;

      ans += upper_bound(v.begin(), v.end(), make_pair(x, y)) - 
             lower_bound(v.begin(), v.end(), make_pair(x, y));
    }
  }
   
  cout << ans << endl;
}
