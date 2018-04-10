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
  string s;
  cin >> n >> s;
  bool ok = 0;

  if(s[0] == '?' or s.back() == '?') ok = 1;
  for(int i = 0; i < s.size() - 1; i++)
    if(s[i] == '?' and s[i + 1] == '?') ok = 1;
  if(!ok)
    for(int i = 0; i < s.size(); i++)
      if(s[i] == '?' and s[i - 1] == s[i + 1]) ok = 1;

  for(int i = 0; i < s.size() - 1; i++)
    if(s[i] == s[i + 1] and s[i] != '?') return cout << "No" << endl, 0;

  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
