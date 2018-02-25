#include<bits/stdc++.h>
using namespace std;
const int N = 367;
int m[N];
int f[N];

int main(){
  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    char c;
    int bg, ed;
    cin >> c >> bg >> ed;
    if(c == 'M') for(int i = bg; i <= ed; i++) m[i]++;
    if(c == 'F') for(int i = bg; i <= ed; i++) f[i]++;
  }

  int mx = 0;
  for(int i = 1; i <= 366; i++)
    mx = max(mx, min(m[i], f[i]));
  cout << 2mx << endl;
}
