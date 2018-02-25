#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int prices[N];

int main(){
  int n, q;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> prices[i];
  sort(prices, prices + n);
  cin >> q;
  for(int i = 0; i < q; i++){
    int m;
    cin >> m;
    cout << upper_bound(prices, prices + n, m) - prices << endl;
  }
}
