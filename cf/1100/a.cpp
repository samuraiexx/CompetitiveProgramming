#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 105;
int v[N], ans[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int n, k, s = 0;
  cin >> n >> k;

  for(int i = 0; i < n; i++)
    cin >> v[i], s += v[i], ans[i%k] += v[i];

  int tans = 0;
  for(int i = 0; i < k; i++)
    tans = max(tans, abs(s - ans[i]));

  cout << tans << '\n';
}
