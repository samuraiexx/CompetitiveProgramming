#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 3e5 + 5;

bool vis[N];
int s[N];

struct Node{
  int n, x = 0;
  double exp = numeric_limits<double>::infinity();

  bool operator<(Node b)const{
    return exp > b.exp;
  }
} nodes[N];

vector<int> adj[N];

int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;

    s[a]++, s[b]++;

    adj[a].pb(b), adj[b].pb(a);
  }

  priority_queue<Node> q;
  q.push({n, 0, 0});

  while(q.size()){
    auto node = q.top(); q.pop();
    if(vis[node.n]) continue;
    vis[node.n] = true;

    for(auto x : adj[node.n]){
      int nx = nodes[x].x + 1;
      double exp;
      if(nodes[x].x == 0) exp = s[x] + node.exp;
      else exp = (nodes[x].exp*nodes[x].x + node.exp)/(double)(nx);
      if(exp < nodes[x].exp)
        nodes[x].n = x, nodes[x].x = nx, nodes[x].exp = exp, q.push(nodes[x]);
    }
  }

  printf("%.12lf\n", nodes[1].exp);
}
