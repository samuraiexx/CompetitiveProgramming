#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;
int lst[N], u[N];
int ans[N];
pair<int, int> st[4*N];

pair<int, int> query(int n, int l, int r, int i, int j){
  if(i > r or l > j) return {INF, INF};
  if(i <= l and r <= j) return st[n];

  int mid = (l + r)/2;
  return min(query(2*n, l, mid, i, j), 
             query(2*n + 1, mid + 1, r, i, j));
}

void update(int n, int l, int r, int i, int val){
  if(l == r){ st[n] = {val, l}; return; }
  int mid = (l + r)/2;

  if(i <= mid) update(2*n, l, mid, i, val);
  else update(2*n + 1, mid + 1, r, i, val);

  st[n] = min(st[2*n], st[2*n + 1]);
}

struct Qry{
  int l, r;
  int i;
  bool operator<(Qry q){ return r < q.r; }
} qry[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  for(int i = 1; i <= n; i++)
    cin >> u[i];

  int q;
  cin >> q;
  for(int i = 0; i < q; i++){
    cin >> qry[i].l >> qry[i].r;
    qry[i].i = i;
  }
  sort(qry, qry + q);

  int j = 0;
  for(int i = 0; i < q; i++){
    auto &q = qry[i];
    int a = q.l, b = q.r;

    while(j < b){
      j++;

      update(1, 1, n, j, lst[u[j]]);
      if(lst[u[j]]) update(1, 1, n, lst[u[j]], INF);
      lst[u[j]] = j;
    }

    auto p = query(1, 1, n, a, b);

    if(p.st < a) ans[q.i] = u[p.nd];
    else ans[q.i] = 0;
  }

  for(int i = 0; i < q; i++)
    cout << ans[i] << '\n';
}
