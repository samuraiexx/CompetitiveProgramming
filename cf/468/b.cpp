#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e5 + 5;
pair<int, int> v[N];

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

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int n, a, b;
  cin >> n >> a >> b;
  for(int i = 0; i < n; i++)
    cin >> v[i].st, v[i].nd = i;
  sort(v, v + n);

  for(int i = 0; i < n; i++){
    int p1 = lower_bound(v, v + n, make_pair(a - v[i].st, 0)) - v;
    int p2 = lower_bound(v, v + n, make_pair(b - v[i].st, 0)) - v;
    if(a - v[i].st == v[p1].st) add(2*i, 2*p1);
    else add(2*i, 2*i + 1);
    if(b - v[i].st == v[p2].st) add(2*i + 1, 2*p2 + 1);
    else add(2*i + 1, 2*i);
  }

  vector<bool> ans(n);
  for(int i = 0; i < n; i++){
    tarjan(2*i), tarjan(2*i + 1);
    if(cmp[2*i] == cmp[2*i + 1]) return cout << "NO\n", 0;
    ans[v[i].nd] = (cmp[2*i] > cmp[2*i + 1] ? 1 : 0);
  }

  cout << "YES\n";
  for(auto x : ans) cout << x << ' ';
  cout << endl;
}
