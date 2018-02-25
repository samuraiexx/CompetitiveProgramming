#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
int v[N];

int main(){
  int n;
  while(cin >> n){
    int ans = 0;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n - 1; j++) if(v[j] > v[j + 1])
        swap(v[j], v[j + 1]);

    for(int i = 0; i < n/2; i++) ans -= v[i];
    for(int i = n/2 + n%2; i < n; i++) ans += v[i];
    cout << ans << endl;
  }
}
