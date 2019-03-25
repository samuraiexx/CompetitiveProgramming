#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
ll v[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> v[i];
  sort(v, v + n);

  pair<int, int> ans;
  int j = 0;
  ll c = 0;
  for(int i = 0; i < n; i++){
    if(i > 0) c += (i - j)*(v[i] - v[i - 1]);
    
    while(j < i and c > k) c -= v[i] - v[j], j++;
    pair<int, int> val = {i - j + 1, -v[i]};
    ans = max(ans, val);
  }

  cout << ans.st << ' ' << -ans.nd << endl;
}
