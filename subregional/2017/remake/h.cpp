#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 105;
vector<int> adj[N];
int dp[N];

struct Point{
  int x, y;
  Point(int x = 0, int y = 0):x(x), y(y){}
  Point operator-(Point p){ return Point(x - p.x, y - p.y); }
  ll operator%(Point p){ return x*p.y - y*p.x; }
}pnt[N];

int dfs(int n){
  if(dp[n]) return dp[n];
  for(auto x : adj[n])
    dp[n] = max(dp[n], dfs(x));

  dp[n]++;
  return dp[n];
}

int main(){
  int n;
  Point pa, pb;
  cin >> n >> pa.x >> pb.x;

  for(int i = 0; i < n; i++)
    cin >> pnt[i].x >> pnt[i].y;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      if((pnt[i] - pa)%(pnt[j] - pa) < 0 and 
         (pnt[i] - pb)%(pnt[j] - pb) > 0)
        adj[j].push_back(i);
    }

  int mx = 0;
  for(int i = 0; i < n; i++)
    mx = max(mx, dfs(i));

  cout << mx << endl;
}
