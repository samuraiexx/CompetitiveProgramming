#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
const int N = 1e5 + 5;
typedef long long ll;
int a[N], b[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int mxa = 0, mxb = 0;
  int fa = -1, la;
  for(int i = 0; i < n; i++) cin >> a[i], mxa = max(mxa, a[i]);
  for(int i = 0; i < m; i++) cin >> b[i], mxb = max(mxb, b[i]);

  int sa = 0, sb = 0;

  for(int i = 0; i < n; i++){
    sa += a[i];
    if(mxa == a[i]){
      if(fa == -1) fa = i;
      la = i;
    }
  }

  for(int i = 0; i < m; i++) sb += b[i];

  sa += mxa*(m - 1);
  sb += b[0]*(fa) + mxb*(la - fa) + b[m - 1]*(n - la - 1);

  ll ans = (1e9)*sa + sb;
  cout << ans << endl;
}
