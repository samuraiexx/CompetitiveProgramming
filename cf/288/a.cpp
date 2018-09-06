#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  int n, k;
  cin >> n >> k;
  string ans;

  if(n < k) return cout << -1 << endl, 0;
  if(k == 1)
    if(n == 1) return cout << "a\n", 0;
    else return cout << -1 << endl, 0;

  for(int i = 0; i < n - k + 2; i++)
    ans.pb(i&1 ? 'b' : 'a');
  for(int i = 0; i < k - 2; i++)
    ans.pb('a' + i + 2);
  cout << ans << endl;
}
