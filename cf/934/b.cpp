#include<bits/stdc++.h>
using namespace std;
const long long N = 100;

int main(){
  int k;
  cin >> k;
  if(k > 36) return cout << -1 << endl, 0;
  for(int i = 0; i < k/2; i++) cout << 8;
  if(k%2) cout << 9;
  cout << endl;
  return 0;
}
