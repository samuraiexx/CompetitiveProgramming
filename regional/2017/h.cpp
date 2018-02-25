#include<bits/stdc++.h>
using namespace std;
int m[3];
int p[3];

int main(){
  int ans = 0;
  for(int i = 0; i < 3; i++) cin >> m[i];
  for(int i = 0; i < 3; i++) cin >> p[i];
  for(int i = 0; i < 3; i++) ans += max(0, p[i] - m[i]);
  cout << ans << endl;
}
