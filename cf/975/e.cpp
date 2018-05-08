#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
typedef long double ld;
const int N = 1e4 + 5;
const ld pi = acos(-1);
int n, q;

struct pnt{
  ld x, y;
  pnt(ld x, ld y):x(x), y(y){}
  pnt():x(0), y(0){}
  pnt operator+(pnt b){ return pnt(x + b.x, y + b.y); }
  pnt operator-(pnt b){ return pnt(x - b.x, y - b.y); }
  pnt operator/(ld k){ return pnt(x/k, y/k); }
  pnt operator*(ld k){ return pnt(x*k, y*k); }
  ld operator!(){ return hypot(x, y); }
  ld operator%(pnt b){ return x*b.y - y*b.x; }
  ld operator*(pnt b){ return x*b.x + y*b.y; }
  pnt rot(ld w){ return pnt(x*cos(w) - y*sin(w), x*sin(w) + y*cos(w)); }
  pnt rot(ld cosx, ld sinx){ return pnt(x*cosx - y*sinx, x*sinx + y*cosx); }
} r[N];

pnt calcG(){
  ld s = 0;
  pnt ans;
  for(int i = 0; i < n; i++){
    int j = (i + 1)%n;
    ans = ans + (r[i] + r[j])*(r[i].x*r[j].y - r[i].y*r[j].x);
    s = s + (r[i].x*r[j].y - r[i].y*r[j].x);
  }

  return ans/(3*s);
}

int main(){
  int f1 = 0, f2 = 1;
  cin >> n >> q;
  for(int i = 0; i < n; i++){
    cin >> r[i].x >> r[i].y;
    //db(r[i].x _ r[i].y);
  }

  pnt g = calcG();
  ld sint = 0;
  ld cost = 1;

  for(int i = 0; i < n; i++) r[i] = r[i] - g;// db(r[i].x _ r[i].y);

  for(int i = 0; i < q; i++){
    int t;
    cin >> t;
    if(t == 1){
      int v, u;
      cin >> v >> u, v--, u--;

      if(f1 == v) swap(f1, f2);
      f2 = u;

      pnt ref = r[f1].rot(cost, sint);

      pnt dg = pnt(0, 0) - ref;
      pnt dgr = pnt(0, 0) - r[f1]; //delta g relativo

      pnt down(0, -1);
      ld nsin = dg%down/!dg;
      ld ncos = dg*down/!dg;

      sint = dgr%down/!dgr, cost = dgr*down/!dr;

      pnt rtd = dg.rot(ncos, nsin) - dg;
      g = rtd + g;
      //db(r[f1].x _ r[f1].y);
      //db(g.x _ g.y);
    }else{
      int v;
      cin >> v, v--;
      pnt ans = r[v].rot(cost, sint) + g;
      printf("%.12Lf %.12Lf\n", ans.x, ans.y);
    }
  }
}
