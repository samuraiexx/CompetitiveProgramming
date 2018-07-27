#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  int n;
  cin >> n;

  string s1, s2;
  cin >> s1 >> s2;

  int ans = 0;
  for(int i = 0; i < n/2; i++){
    map<char, int> m;
    char c1 = s1[i], c2 = s1[n - i - 1];
    char c3 = s2[i], c4 = s2[n - i - 1];

    m[c1]++, m[c2]++;
    m[c3]++, m[c4]++;

    int mx = 0;
    int mn = 5;
    for(auto p : m)
      mx = max(mx, p.nd), mn = min(mn, p.nd);

    if(mx == 3){
      ans++;
    }
    else if(mx == 1) {
      ans += 2;
    }
    else if(mx == 2 and mn == 1){
      if(c1 == c2) ans += 2;
      else ans += 1;
    }
  }

  if(n%2 == 1 and s1[n/2] != s2[n/2])
    ans++;

  cout << ans << endl;
}
