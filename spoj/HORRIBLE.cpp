#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
ll st[4*N];
ll lz[4*N];

void push(int n, int l, int r){
  if(!lz[n]) return;

  st[n] += (r - l + 1)*lz[n];
  if(l != r){
    lz[2*n] += lz[n];
    lz[2*n + 1] += lz[n];
  }
  lz[n] = 0;
}

void update(int n, int l, int r, int i, int j, int val){
  push(n, l, r);
  if(r < i or l > j) return;
  if(i <= l and r <= j) { lz[n] += val; push(n, l, r); return; }
  int mid = (l + r)/2;
  update(2*n, l, mid, i, j, val);
  update(2*n + 1, mid + 1, r, i, j, val);
  st[n] = st[2*n] + st[2*n + 1];
}

ll query(int n, int l, int r, int i, int j){
  push(n, l, r);
  if(r < i or l > j) return 0;
  if(i <= l and r <= j) { return st[n]; }
  int mid = (l + r)/2;
  return query(2*n, l, mid, i, j) + query(2*n + 1, mid + 1, r, i, j);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, c;
    memset(st, 0, sizeof st);
    memset(lz, 0, sizeof lz);
    cin >> n >> c;

    while(c--){
      int t, p, q;
      cin >> t >> p >> q;
      if(t == 0){
        int v;
        cin >> v;
        update(1, 1, n, p, q, v);
      }else{
        cout << query(1, 1, n, p, q) << '\n';
      }
    }
  }
}
