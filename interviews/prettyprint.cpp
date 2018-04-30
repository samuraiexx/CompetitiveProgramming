#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > prettyPrint(int A) {
  int n = 2*A - 1;
  vector<vector<int>> m(n);
  for(auto v : m) v.resize(n);
  cout << n << endl;;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cout << m.size() << ' ' << m[i].size() << endl, m[i][j] = max(abs(n/2 - i), abs(n/2 - j)) + 1;

  return m;
}


int main(){
  auto m = prettyPrint(3);
  for(auto v : m){
    for(auto x : v)
      cout << x << ' ';
    cout << endl;
  }
}
