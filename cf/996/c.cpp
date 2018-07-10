#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 50 + 5;
int m[6][N];
int n, k;

pair<int, int> pos(int i){
  return {2 + (i - 1)/n, i <= n ? i : n - (i - 1)%n};
}

int main(){
  vector<string> ans;
  int cnt = 0;

  cin >> n >> k;
  for(int i = 1; i <= 4; i++)
    for(int j = 1; j <= n; j++)
      cin >> m[i][j];

  if(k == 2*n){
    bool ok = false;
    for(int i = 1; i <= n; i++){
      if(m[1][i] == m[2][i]){
        ans.push_back(to_string(m[1][i]) + " 1 " +  to_string(i)), m[2][i] = 0, cnt++;
        ok = true;
      }
      if(m[4][i] == m[3][i]){
        ans.push_back(to_string(m[4][i]) + " 4 " +  to_string(i)), m[3][i] = 0, cnt++;
        ok = true;
      }
    }

    if(!ok)
      return cout << -1 << endl, 0;
  }

  int lst;
  for(int i = 1; i <= 2*n; i++){
    auto p = pos(i);
    if(m[p.st][p.nd] == 0){
      lst = i;
      break;
    }
  }

  while(cnt < k){
    int nxt = (lst)%(2*n) + 1;
    auto p = pos(nxt);
    auto pl = pos(lst);

    int x = m[p.st][p.nd];

    if(x != 0){
      int nb = p.st - (p.st == 2) + (p.st == 3);
      if(m[nb][p.nd] == x)
        ans.push_back(to_string(x) + ' ' + to_string(nb) + ' ' + to_string(p.nd)), cnt++;
      else
        ans.push_back(to_string(x) + ' ' + to_string(pl.st) + ' ' + to_string(pl.nd)), 
        m[pl.st][pl.nd] = x;

      m[p.st][p.nd] = 0;
    }

    lst = nxt;
  }

  cout << ans.size() << endl;
  for(auto s : ans)
    cout << s << endl;
}
