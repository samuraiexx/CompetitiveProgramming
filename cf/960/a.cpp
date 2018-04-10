#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  map<char, int> m;
  string s;
  cin >> s;
  for(auto c : s){
    m[c]++;
    if(m.rbegin()->st != c) return cout << "NO" << endl, 0;
  }

  if((m['c'] == m['a'] or m['c'] == m['b']) and m['a'] > 0 and m['b'] > 0)
    cout << "YES" << endl;
  else cout << "NO" << endl;
}
