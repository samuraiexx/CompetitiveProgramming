#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    int n;
    cin >> n;
    int mx = 0, mn = 200;

    for(int i = 0, x; i < n; i++)
      cin >> x, mx = max(mx, x), mn = min(mn, x);

    cout << 2*(mx - mn) << endl;
  }
}
