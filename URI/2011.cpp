#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e3 + 5;
const double EPS = 1e-8;
bool vis[N];
int n, m;

struct Edge{
  int a, b;
  int to;
};

vector<Edge> adj[N];

double dij(double t){
  priority_queue<pair<double, int>,
          vector<pair<double, int>>,
         greater<pair<double, int>>> q;

  for(int i = 1; i <= n; i++)
    vis[i] = false;

  q.push({0, 1});

  while(q.size()){
    double w = q.top().st;
    int node = q.top().nd;
    q.pop();

    if(vis[node]) continue;
    vis[node] = true;
    if(node == n) return w;

    for(auto edge : adj[node])
      q.push({w + edge.a*t + edge.b, edge.to});
  }
}

int main(){
  cin >> n >> m;

  while(m--){
    Edge edg;
    int i, j, a, b;
    cin >> i >> j >> a >> b;
    adj[i].pb({a, b, j});
    adj[j].pb({a, b, i});
  }

  double i = 0, j = 24*60;
  for(int z = 0; z < 100; z++){
    double a = i + (j - i)/3;
    double b = j - (j - i)/3;
    if(dij(a) < dij(b)) i = a;
    else j = b;
  }
  double ans = dij(i);
  printf("%.5lf\n", ans);
}
