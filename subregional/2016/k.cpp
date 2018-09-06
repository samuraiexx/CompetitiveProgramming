#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n;

struct Point{
  ll x, y;
  Point(ll x = 0, ll y = 0):x(x), y(y){}
  Point operator+(Point p){ return Point(x + p.x, y + p.y); }
  Point operator-(Point p){ return Point(x - p.x, y - p.y); }
  Point operator*(ll k){ return Point(x*k, y*k); }
  Point operator/(ll k){ return Point(x/k, y/k); }
  ll operator%(Point p){ return x*p.y - y*p.x; }
  int dir(Point p1, Point p2){ 
    ll vp = (p1 - *this)%(p2 - *this);
    if(vp == 0) return 0;
    else if(vp > 0) return 1;
    else return -1;
  }
}pnt[N], pnta[N], pntb[N];

Point a, b;

ll dp[N][4][4];

ll area(Point a, Point b, Point c){
  return abs((b - a)%(c - a));
}

void dpf(Point org){
  int dir[] = { org.dir(pnta[1], pnta[2]),
                org.dir(pntb[1], pnta[2]),
                org.dir(pnta[1], pntb[2]), 
                org.dir(pntb[1], pntb[2]) };

    dp[2][0][0] = area(org, pnta[1], pnta[2]);
    dp[2][1][1] = area(org, pntb[1], pnta[2]);
    dp[2][2][2] = area(org, pnta[1], pntb[2]);
    dp[2][3][3] = area(org, pntb[1], pntb[2]);

  for(int i = 3; i < n; i++){
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 2; k++){
        for(int t = 0; t < 4; t++){
          Point p0 = (k&1 ? pntb[i - 2] : pnta[i - 2]);
          Point p1 = (j&1 ? pntb[i - 1] : pnta[i - 1]);
          Point p2 = (j&2 ? pntb[i] : pnta[i]);

          Point a = (t&1 ? pntb[1] : pnta[1]);
          Point b = (t&2 ? pntb[2] : pnta[2]);

          int dir = p0.dir(p1, p2);
          if(dir != org.dir(p1, p2) or 
              dir != org.dir(a, p2)) continue;

          dp[i][j][t] = min(dp[i][j][t],
              dp[i - 1][(j&1)*2 + k][t] + area(org, p1, p2));
        }
      }
    }
  }
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> pnt[i].x >> pnt[i].y;
    pnt[i] = pnt[i]*2;
  }

  cin >> a.x >> a.y >> b.x >> b.y;
  a = a*2, b = b*2;

  for(int i = 0; i < n; i++){
    pnta[i] = (pnt[i] + a)/2;
    pntb[i] = (pnt[i] + b)/2;
  }

  memset(dp, 0x3f, sizeof dp);
  dpf(pnta[0]);

  ll ans = 0x3f3f3f3f3f3f3f3f;
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++) if(dp[n - 1][i][j] > 0)
      ans = min(ans, dp[n - 1][i][j]);

  memset(dp, 0x3f, sizeof dp);
  dpf(pntb[0]);

  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++) if(dp[n - 1][i][j] > 0)
      ans = min(ans, dp[n - 1][i][j]);

  double dans = ans/(double)8;
  printf("%.3lf\n", dans);
}
