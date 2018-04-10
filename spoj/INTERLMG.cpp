#include<bits/stdc++.h>
using namespace std;
#define nd second
#define st first
const int N = 1e3 + 5;
bool vis[N];

struct point{
  double x, y;
  point(double x, double y):x(x), y(y){};
  point():x(0), y(0){};
  double operator!(){ return hypot(x, y); }
  point operator-(point p){ return point(x - p.x, y - p.y); }
} pts[N];

int main(){
  int n;
  while(cin >> n, n){
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < n; i++)
      cin >> pts[i].x >> pts[i].y;

    priority_queue<pair<double, int>> q;
    q.push({0, 0});
    double mx = 0;
    while(q.size()){
      auto p = q.top(); q.pop();
      if(vis[p.nd]) continue;
      vis[p.nd] = true, mx = max(mx, -p.st);
      for(int i = 0; i < n; i++)
        if(!vis[i] and i != p.nd)
          q.push({-!(pts[p.nd] - pts[i]), i});
    }

    printf("%.4lf\n", mx);
  }
}
