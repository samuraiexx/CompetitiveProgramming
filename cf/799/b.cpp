#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e5 + 5;

map<pair<int, int>, int> v[3];
int p[N], c1[N], c2[N];

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> p[i];

  for(int i = 0; i < n; i++)
    cin >> c1[i];

  for(int i = 0; i < n; i++)
    cin >> c2[i];

  for(int i = 0; i < n; i++){
    v[c1[i] - 1][{p[i], c2[i] - 1}]++;
    v[c2[i] - 1][{p[i], c1[i] - 1}]++;
  }

  int m;
  cin >> m;

  while(m--){
    int c;
    cin >> c;
    c--;

    if(v[c].size()){
      auto p = v[c].begin()->first;
      cout << p.first << ' ';

      v[c][p]--;
      if(v[c][p] == 0) v[c].erase(p);

      pair<int, int> p2 = {p.first, c};
      v[p.second][p2]--;
      if(v[p.second][p2] == 0) v[p.second].erase(p2);
    }
    else cout << -1 << ' ';
  }
  cout << '\n';

}
