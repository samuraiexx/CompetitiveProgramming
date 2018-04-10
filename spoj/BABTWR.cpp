#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  int n;
  while(cin >> n, n){
    vector<tuple<int, int, int>> v;
    for(int i = 0; i < n; i++){
      int x, y, z;
      cin >> x >> y >> z;
      vector<int> tp({x, y, z});
      sort(tp.begin(), tp.end());

      do v.pb({tp[0], tp[1], tp[2]});
      while(next_permutation(tp.begin(), tp.end()));
    }

    vector<int> dp;
    for(auto t : v) dp.pb(get<2>(t));

    for(int i = 0; i < v.size(); i++)
      for(int i = 0; i < v.size(); i++)
        for(int j = 0; j < v.size(); j++){
          int x1, x2, y1, y2, z1, z2;
          tie(x1, y1, z1) = v[i];
          tie(x2, y2, z2) = v[j];
          if(x1 < x2 and y1 < y2) dp[i] = max(dp[i], dp[j] + z1);
        }

    int mx = 0;
    for(auto x : dp) mx = max(mx, x);
    cout << mx << endl;
  }
}
