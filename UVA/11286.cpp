#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  while(cin >> n, n){
    map<set<int>, int> dc;
    for(int i = 0; i < n; i++){
      set<int> c;
      for(int j = 0, a; j < 5; j++)
        cin >> a, c.insert(a);
      dc[c]++;
    }

    int mx = 0;
    for(auto p : dc)
      mx = max(mx, p.second);
    int ans = 0;
    for(auto p : dc)
      if(p.second == mx) ans += p.second;
    
    cout << ans << endl;
  }
}
