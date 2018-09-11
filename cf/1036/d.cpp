#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 3e5 + 15;
ll v[N], u[N];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int n, m;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> v[i];

  cin >> m;
  for(int i = 0; i < m; i++)
    cin >> u[i];

  int j = 0, i = 0;
  int amt = 0;
  for(; i < n and j < m; i++, j++){
    while(v[i] != u[j] and i < n and j < m){
      if(v[i] > u[j])
        u[j + 1] += u[j], j++, amt++;
      if(v[i] < u[j])
        v[i + 1] += v[i], i++;
    }
  }

  if(i != n or j != m)
    cout << -1 << '\n';
  else cout << m - amt << '\n';
}
