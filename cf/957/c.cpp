#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
int e[N];

double eff(int i, int j, int k){
  return (e[k] - e[j])/(double)(e[k] - e[i]);
}

int main(){
  int n, u;
  cin >> n >> u;
  double ans = 0;
  for(int i = 0; i < n; i++)
    cin >> e[i];

  for(int i = 0; i < n - 1; i++){
    int j = i + 1;
    int k = upper_bound(e, e + n, e[i] + u) - e - 1;
    if(k == i + 1) continue;
    ans = max(ans, eff(i, j, k));
  }

  if(ans == 0) cout << -1 << endl;
  else printf("%.12lf\n", ans);
}
