#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
int v[N];

int main(){
  int n, k;
  cin >> n >> k;

  int gcd = k;
  for(int i = 0; i < n; i++){
    cin >> v[i], v[i] %= k;
    if(v[i] > 0) gcd = __gcd(gcd, v[i]);
  }
  if(gcd == k) return cout << "1\n0\n", 0;

  vector<int> ans;
  for(int i = 0; i < k; i += gcd)
    ans.push_back(i);

  cout << ans.size() << endl;
  for(auto x : ans)
    cout << x << ' ';
  cout << endl;

}
