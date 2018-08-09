#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 505;
char g[N][N];
int id[N][N];
int cnt = 1;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int amt[N*N];
int sz[N*N];
int sum;

int n, k;

void dfs(int i, int j, int idx){
  if(g[i][j] == 'X' or id[i][j]) return;
  id[i][j] = idx;
  sz[idx]++;

  for(int k = 0; k < 4; k++)
    dfs(i + dx[k], j + dy[k], idx);
}

void add(int c, int l, int r, bool row, bool in, bool rem = false){
  for(int i = l; i <= r; i++){
    int idx;
    if(row) idx = id[c][i];
    else idx = id[i][c];

    if(idx == 0){
      if(in) sum = sum + !rem - rem;
    }
    else{
      amt[idx] = amt[idx] + !rem - rem;
      if(amt[idx] == 1 and !rem) sum += sz[idx];
      if(amt[idx] == 0 and rem) sum -= sz[idx];
    }
  }
}

void addEnv(int i, int j, bool rem = false){
  add(i - 1, j, j + k - 1, true, false, rem);
  add(i + k, j, j + k - 1, true, false, rem);
  add(j - 1, i, i + k - 1, false, false, rem);
  add(j + k, i, i + k - 1, false, false, rem);
}

int main(){
  cin >> n >> k;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      cin >> g[i][j];

  for(int i = 0; i <= n + 1; i++)
    g[i][0] = 'X', g[i][n + 1] = 'X',
      g[0][i] = 'X', g[n + 1][i] = 'X';

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      if(!id[i][j] and g[i][j] != 'X') dfs(i, j, cnt++);

  add(0, 1, k, true, false, false);
  add(k + 1, 1, k, true, false, false);
  add(0, 1, k, false, false, false);
  add(k + 1, 1, k, false, false, false);
  for(int i = 1; i <= k; i++)
    add(i, 1, k, true, true, false);

  int ans = sum;

  int dir = 1; // right
  for(int i = 1; i <= n - k + 1;){
    int lim = n - k + 1, bg = 1;
    int j;

    if(dir == -1) swap(lim, bg);
    for(j = bg; j != lim;){
      addEnv(i, j, true);

      if(dir == 1)
        add(j, i, i + k - 1, false, true, true),
        add(j + k, i, i + k - 1, false, true, false);
      else
        add(j + k - 1, i, i + k - 1, false, true, true),
        add(j - 1, i, i + k - 1, false, true, false);

      j += dir;
      addEnv(i, j, false);

      ans = max(ans, sum);
    }
    if(i == n - k + 1) break;

    addEnv(i, j, true);
    add(i, j, j + k - 1, true, true, true),
    add(i + k, j, j + k - 1, true, true, false);

    i++;
    dir = -dir;

    addEnv(i, j, false);

    ans = max(ans, sum);
  }

  cout << ans << endl;
}
