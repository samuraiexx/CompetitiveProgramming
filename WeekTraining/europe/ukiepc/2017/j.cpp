#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  map<int, double> c;
  c[0] = 2;
  for(int i = 1 ; i <= 16; i++)
    c[i] = 1/(double)i;

  int n;
  double ans = 0;
  cin >> n;
  for(int i = 0, a; i < n; i++)
    cin >> a, ans += c[a];

  printf("%.12lf\n", ans);
}
