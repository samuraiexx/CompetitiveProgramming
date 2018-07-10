#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5; 

int nor[N], flip[N];

int v[N];

int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    cin >> v[i];

  v[++n] = m;

  int prev = 0;
  bool on = true;
  for(int i = 1; i <= n; i++){
    nor[i] = (v[i] - prev)*on + nor[i - 1];
    flip[i] = (v[i] - prev)*(!on) + flip[i - 1];
    on = !on;
    prev = v[i];
  }

  int ans = nor[n];
  if(n == m) return cout << ans << endl, 0;
  for(int i = 1; i <= n; i++){
    ans = max(ans, nor[i] + flip[n] - flip[i] - 1);
  }
  cout << ans << endl;
}
