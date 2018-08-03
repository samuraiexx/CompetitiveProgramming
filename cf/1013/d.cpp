#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e5 + 5;

int par[N], sz[N];
int cnt[N];

bool vx[N];
bool vy[N];

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite(int a, int b) {
  if ((a = find(a)) == (b = find(b))) return;
  if (sz[a] < sz[b]) swap(a, b);
  par[b] = a; sz[a] += sz[b];
}

struct point{
  int yi, yf;
  int id;
  bool operator<(const point p) const{
    if(yi != p.yi) return yi < p.yi;
    return id != p.id ? id < p.id : yf < p.yf;
  }
};

int main(){
  for(int i = 0; i < N; i++)
    par[i] = i, sz[i] = 1;

  int n, m, q;

  set<point> s;
  cin >> n >> m >> q;

  for(int i = 0; i < q; i++){
    int x, y;
    cin >> x >> y;
    s.insert({y, y, x});

    vx[x] = true;
    vy[y] = true;
  }

  auto it = s.begin();
  auto it2 = it;
  it2++;
  while(it2 != s.end()){
    while(it->yf >= it2->yi and it2 != s.end()){
      unite(it->id, it2->id);

      int yi = it->yi;
      int yf = max(it->yf, it2->yf);
      int id = find(it->id);

      s.erase(it2);
      s.erase(it);
      it = s.insert({yi, yf, id}).first;
      it2 = it;
      it2++;
    }

    it++;
    it2 = it;
    if(it != s.end())
      it2++;
  }

  for(auto x : s){
    cnt[find(x.id)] += x.yf - x.yi + 1;
  }

  int ans = 0;
  for(int i = 1; i <= n; i++){
    if(!vx[i]) ans++;
  }

  for(int i = 1; i <= m; i++){
    if(!vy[i]) ans++;
    if(cnt[i]) ans++;
  }
  ans--;

  cout << ans << endl;
}
