#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
const int N = 1e3 + 5;
vector<int> adj[N];
stack<int> st;
int vis[N];

void dfs(int n){
  vis[n] = true;
  st.push(n);
  for(auto a : adj[n])
    if(!vis[a]) dfs(a);
}

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      char c;
      cin >> c;
      if(c == 'X'){
        for(int k = j + 1; k < n; k++)
          cin >> c;
        break;
      }
      if(c == '1') adj[i].pb(j);
      else adj[j].pb(i);
    }

  dfs(0);
  if(st.size() != n) return cout << "impossible" << endl, 0;

  while(st.size()) cout << st.top() << ' ', st.pop();
  cout << endl;
}
