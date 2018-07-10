#include<bits/stdc++.h>
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
using namespace std;
const int N = 1e5 + 5;

int dx[] = {1, -1, 1, -1, 1, -1, 0, 0};
int dy[] = {1, -1, -1, 1, 0, 0, 1, -1};
vector<int> adj[N];
int dist[N];

int main(){
  int x0, y0, x1, y1;
  int n;
  cin >> x0 >> y0 >> x1 >> y1 >> n;
  memset(dist, -1, sizeof dist);


  map<pair<int, int>, int> m;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    int a, b, c;
    cin >> a >> b >> c;
    for(int i = b; i <= c; i++)
      if(!m.count({a, i}))
        m[make_pair(a, i)] = cnt++;
  }

  for(auto p : m){
    for(int i = 0; i < 8; i++){
      auto x = p.st;
      x.st += dx[i], x.nd += dy[i];
      if(m.count(x))
        adj[p.nd].push_back(m[x]);
    }
  }

  int bg = m[make_pair(x0, y0)];
  int ed = m[make_pair(x1, y1)];

  queue<int> bfs;
  bfs.push(bg);
  dist[bg] = 0;

  while(bfs.size()){
    auto p = bfs.front();
    bfs.pop();
    for(auto x : adj[p])
      if(dist[x] == -1){
        dist[x] = dist[p] + 1;
        bfs.push(x);
      }
  }

  cout << dist[ed] << endl;
}
