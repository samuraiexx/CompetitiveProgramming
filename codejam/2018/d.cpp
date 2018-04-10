#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<  
typedef long long ll;
const double EPS = 1e-10;
const double pi = acos(-1);
const double sr2 = sqrt(2);

int dx[] = { 1,  1, -1, -1, 1,  1, -1, -1};
int dy[] = {-1, -1, -1, -1, 1,  1,  1,  1};
int dz[] = { 1, -1,  1, -1, 1, -1,  1, -1};
int t;

struct point{
  double x, y;

  point() : x(0), y(0) {}
  point(double x, double y) : x(x), y(y) {}

  point operator -() { return point(-x, -y); }
  point operator +(point p) { return point(x+p.x, y+p.y); }
  point operator -(point p) { return point(x-p.x, y-p.y); }

  point operator *(double k) { return point(k*x, k*y); }
  point operator /(double k) { return point(x/k, y/k); }

  double operator *(point p) { return x*p.x + y*p.y; }
  double operator %(point p) { return x*p.y - y*p.x; }
} origin;

bool radial(point p1, point p2){
  p1 = p1 - origin, p2 = p2 - origin;
  double x = p1%p2;
  if(abs(x) < EPS) return p1*p1 < p2*p2;
  else return x > 0;
}

struct point3{
  double x, y, z;
  point3(double x, double y, double z):x(x), y(y), z(z){}
  point3() : x(0), y(0), z(0) {}
  point3 operator -() { return point3(-x, -y, -z); }
  double operator !() { return sqrt((*this)*(*this)); }
  point3 operator +(point3 p) { return point3(x+p.x, y+p.y, z+p.z); }
  point3 operator -(point3 p) { return point3(x-p.x, y-p.y, z-p.z); }

  point3 operator *(double k) { return point3(k*x, k*y, k*z); }
  point3 operator /(double k) { return point3(x/k, y/k, z/k); }

  double operator *(point3 p) { return x*p.x + y*p.y + z*p.z; }
  point3 operator %(point3 p) {
    return point3(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);
  }

  void rot(point3 k, double teta){
    point3 &v = *this;
    v = v*cos(teta) + (k%v)*sin(teta) + k*(k*v)*(1-cos(teta));
  }
};

double area(point3 p1, point3 p2, point3 p3){
  vector<point> pts;
  for(int i = 0; i < 8; i++){
    point3 p = p1*dx[i] + p2*dy[i] + p3*dz[i];
    pts.pb({p.x, p.z});
  }

  vector<point> ch(pts.size());
  point mn = pts[0];

  for(point p : pts) if(p.y < mn.y or (abs(p.y - mn.y) < EPS and p.x < mn.x)) mn = p;

  origin = mn;
  sort(pts.begin(), pts.end(), radial);

  int n = 0;

  for(point p : pts) {
    while (n > 1 and (p - ch[n-2])%(ch[n-1] - ch[n-2]) > -EPS) n--;
    ch[n++] = p;
  }
  ch.resize(n);

  for(auto p : ch)
    cout << p.x << ' ' << p.y << endl;
  cout << endl;

  double s = 0;
  for(int i = 0; i <= n; i++)
    s += ch[i]%ch[(i+1)%n];

  return abs(s/2);
}

double func(point3 p1, point3 p2, point3 p3, double teta){
  point3 k = {sr2/2, 0, sr2/2};
  p1.rot(k, teta);
  p2.rot(k, teta);
  p3.rot(k, teta);

  return area(p1, p2, p3);
}

void solve(double a){
  point3 p1 = {0.5, 0, 0};
  point3 p2 = {0, 0.5, 0};
  point3 p3 = {0, 0, 0.5};
  double i = 0, j = atan2(sr2, 1);
  
  /*
  for(int i = 0; i < 42; i++){
    auto s = func(p1, p2, p3, i*pi/18.0);
    cout << i*10 << ' ' <<  s << endl;
  }
  */

  for(int k = 0; k < 100; k++){
    double mid = (i + j)/2.0;
    if(func(p1, p2, p3, mid) < a) i = mid;
    else j = mid;
  }

  point3 k = {sr2/2, 0, sr2/2};
  p1.rot(k, i);
  p2.rot(k, i);
  p3.rot(k, i);

  if(abs(!p1 - 0.5) > EPS) db("ERRO");
  if(abs(!p2 - 0.5) > EPS) db("ERRO");
  if(abs(!p3 - 0.5) > EPS) db("ERRO");
  cout << endl;
  if(abs(abs(atan2(!(p1%p2), p1*p2)) - pi/2) > EPS) db("ERRO2");
  if(abs(abs(atan2(!(p3%p2), p3*p2)) - pi/2) > EPS) db("ERRO2");
  if(abs(abs(atan2(!(p1%p3), p1*p3)) - pi/2) > EPS) db("ERRO2");
  cout << endl;
  if(abs(a - area(p1, p2, p3)) > EPS) db("ERROR3");

  printf("Case #%d:\n", t);
  printf("%.12lf %.12lf %.12lf\n", p1.x, p1.y, p1.z);
  printf("%.12lf %.12lf %.12lf\n", p2.x, p2.y, p2.z);
  printf("%.12lf %.12lf %.12lf\n", p3.x, p3.y, p3.z);
}

int main(){
  int T;
  cin >> T;
  for(t = 1; t <= T; t++){
    double a;
    cin >> a;
    solve(a);
  }
}
