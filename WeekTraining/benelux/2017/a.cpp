#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
const int N = 1e4 + 5;
const double pi = acos(-1);

int main(){
  int m, n;
  double r;
  int x1, y1, x2, y2;
  cin >> m >> n >> r;
  cin >> x1 >> y1 >> x2 >> y2;

  double ans = 1e18;
  for(int i = min(y1, y2); i >= 0; i--){
    double tmp = 0;
    tmp = pi*i*r/(double)n*(abs(x1 - x2)/(double)m);
    tmp += abs(y1 - i)*r/(double)n;
    tmp += abs(y2 - i)*r/(double)n;
    ans = min(ans, tmp);
  }


  printf("%.12lf\n", ans);
}
