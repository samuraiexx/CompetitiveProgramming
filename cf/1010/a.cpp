#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e3 + 5;
const double EPS = 1e-9;
double a[N], b[N];
int n, m;

bool fuel(double sum){
  sum -= (m + sum)/a[0];

  for(int i = 1; i < n and sum > -EPS; i++){
    sum -= (m + sum)/b[i];
    if(sum < -EPS) return false;
    sum -= (m + sum)/a[i];
  }

  sum -= (m + sum)/b[0];

  return sum > -EPS;
}

int main(){
  cin >> n >> m;

  for(int i = 0; i < n; i++)
    cin >> a[i];

  for(int i = 0; i < n; i++)
    cin >> b[i];

  double i = 0, j = 1e9 + 1;

  for(int k = 0; k < 200; k++){
    double mid = (i + j)/2;
    if(fuel(mid)) j = mid;
    else i = mid;
  }
  if(i > 1e9 + EPS) cout << -1 << endl;
  else printf("%.6lf\n", i);
}
