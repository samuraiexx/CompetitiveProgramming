#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e5 + 5;
vector<pair<int, int>> adj[N];
int n, m, k;
int cnt;

vector<string> sans;

vector<int> opt[N];

int vis[N];
int ans[N];

void bt(int i){
  if(cnt == k) return;

  if(i > n){
    string s;
    for(int i = 0; i < m; i++)
      if(ans[i]) s.push_back('1');
      else s.push_back('0');

    sans.pb(s);
    cnt++;
    return;
  }
  for(auto x : opt[i]){
    ans[x] = true;
    bt(i + 1);
    ans[x] = false;

    if(cnt == k) return;
  }
}

int main(){
  cin >> n >> m >> k;
  for(int i = 0; i < m ;i++){
    int a, b;
    cin >> a >> b;
    adj[a].pb({b, i}), adj[b].pb({a, i});
  }

  memset(vis, -1, sizeof vis);

  queue<int> bfs;
  bfs.push(1);
  vis[1] = 0;

  int dist = 0;
  while(bfs.size()){
    while(bfs.size() and vis[bfs.front()] == dist){
      int x = bfs.front(); bfs.pop();

      for(auto p : adj[x]){
        int y = p.st;
        if(vis[y] == -1 or vis[y] == vis[x] + 1){
          if(vis[y] == -1) bfs.push(y);

          vis[y] = vis[x] + 1;

          opt[y].pb(p.nd);
        }
      }
    }
    dist++;
  }

  bt(2);
  cout << sans.size() << '\n';
  for(auto s : sans)
    cout << s << '\n';
}
