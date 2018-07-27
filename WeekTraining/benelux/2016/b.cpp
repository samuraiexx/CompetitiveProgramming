#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 

int main(){
  string s, ans = "";
  cin >> s;
  for(ll i = 0; i < s.size(); i++){
    if(i < (int)s.size() - 2 and s[i] !=  s[i + 1] and
                            s[i + 1] != s[i + 2] and
                            s[i] != s[i + 2]){
      i = i + 2;
      ans.pb('C');
      continue;
    }

    if(s[i] == 'R') ans.pb('S');
    else if(s[i] == 'B') ans.pb('K');
    else if(s[i] == 'L') ans.pb('H');
  }

  cout << ans << endl;
}
