#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int v1[N], v2[N];

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> v1[i];
  for(int i = 0; i < n; i++) cin >> v2[i];

  int a = 0, b = 0;
  for(int i = 0; i < n; i++)
    a = a|v1[i], b = b|v2[i];

  cout << a + b << endl;
}
