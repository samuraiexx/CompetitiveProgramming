#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e4 + 5;
int v[N], st[4*N];

void build(int n, int l, int r){
  if(l == r){ st[n] = v[l]; return; }
  int mid = (l + r)/2;
  build(2*n, l, mid);
  build(2*n + 1, mid + 1, r);
  st[n] = st[2*n]&st[2*n + 1];
}

int query(int n, int l, int r, int i, int j){
  if(r < i or l > j) return -1;
  if(l >= i and r <= j) return st[n];

  int mid = (l + r)/2;
  int ans = query(2*n, l, mid, i, j);
  ans &= query(2*n + 1, mid + 1, r, i, j);
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> v[i];
    build(1, 0, n-1);

    for(int i = 0; i < n; i++){

      int ans;
      if(k >= n) ans = st[1];
      else if(i - k < 0)
        ans = query(1, 0, n - 1, 0, i + k)&query(1, 0, n - 1, n + i - k, n - 1);
      else if(i + k >= n)
        ans = query(1, 0, n - 1, i - k, n - 1)&query(1, 0, n - 1, 0, i + k - n);
      else ans = query(1, 0, n - 1, i - k, i + k);

      cout << ans << " \n"[i == n - 1];
    }
  }
}
