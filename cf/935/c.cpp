#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl;
#define _ << ", " <<;

double dist(pair<double, double> p1, pair<double, double> p2){
  return sqrt((p1.st - p2.st)*(p1.st - p2.st) + 
              (p1.nd - p2.nd)*(p1.nd - p2.nd));
}

int main(){
  double R;
  pair<double, double> p1, p2;
  cin >> R >> p1.st >> p1.nd >> p2.st >> p2.nd;

  if(dist(p1, p2) >= R) return printf("%.12lf %.12lf %.12lf\n", p1.st, p1.nd, R), 0;

  double r = (R + dist(p1, p2))/2.0;

  if(dist(p1, p2) < 1e-8)
    return printf("%.12lf %.12lf %.12lf\n", p1.st + r, p1.nd, r), 0;
  double dx = (p1.st - p2.st)*r/dist(p1, p2);
  double dy = (p1.nd - p2.nd)*r/dist(p1, p2);
  printf("%.12lf %.12lf %.12lf\n", p2.st + dx, p2.nd + dy, r);
}
