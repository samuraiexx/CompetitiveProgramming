#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 7201;
const int INF = 0x3f3f3f3f;
int c[N];

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, t;
    cin >> n >> t;
    vector<int> bp, bn;
    for(int i = 0; i < n;  i++){
      int b;
      cin >> b;
      if(b > 0) bp.pb(b);
      else bn.pb(b);
    }
    memset(c, 0x3f, sizeof c);
    c[0] = 0;

    for(int i = 0; i < N; i++)
      for(auto x : bp) if(i - x >= 0){
        c[i] = min(c[i - x] + 1, c[i]);
        if(i > 3600) c[3600] = min(c[3600], c[i]);
      }

    for(int i = N - 1; i >= 0; i--)
      for(auto x : bn)
        if(i - x < N) c[i] = min(c[i - x] + 1, c[i]);

    for(int i = t; i <= 3600; i++)
      if(c[i] != INF) {
        cout << c[i] << ' ' << i - t << endl;
        break;
    }
  }
}
