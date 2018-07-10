#include<bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
using namespace std;
typedef long long ll;

const ll N = 1e3 + 5;

ll mat[N][N];
ll cans[N*N], lans[N*N];

int main(){
  ll n, m, k, p;
  cin >> n >> m >> k >> p;

  priority_queue<ll> line, column;

  for(ll i = 0; i < n; i++){
    ll sum = 0;
    for(ll j = 0; j < m; j++)
      cin >> mat[i][j], sum += mat[i][j];

    line.push(sum);
  }

  for(ll j = 0; j < m; j++){
    ll sum = 0;
    for(ll i = 0; i < n; i++)
      sum += mat[i][j];

    column.push(sum);
  }

  for(ll i = 1; i <= k; i++){
    ll val = line.top();
    line.pop();
    line.push(val - m*p);

    lans[i] = lans[i - 1] + val;
  }

  for(ll i = 1; i <= k; i++){
    ll val = column.top();
    column.pop();
    column.push(val - n*p);

    cans[i] = cans[i - 1] + val;
  }

  ll ans = cans[k];
  for(int i = 0; i <= k; i++)
    ans = max(ans, cans[i] + lans[k - i] - p*i*(k - i));

  cout << ans << endl;
}
