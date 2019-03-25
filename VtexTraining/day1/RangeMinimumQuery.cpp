#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int M = 20;
const int N = 1 << M;
const int INF = 1e9 + 1;

int bit[N];
tuple<char, int, int> qry[N];
int st[4*N];

void add(int x, int val = 1){
  for(int i = x; i < N; i+=i&-i)
    bit[i] += val;
}

int bquery(int x){
  int ans = 0;
  for(int i = x; i > 0; i-=i&-i)
    ans += bit[i];
  return ans;
}

int binary_search(int val){ // lower bound
  int ans = 0, sum = 0;
  for(int i = M - 1; i >= 0; i--){
    int x = ans + (1 << i);
    if(sum + bit[x] < val)
      ans = x, sum += bit[x];
  }

  return ans + 1;
}

void update(int n, int l, int r, int x, int val){
  if(x < l or x > r) return;
  if(l == r){ st[n] = val; return; }
  int mid = (l + r)/2;
  update(2*n, l, mid, x, val);
  update(2*n + 1, mid + 1, r, x, val);

  st[n] = min(st[2*n], st[2*n + 1]);
}

int query(int n, int l, int r, int i, int j){
  if(r < i or j < l) return INF;
  if(i <= l and r <= j) return st[n];
  int mid = (l + r)/2;
  return min(query(2*n, l, mid, i, j),
             query(2*n + 1, mid + 1, r, i, j));
}

int main(){
  freopen("rmq.in", "r", stdin);
  freopen("rmq.out", "w", stdout);
  cin.tie(0), ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    char c;
    int a, b;
    cin >> c >> a >> b;
    qry[i] = {c, a, b};
    add(i + 1);
  }

  for(int i = n - 1; i >= 0; i--){
    auto &[c, x, y] = qry[i];
    if(c == '+'){
      x = binary_search(x + 1);
      add(x, -1);
    } else {
      x = binary_search(x);
      y = binary_search(y);
    }
  }

  for(int i = 0; i < n; i++){
    auto [c, a, b] = qry[i];
    if(c == '+') update(1, 1, n, a, b);
    else cout << query(1, 1, n, a, b) << '\n';
  }
}
