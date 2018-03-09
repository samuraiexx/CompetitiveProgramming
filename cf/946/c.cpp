#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 

int main(){
  string s;

  cin >> s;
  if(s.size() < 26) return cout << -1 << endl, 0;

  char c = 'a';

  for(int i = 0; i < s.size() and c <= 'z'; i++)
    if(s[i] <= c) s[i] = c++;

  if(c == 'z' + 1) cout << s << endl;
  else cout << -1 << endl;

  return 0;
}

