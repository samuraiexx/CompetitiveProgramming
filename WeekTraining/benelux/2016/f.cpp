#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
const int N = 105;
const ld INF = 1e9;
ld EPS = 1e-8;

struct point{
  ld x, y;
  point(ld x, ld y):x(x), y(y){};
  point(){};
  point operator-(point p) { return point(x - p.x, y - p.y); }
  ld operator%(point p) { return x*p.y - y*p.x; }
  point operator/(ld v) { return point(x/v, y/v); }
} org;

point lines_intersect(point p, point q, point a, point b) {
  point r = q-p, s = b-a, c(p%q, a%b);
  if (abs(r%s) < EPS) return point(INF, INF);
  return point(point(r.x, s.x) % c, point(r.y, s.y) % c) / (r%s);
}

struct cmp{
  bool operator()(pair<point, int> p1, pair<point, int> p2){
    return (p1.st - org)%(p2.st - org) < EPS;
  }
};

string names[N];
vector<pair<point, int>> interc[N];
vector<int> st;
pair<point, point> lines[N];

int main(){
  int r, n, x, y;
  cin >> r >> n >> x >> y;
  org.x = x, org.y = y;
  for(int i = 0; i < r; i++){
    string s;
    point p1, p2;
    cin >> s >> p1.x >> p1.y >> p2.x >> p2.y;
    lines[i] = make_pair(p1, p2);
    names[i] = s;
  }


  for(int i = 0; i < r; i++)
    for(int j = i + 1; j < r; j++){
      point p = lines_intersect(lines[i].st, lines[i].nd, lines[j].st, lines[j].nd);
      if(abs(p.x - INF) < EPS) continue;
      interc[i].pb({p, j}), interc[j].pb({p, i});
    }

  int start;
  for(int i = 0; i < r; i++)
    if(abs((org - lines[i].st)%(lines[i].nd - lines[i].st)) < EPS) { start = i; break; }

  auto org2 = org;

  org.y--;

  sort(interc[start].begin(), interc[start].end(), cmp());

  auto k = lower_bound(interc[start].begin(), interc[start].end(), make_pair(org2, -1), cmp());
  if(k == interc[start].end()) return cout << names[start] << endl, 0;

  st.pb(start);

  org.y++;

  for(int i = 0; i < r; i++)
    if(i != start) sort(interc[i].begin(), interc[i].end(), cmp());

  /*for(int i = 0; i < r; i++){
    db(names[i]);
    for(auto p : interc[i]) db(p.st.x _ p.st.y);
  }*/

  bool finite = 0;
  int i = k->nd;

  while(i != start){
    st.pb(i);
    k = lower_bound(interc[i].begin(), interc[i].end(), make_pair(k->st, (int)INF), cmp());
    if(k == interc[i].end()) { finite = true; break; }
    i = k->nd;
  }
  if(finite) cout << names[st[ n < st.size() ? n : st.size() - 1]] << endl;
  else cout << names[st[n%st.size()]] << endl;
}
