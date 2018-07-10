#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 5e3 + 5;
ll a[N];

int main(){
  int n, k;
  cin >> n >> k;
  for(int i = 1; i <= n; i++)
    cin >> a[i], a[i] += a[i - 1];

  double ans = 0;
  for(int i = 1; i <= n; i++)
    for(int j = i + k - 1; j <= n; j++)
      ans = max(ans, (a[j] - a[i - 1])/(double)(j - i + 1));

  printf("%.12lf\n", ans);
}
