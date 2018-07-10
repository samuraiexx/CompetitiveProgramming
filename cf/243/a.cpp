#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int v[N];

int main(){
  int n;
  cin >> n;

  vector<int> b[30];

  for(int i = 0; i < n; i++){
    cin >> v[i];
    for(int j = 0; j < 30; j++)
      if((1 << j)&v[i]) b[j].push_back(i);
  }

  set<int> ans;

  for(int i = 0; i < n; i++){
    int x = v[i];
    int j = i + 1;
    while(true){
      int p = n;
      ans.insert(x);

      for(int i = 0; i < 30; i++){
        if((1 << i)&x) continue;
        auto it = lower_bound(b[i].begin(), b[i].end(), j);
        if(it != b[i].end()) p = min(p, *it);
      }
      if(p == n) break;
      x |= v[p], j = p + 1;
    }
  }

  cout << ans.size() << endl;
}
