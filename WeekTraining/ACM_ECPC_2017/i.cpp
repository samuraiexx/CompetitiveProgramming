#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 205;
const int M = 2e3 + 5;
int bit[205][205];
int ans[(int) 1e4 + 5];
int mat[N][N];
vector<pair<int, int>> xy[M];

int pos;

struct query{
  int a, b, c, d;
  int i;
};

void add(int x, int y, int val){
  for(int i = x; i < N; i += i&-i)
    for(int j = y; j < N; j+= j&-j)
      bit[i][j] += val;
}

ll bquery(int x, int y){
  ll ans = 0;
  for(int i = x; i > 0; i -= i&-i)
    for(int j = y; j > 0; j -= j&-j)
      ans += bit[i][j];

  return ans;
}

void pbs(int l, int r, vector<query> v){
  int mid = (l + r)/2;
  while(pos < mid){
    pos++;
    for(auto p : xy[pos])
      add(p.st, p.nd, 1);
  }
  while(pos > mid){
    for(auto p : xy[pos])
      add(p.st, p.nd, -1);
    pos--;
  }

  vector<query> lq, rq;
  for(auto q : v){
    ll amt = bquery(q.c, q.d) + bquery(q.a - 1, q.b - 1) - 
             (bquery(q.a - 1, q.d) + bquery(q.c, q.b - 1));
    ll total = (q.c - q.a + 1)*(q.d - q.b + 1);
    if(amt > total/2){
      lq.push_back(q);
      ans[q.i] = mid;
    } else rq.push_back(q);
  }

  if(l != r){
    pbs(l, mid, lq);
    pbs(mid + 1, r, rq);
  }
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  freopen("important.in", "r", stdin);

  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    cout << "Case " << t << ":\n";
    int n, m, q;
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++){
        cin >> mat[i][j];
        xy[mat[i][j]].push_back({i, j});
      }

    vector<query> qry;
    for(int i = 0; i < q; i++){
      query q;
      cin >> q.a >> q.b >> q.c >> q.d;
      q.i = i;
      qry.pb(q);
    }

    pbs(1, 2000, qry);

    for(int i = 0; i < q; i++)
      cout << ans[i] << '\n';
  }
}
