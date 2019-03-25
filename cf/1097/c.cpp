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
  int n;
  cin >> n;

  map<int, int> m;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    int sum = 0;
    int mn = 0;
    for(auto c : s) {
      if(c == '(') sum++;
      else sum--;
      mn = min(sum, mn);
    }
    if(mn >= 0 or mn == sum) m[sum]++;
  }

  int ans = m[0]/2;
  for(auto p : m){
    if(p.st >= 0) break;
    ans += min(p.nd, m[-p.st]);
  }

  cout << ans << endl;
}
