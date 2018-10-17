#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 3e5 + 5;
pair<int, int> buf[N], c[N];
vector<int> ys;

vector<tuple<int, int, int>> g;

int amt[N], bg[N], ed[N];
vector<int> adj[N];

int bit[N];

void add(int x, int val){
  for(int i = x + 2; i < N; i+=i&-i)
    bit[i] += val;
}

int query(int x){
  int ans = 0;
  for(int i = x + 2; i > 0; i-=i&-i)
    ans += bit[i];
  return ans;
}

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> buf[i].st >> buf[i].nd, ys.pb(buf[i].nd);

  int m;
  cin >> m;
  for(int i = 0; i < m; i++)
    cin >> c[i].st >> c[i].nd, ys.pb(c[i].nd);

  sort(ys.begin(), ys.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());

  for(int i = 0; i < n; i++)
    g.pb({buf[i].st, lower_bound(ys.begin(), ys.end(), buf[i].nd) - ys.begin(), 0});

  for(int i = 0; i < m; i++)
    g.pb({c[i].st, lower_bound(ys.begin(), ys.end(), c[i].nd) - ys.begin(), i + 1});

  sort(g.begin(), g.end(), greater<tuple<int, int, int>>());
  for(auto tp : g){
    int x, y, t;
    tie(x, y, t) = tp;
    if(t == 0) amt[query(y)]++;
    else{
      int id = query(y);
      bg[t] = y;

      add(y + 1, id);
      ed[id] = y + 1;

      while((id = query(y)) > t){
      }
    }
  }
}
