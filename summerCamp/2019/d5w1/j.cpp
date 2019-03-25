#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e5 + 5;
pair<int, int> d[N], e[N];
int ord[N];

int cnt[N];
bool vis[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for(int i = 0; i < n; i++)
    cin >> d[i].st;

  for(int i = 0; i < n; i++)
    cin >> d[i].nd, d[i].nd--;

  for(int i = 0; i < m; i++)
    cin >> e[i].st >> e[i].nd, ord[i] = i;

  sort(ord, ord + m, [] (int i, int j) { return e[i].st > e[j].st; });

  sort(d, d + n, greater<pair<int, int>>());
  int i = 0, j = n + 1;

  while(i != j){
    memset(cnt, 0, sizeof cnt);
    memset(vis, 0, sizeof vis);
    int mid = (i + j)/2;

    for(int i = 0; i < n; i++){
      int j = d[i].nd;
      if(e[j].st < d[i].st and e[j].nd >= d[i].st and cnt[j] < mid)
        cnt[j]++, vis[i] = true;
    }

    int z = 0;
    bool ok = true;
    for(int jj = 0; jj < m and ok; jj++){
      int j = ord[jj];
      for(int k = cnt[j]; k < mid; k++){
        while(z < n and vis[z]) z++;
        if(z >= n) break;
        if(d[z].st > e[j].st){ ok = false; break; }
        vis[z] = true;
      }
    }

    while(z < n and vis[z]) z++;

    if(ok and z >= n) j = mid;
    else i = mid + 1;
  }

  if(j == n + 1)
    cout << -1 << endl;
  else cout << j << endl;
}
