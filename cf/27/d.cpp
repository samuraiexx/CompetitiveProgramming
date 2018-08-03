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
pair<int, int> road[N];
char ans[N];

bool dfs(int n, char t){
  if(ans[n]) return ans[n] == t;
  ans[n] = t;

  if(t == 'o') t = 'i';
  else t = 'o';

  bool ret = true;
  for(auto x : adj[n])
    ret &= dfs(x, t);

  return ret;
}

int main(){
  int n, m;
  cin >> n >> m;

  for(int i = 0; i < m; i++)
    cin >> road[i].st >> road[i].nd;

  for(int i = 0; i < m; i++){
    for(int j = i + 1; j < m; j++){
      int k = road[i].st;
      bool ok = true;
      while(1){
        k = k%n + 1;
        if(k == road[i].nd) break;
        else if(k == road[j].st or k == road[j].nd){
          ok = false;
          break;
        }
      }
      bool ok2 = true;

      k = road[i].st;
      while(1){
        k = (k + n - 2)%n + 1;
        if(k == road[i].nd) break;
        else if(k == road[j].st or k == road[j].nd){
          ok2 = false;
          break;
        }
      }
      if(!ok and !ok2) adj[i].push_back(j), adj[j].push_back(i);
    }
  }

  bool ok = true;
  for(int i = 0; i < m; i++)
    if(!ans[i]) ok &= dfs(i, 'i');

  if(!ok) cout << "Impossible";
  else
    for(int i = 0; i < m; i++)
      cout << ans[i];

  cout << endl;
}
