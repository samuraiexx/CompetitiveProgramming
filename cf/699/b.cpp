#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
const int N = 1e3 + 1;

int hp[N], vp[N];
vector<pair<int, int>> bombs;

int main(){
  int n, m;
  bool ok = 1;
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
      char c;
      cin >> c;
      if(c == '*') bombs.push_back({i, j});
    }

  if(bombs.size() == 0) return cout << "YES\n1 1\n", 0;
  if(bombs.size() == 1)
    return cout << "YES\n" << bombs[0].first << ' ' << bombs[0].second << endl, 0;
  if(bombs.size() == 2)
    return cout << "YES\n" << bombs[0].first << ' ' << bombs[1].second << endl, 0;

  for(auto p : bombs) hp[p.nd]++, vp[p.st]++;
  int mxh = 0, mxv = 0;
  int vx, hx;

  for(int i = 1; i <= n; i++) if(vp[i] > mxv) mxv = vp[i], vx = i;
  for(int i = 1; i <= m; i++) if(hp[i] > mxh) mxh = hp[i], hx = i;
  
  if(mxv == 1)
    for(auto p : bombs) if(p.second != hx) vx = p.first;

  if(mxh == 1)
    for(auto p : bombs) if(p.first != vx) hx = p.second;

  for(auto p : bombs) if(p.st != vx and p.nd != hx) ok = 0;

  if(ok) cout << "YES\n" << vx << ' ' << hx << endl;
  else cout << "NO" << endl;

}
