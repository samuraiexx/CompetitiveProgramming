#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " <<

typedef long long ll;
set<char> ch;

int main(){
  int n, k;
  string s;
  cin >> n >> k >> s;

  char mx  = 'a';
  for(auto c : s)
    ch.insert(c);

  string ans;

  if(k > n){
    cout << s;
    for(int i = n; i < k; i++)
      cout << *ch.begin();
    cout << endl;
    return 0;
  }

  int i;
  for(i = k - 1; i >= 0; i--){
    if(++ch.find(s[i]) != ch.end())
      { ans.pb(*(++ch.find(s[i]))); break; }
    else ans.pb(*ch.begin());
  }

  for(i = i - 1; i >= 0; i--)
    ans.pb(s[i]);

  for(int i = ans.size() - 1; i >= 0; i--)
    cout << ans[i];
  cout << endl;
}
