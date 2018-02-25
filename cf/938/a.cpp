#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define st first
#define nd second

int main(){
  set<char> v;
  v.insert('a');
  v.insert('e');
  v.insert('i');
  v.insert('o');
  v.insert('u');
  v.insert('y');

  int n;
  string s;
  string ans;
  cin >> n >> s;
  for(int i = 0; i < n; i++){
    if(ans.size() and v.count(ans.back()) and v.count(s[i])) continue;
    else ans.pb(s[i]);
  }
  cout << ans << endl;
}
