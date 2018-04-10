#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  ll h, m;
  ll h0, d, c, n;
  cin >> h >> m;
  cin >> h0 >> d >> c >> n;

  m += h*60;
  ll amt = max(0ll, 20*60 - m)*d;
  
  printf("%.12lf\n", min((double)((h0 + n - 1)/n*c), (double)(((h0 + amt) + n - 1)/n*c)*0.8));
}
