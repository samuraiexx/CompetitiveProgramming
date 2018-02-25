#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  bool ok = 0;
  cin >> n;

  int ta = 1234567, tb = 123456, tc = 1234;
  int maxa = n/ta, maxb = n/tb;

  for(int i = 0; i <= maxa; i++)
    for(int j = 0; j <= maxb; j++)
      if(n < i*ta + j*tb) break;
      else if((n - i*ta - j*tb)%tc == 0) {
        ok = 1;
        break;
      }

  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
}
