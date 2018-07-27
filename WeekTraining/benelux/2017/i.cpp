#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
const int N = 105;
int c[N][N][2];
bool vis[N][N][2];

int dp(int n, int m, bool b){
  if(n == 0) return 0;
  if(vis[n][m][b]) return c[n][m][b];

  int mx = -1e9;
  int z = (n%2);
  if(!b) z = -z;
  for(int i = 1; i <= m; i++)
    mx = max(mx, (i%2)*z - dp(m - i, n, (b + n + m)%2));

  vis[n][m][b] = true;
  return c[n][m][b] = mx;
}

int main(){
  int p, q;
  cin >> p >> q;

  cout << dp(p, q, true) << endl;
}
