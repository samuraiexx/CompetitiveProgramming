#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

ll stoix(string s, ll i){
  for(auto &c : s)
    if(c == '?') c = '0' + i;

  return stoll(s);
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  ll t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;

    string a, b, x;

    set<int> st;

    char op = 0;
    bool eq = false;
    for(auto c : s){
      if(c == '=') eq = true;
      else if(eq) x.pb(c);
      else if(!op and a.size() and (c == '*' or c == '-' or c == '+'))
        op = c;
      else if(op) b.pb(c);
      else a.pb(c);

      if(c >= '0' and c <= '9') st.insert(c - '0');
    }

    ll ans = -1;
    for(ll i = 9; i >= 0; i--){
      if(st.count(i)) continue;
      if(i == 0 and ((a[0] == '?' and a.size() > 1) or
                     (b[0] == '?' and b.size() > 1) or
                     (x[0] == '?' and x.size() > 1))) continue;
      ll ax, bx, xx;

      ax = stoix(a, i);
      bx = stoix(b, i);
      xx = stoix(x, i);

      if(op == '*' and ax*bx == xx) ans = i;
      if(op == '-' and ax-bx == xx) ans = i;
      if(op == '+' and ax+bx == xx) ans = i;
    }

    cout << ans << '\n';
  }
}
