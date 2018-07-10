#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 3e5 + 5;

int vis[N];
bool vis1[N];
bool vis3[N];

vector<int> tadj[N];
vector<int> com[N];
vector<int> iadj[N];

int ans = 0;

stack<int> st;

void dfs(int a, int f){
  if(vis1[a]) return;
  vis1[a] = true;

  for(auto x : tadj[a])
    if(x != f){
      dfs(x, a);
      iadj[x].push_back(a);
    }
  st.push(a);
}

int diam(int a, int f){
  if(vis3[a]) return -1;
  vis3[a] = true;

  int mx1 = 0, mx2 = 0;
  for(auto n : com[a])
    for(auto x : tadj[n])
      if(vis[x] != f){
        mx2 = max(mx2, 1 + diam(vis[x], a));
        if(mx2 > mx1) swap(mx2, mx1);
      }

  ans = max(ans, mx1 + mx2);
  return max(mx1, mx2);
}

void idfs(int a, int cnt){
  if(vis[a]) return;
  vis[a] = cnt;
  com[cnt].push_back(a);

  for(auto x : iadj[a])
    idfs(x, cnt);
}

int main(){
  int n, m;
  cin >> n >> m;

  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    tadj[a].push_back(b);
    tadj[b].push_back(a);
  }

  dfs(1, 0);

  int cnt = 1;

  while(st.size()){
    int x = st.top();
    st.pop();
    idfs(x, cnt++);
  }


  diam(1, 0);

  cout << ans << endl;
}
