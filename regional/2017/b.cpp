#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
set<char> vog;

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  string s;
  vog.insert('a');
  vog.insert('e');
  vog.insert('i');
  vog.insert('o');
  vog.insert('u');

  cin >> s;

  int i = -1, j = s.size();

  int cnt = 0;
  for(auto c : s) if(vog.count(c)) cnt++;
  if(!cnt) return cout << 1 << endl, 0;
  if(!vog.count(s[0])) return cout << 0 << endl, 0;

  bool l = 1;
  while(i <= j){
    int p;
    int dir;
    if(l) p = i + 1, dir = 1;
    else p = j - 1, dir = -1;

    while(!vog.count(s[p])) p += dir;//, db(p _ s[p]);

    //db(i _ j _ p);

    if(l)
      if(p == j) return cout << j - i << endl, 0;
      else i = p;
    else
      if(p == i) return cout << j - i << endl, 0;
      else j = p;
    l = !l;
  }
  return 0;
}
