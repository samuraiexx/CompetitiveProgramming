#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  double k, p, x;
  scanf("%lf %lf %lf", &k, &p, &x);

  double m = sqrt(k*p/x);
  ll m1 = (ll)m;
  ll m2 = (ll)(m + 1);
  printf("%.3lf\n", min(k*p/(double)m1 + m1*x, k*p/(double)m2 + m2*x));
}
