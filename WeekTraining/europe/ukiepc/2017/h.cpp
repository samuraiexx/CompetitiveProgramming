#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e3 + 5;
int dist[N];
int pos[N], mnd[N];
int id[N];
vector<int> ans[N];

int main(){
  int b, p, k;
  cin >> b >> p;
  for(int i = 0; i < p; i++)
    cin >> dist[i];

  cin >> k;
  for(int i = 0; i < k; i++)
    cin >> mnd[i] >> pos[i], id[i] = i, pos[i]--;

  sort(id, id + k, [](int i, int j){return pos[i] < pos[j];});

  for(int i = 0; i < k - 1; i++){
    int p1 = pos[id[i]], p2 = pos[id[i + 1]];
    int mn = max(mnd[id[i]], mnd[id[i + 1]]);

    while(p1 != p - 1 or p2 != p - 1){
      //db(p1 _ p2 _ b _ mn);
      if(p2 == p - 1) p1++, ans[i].pb(id[i]);
      else if(dist[p2 + 1] - dist[p1] <= b) p2++, ans[i].pb(id[i+1]);
      else if(dist[p2] - dist[p1 + 1] >= mn) p1++, ans[i].pb(id[i]);
      else return cout << "impossible" << endl, 0;
    }
    //db(p1 _ p2 _ b _ mn _ p);
  }

  vector<int> fans = ans[k - 2];

  for(int i = k - 3; i >= 0; i--){
    vector<int> v;
    int x = id[i + 1], p1 = 0, p2 = 0;
    while(p1 < ans[i].size() or p2 < fans.size()){
      //db(p1 _ p2 _ ans[i][p1] _ fans[p2] _ x);
      while(p1 < ans[i].size() and ans[i][p1] != x) v.pb(ans[i][p1++]);
      while(p2 < fans.size() and fans[p2] != x) v.pb(fans[p2++]);

      bool ap = 0;
      if(p1 < ans[i].size() and ans[i][p1] == x) p1++, ap = true;
      if(p2 < fans.size() and fans[p2] == x) p2++, ap = true;
      if(ap) v.pb(x);
    }

    fans = v;
  }

  for(auto a : fans) cout << a + 1 << ' ';
  cout << endl;
}
