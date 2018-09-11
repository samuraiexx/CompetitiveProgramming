#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e3 + 5;
int s[2][N], ps1[N], ps2[N];
int tmp[2][N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  
  int t;
  cin >> t;
  while(t--){
    memset(s, 0, sizeof s);
    memset(ps1, 0, sizeof ps1);
    memset(ps2, 0, sizeof ps2);
    memset(tmp, 0, sizeof tmp);
    int n;
    cin >> n;
    bool sev = false, ok = true;
    int st = -1;
    bool p = 0;

    for(int i = 1; i <= n; i++){
      int x;
      cin >> x;

      if(x == 0) p ^= 1;
      s[p][i] = x + s[p][i - 1];
      s[p^1][i] = s[p^1][i - 1];

      ps1[i] = ps1[i - 1] + (x == 1);
      tmp[p][i] = 7*(x == 1);

      if(i >= st and st != -1) ps2[i] = ps2[i - 1] + x;
      if(ps1[i] == 15 and st == -1) st = i + 2;
      if(sev && x == 7) ok = false;
      if(x) sev = (x == 7);
    }

    if(!ok) { cout << n << '\n'; continue; }

    for(int i = 1; i <= n; i++){
      int x0 = 8*(ps1[n] - ps1[i]) + ps2[n] - ps2[i] + tmp[0][i];
      int x1 = 8*(ps1[n] - ps1[i]) + ps2[n] - ps2[i] + tmp[1][i];
      if(s[0][i] - s[1][i] > x1 or 
         s[1][i] - s[0][i] > x0){ cout << i << '\n'; break;}
    }
  }
}
