#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1000;
const int M = 666;

bool g[N][N];
int cnt[2][2];

pair<int, int> v[M + 1], x;
pair<int, int> mid = {500, 500};

int norm(int x) { return x == 0 ? 0 : x/abs(x); }

bool play(pair<int, int> to){
  pair<int, int> nxt = {x.st + norm(to.st - x.st), 
                        x.nd + norm(to.nd - x.nd)};

  if(g[nxt.st][nxt.nd]) cout << nxt.st << ' ' << x.nd << endl;
  else cout << nxt.st << ' ' << nxt.nd << endl;

  int k;
  cin >> k;
  if(k <= 0) return false;

  g[v[k].st][v[k].nd] = false;

  cin >> v[k].st >> v[k].nd;
  g[v[k].st][v[k].nd] = true;

  x = nxt;
  return true;
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  cin >> x.st >> x.nd;

  for(int i = 1; i <= M; i++)
    cin >> v[i].st >> v[i].nd, g[v[i].st][v[i].nd] = true;

  while(x.st != mid.st || x.nd != mid.nd)
    if(!play(mid)) return 0;

  for(int i = 1; i < N; i++)
    for(int j = 1; j < N; j++)
      cnt[i > mid.st][j > mid.nd] += g[i][j];

  int mn = 666/4;
  pair<int, int> to;
  if(cnt[0][0] <= mn) to = {999, 999};
  else if(cnt[1][1] <= mn) to = {0, 0};
  else if(cnt[0][1] <= mn) to = {999, 0};
  else to = {0, 999};


  while(play(to));
}
