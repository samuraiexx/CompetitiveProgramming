#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  string s;
  cin >> s;

  int cnt = 0;
  for(auto c : s)
    if(c == '1') cnt++;

  string ans;
  s.push_back('2');
  bool fz = false;
  for(auto c : s){
    if(c == '2' and !fz){
      fz = true;
      while(cnt--)
        ans.pb('1');
    }

    if(c != '1') ans.pb(c);
  }

  ans.pop_back();
  cout << ans << endl;
}
