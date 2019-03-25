#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  if(k*(k -1) < n) return cout << "NO\n", 0;
  cout << "YES\n";

  for(int i = 1; i < k; i++){
    for(int j = 1; j <= k; j++){
      cout << j << ' ' << (i + j - 1)%k + 1 << '\n';
      n--;
      if(n == 0) return 0;
    }
  }
}
