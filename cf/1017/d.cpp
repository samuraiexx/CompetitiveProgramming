#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 15;
const int L = (1 << 24);
const int P = (1 << 12);

int v[L];
int w[N];

ll ans[P][101];



int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  bitset<12> b;
  int n, m, q;
  cin >> n >> m >> q;

  for(int i = 0; i < n; i++)
    cin >> w[i];

  for(int i = 0; i < m; i++)
    cin >> b, v[b.to_ulong()]++;

  for(int i = 0; i < (1 << n); i++){
    for(int j = i; j < (1 << n); j++){

      int sum = 0;
      int x = ~(i^j);
      for(int i = 0; i < n; i++)
        if((1 << i)&x) sum += w[n - i - 1];

      if(sum > 100) continue;
      ans[i][sum] += v[j];
      if(i != j) ans[j][sum] += v[i];
    }
  }

  for(int i = 0; i < (1 << n); i++){
    for(int j = 1; j <= 100; j++)
      ans[i][j] += ans[i][j - 1];
  }

  for(int i = 0; i < q; i++){
    int t, k;
    cin >> b >> k;
    t = b.to_ulong();

    cout << ans[t][k] << '\n';
  }


}
