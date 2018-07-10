#include<bits/stdc++.h>
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
tuple<int, int, int> d[N];
int ans[N];
int st[4*N];

void update(int n, int l, int r, int i, int val){
  if(l > i or i > r) return;
  if(l == r){ st[n] = val; return; }
  int mid = (l + r)/2;
  update(2*n, l, mid, i, val);
  update(2*n + 1, mid + 1, r, i, val);
  st[n] = max(st[2*n], st[2*n + 1]);
}

int query(int n, int l, int r, int i, int j){
  if(j < l or i > r) return -INF;
  if(i <= l and r <= j) return st[n];
  int mid = (l + r)/2;
  return max(query(2*n, l, mid, i, j), query(2*n + 1, mid + 1, r, i, j));
}

int main(){
  memset(st, 0x80, sizeof st);
  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    d[i] = {a, b, i};
  }

  sort(d, d + n);

  for(int i = n - 1; i >= 0; i--){

    int dist = get<0>(d[i]) + get<1>(d[i]);
    update(1, 0, n - 1, i, dist); 

    tuple<int, int, int> mx = {dist, -INF, -INF};
    auto it = lower_bound(d, d + n, mx);

    mx = {query(1, 0, n - 1, i, it - d - 1), -INF, -INF};

    update(1, 0, n - 1, i, get<0>(mx)); 

    it = lower_bound(d, d + n, mx);
    ans[get<2>(d[i])] = it - (d + i);
  }

  for(int i = 0; i < n; i++)
    cout << ans[i] << ' ';
  cout << endl;
}
