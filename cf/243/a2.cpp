#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  set<int> ans;
  set<int> lst;

  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    lst.insert(0);

    set<int> nxt;
    for(auto y : lst)
      nxt.insert(x|y), ans.insert(x|y);

    lst = nxt;
  }

  cout << ans.size() << endl;
}
