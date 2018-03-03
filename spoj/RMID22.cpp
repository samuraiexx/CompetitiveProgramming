#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    multiset<int> l, r;
    int n;
    while(cin >> n, n){
      auto rit = r.begin();
      auto lit = l.end();
      if(n == -1){ lit--,cout << *lit << endl; continue; }

      if(l.size() <= r.size()) l.insert(n);
      else r.insert(n);

      rit = r.begin();
      lit = l.end(); lit--;

      if(n == -1){ cout << *lit << endl; continue; }

      if(r.size())
        if(*rit < *lit) r.insert(*lit), l.erase(lit),
          l.insert(*rit), r.erase(rit);
    }
  }
}

