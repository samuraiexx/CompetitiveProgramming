#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

const int N = 2e5 + 5;

// Tarjan for SCC and Edge Biconnected Componentes - O(n + m)
vector<int> adj[N];
stack<int> st;
bool inSt[N];

int id[N], cmp[N];
int cnt, cmpCnt;

void add(int u, int v){
  adj[u].pb(v);
  adj[v^1].pb(u^1);
}

int tarjan(int n){
  if(id[n]) return -1;
  int low;
  id[n] = low = ++cnt;
  st.push(n), inSt[n] = true;

  for(auto x : adj[n]){
    if(id[x] and inSt[x]) low = min(low, id[x]);
    else if(!id[x]) {
      int lowx = tarjan(x);
      if(inSt[x])
        low = min(low, lowx);
    }
  }

  if(low == id[n]){
    while(st.size()){
      int x = st.top();
      inSt[x] = false;
      cmp[x] = cmpCnt;

      st.pop();
      if(x == n) break;
    }
    cmpCnt++;
  }
  return low;
}

// End of tarjan

vector<int> sw[N];
bool state[N];

int main(){
  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= n; i++)
    cin >> state[i];

  for(int i = 0; i < m; i++){
    int x;
    cin >> x;
    for(int j = 0, y; j < x; j++)
      cin >> y, sw[y].pb(i);
  }

  for(int i = 1; i <= n; i++){
    if(state[i]) { //unclocked
      add(2*sw[i][0], 2*sw[i][1]);
      add(2*sw[i][0] + 1, 2*sw[i][1] + 1);
    } else {
      add(2*sw[i][0], 2*sw[i][1] + 1);
      add(2*sw[i][0] + 1, 2*sw[i][1]);
    }
  }

  bool sat = true;
  for(int i = 0; i < m; i++){
    tarjan(2*i);
    tarjan(2*i + 1);
    if(cmp[2*i] == cmp[2*i + 1]) sat = false;
  }

  cout << (sat ? "YES" : "NO") << endl;
}
