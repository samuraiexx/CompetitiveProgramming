#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;

vector<int> adj[N];
stack<int> st;
bool inSt[N];

int low[N], id[N], cmp[N];
int in[N];
int cnt, cmpCnt;

void tarjan(int n){
  id[n] = low[n] = ++cnt;
  st.push(n), inSt[n] = true;

  for(auto x : adj[n]){
    if(id[x] and inSt[x]) low[n] = min(low[n], id[x]);
    else if(!id[x]) {
      tarjan(x);
      if(inSt[x])
        low[n] = min(low[n], low[x]);
    }
  }

  if(low[n] == id[n]){
    while(st.size()){
      int x = st.top();
      inSt[x] = false;
      cmp[x] = cmpCnt;

      st.pop();
      if(x == n) break;
    }
    cmpCnt++;
  }
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;

  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }

  for(int i = 1; i <= n; i++)
    if(!id[i]) tarjan(i);

  for(int i = 1; i <= n; i++)
    for(auto x : adj[i])
      if(cmp[i] != cmp[x])
        in[cmp[i]]++;

  int cAns;
  vector<int> ans;
  for(int i = 0; i < cmpCnt; i++){
    if(in[i] == 0){
      cAns = i;
      break;
    }
  }

  for(int i = 1; i <= n; i++)
    if(cmp[i] == cAns) ans.push_back(i);

  cout << ans.size() << '\n';
  for(int i = 0; i < ans.size(); i++)
    cout << ans[i] << " \n"[i == ans.size() - 1];
}
