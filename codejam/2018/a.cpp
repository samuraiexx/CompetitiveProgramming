#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int dmg(string &s){
  int x = 1;
  int tt = 0;
  for(auto c : s)
    if(c == 'C') x *= 2;
    else tt += x;
  return tt;
}

bool next(string &s){
  bool ret = false;
  for(int i = 0; i < s.size() - 1; i++)
    if(s[i] == 'C' and s[i + 1] == 'S'){
      ret = true;
      swap(s[i], s[i + 1]);
      break;
    }
  return ret;
}

int main(){
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    int d;
    string s;
    cin >> d >> s;

    int ans = 0;
    bool ne = true;
    while(dmg(s) > d and ne){
      ans++;
      ne = next(s);
    }
    cout << "Case #" << t << ": ";
    if(ne) cout << ans << endl;
    else cout << "IMPOSSIBLE" << endl;
  }
}
