#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e5 + 5;
const int M = 31;
int a[N];
int v[M];

int main(){
  int n, q;
  cin >> n >> q;

  for(int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);
  int b = 0;
  for(int i = 0; i < n; i++){
    while(a[i] != (1 << b)) b++;
    v[b]++;
  }

  for(int i = 0; i < q; i++){
    int x, ans = 0;
    cin >> x;
    int j = M - 1;
    while(x and j >= 0){
      while((1 << j) > x) j--;
      int dt = min(x/(1 << j), v[j]);
      x -= dt*(1 << j);
      ans += dt;
      j--;
    }
    if(x > 0) cout << -1 << endl;
    else cout << ans << endl;
  }
}
