#include<bits/stdc++.h>
using namespace std;

int main(){
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for(auto &x : v)
      cin >> x;

    cout << n << endl;
    cout << "Case #" << t << ": ";
    if(n%2) cout << 1 << endl << 0 << endl;
    else cout << 0 << endl;
  }
}
