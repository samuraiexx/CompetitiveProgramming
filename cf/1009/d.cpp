#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N  = 1e5 + 5;
bool sieve[N];

int main(){
  for(int i = 2; i < N; i++)
    if(!sieve[i])
      for(int j = 2*i; j < N; j+=i)
        sieve[j] = true;

  int n, m;
  cin >> n >> m;

  if(n > m + 1) return cout << "Impossible" << endl, 0;

  if(n > 1e3){
    cout << "Possible" << endl;
    for(int i = 2; i <= n and m > 0; i++)
      m--, cout << 1 << ' ' << i << '\n';

    for(int i = 2; i <= n and m > 0; i++)
      if(!sieve[i]){
        for(int j = 2; j < i and m; j++)
          cout << i << ' ' << j << '\n', m--;
      }
  }else{
    vector<pair<int, int>> ans;
    for(int i = 1; i < n; i++)
      for(int j = i + 1; j <= n; j++){
        if(__gcd(i, j) == 1)
          ans.push_back({i, j});
      }

    if(ans.size() < m) return cout << "Impossible" << endl, 0;
    cout << "Possible" << endl;
    for(int i = 0; i < m; i++)
      cout << ans[i].st << ' ' << ans[i].nd << '\n';
  }
}
