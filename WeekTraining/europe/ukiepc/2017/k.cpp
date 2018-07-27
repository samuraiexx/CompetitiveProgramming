#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

const int N = 105, INF = 1e9;
vector<int> ans[N];

int main(){
  int n, m;
  cin >> n;
  set<pair<int, pair<int, int>>> dw;
  set<pair<int, int>> bld;

  for(int i = 0; i < n; i++){
    int w, l;
    cin >> w >> l;
    dw.insert({-l, {-w, i + 1}});
  }
  
  cin >> m;
  for(int i = 0; i < m; i++){
    int w;
    cin >> w;
    bld.insert({-w, i + 1});
  }

  while(bld.size()){

    auto it = bld.begin();
    auto g = dw.begin();
    for(auto it2 = dw.begin(); it2 != dw.end(); it2++)
      if(-it2->st >= -it->st and -it2->nd.st < -g->nd.st) g = it2;
    
    //db(g->st _ g->nd.st _ g->nd.nd);
    //db(it->st _ it->nd);

    if(dw.empty() or -it->st > -g->st) return cout << "impossible" << endl, 0;

    ans[it->nd].pb(g->nd.nd);
    if(g->nd.st) bld.insert({g->nd.st, it->nd});

    bld.erase(it);
    dw.erase(g);
  }

  for(int i = 1; i <= m; i++){
    for(int j = ans[i].size() - 1; j >= 0; j--)
      cout << ans[i][j] << " \n"[j == 0];
  }

}
