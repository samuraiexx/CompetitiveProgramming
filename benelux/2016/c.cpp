#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
const int N = 2e5 + 5;

vector<int> adj[N];
int inc[N];

int main(){
  int c, p, x, l;
  cin >> c >> p >> x >> l;
  for(int i = 0, a, b; i < p; i++)
    cin >> a >> b, adj[a].pb(b), adj[b].pb(a), inc[a]++, inc[b]++;

  inc[l] = -1;

  stack<int> st;
  st.push(l);

  while(st.size()){
    int l = st.top(); st.pop();

    for(auto a : adj[l]){
        if(inc[a] == -1) continue;
        inc[a]--;
        if(inc[a] <= adj[a].size()/2) st.push(a), inc[a] = -1;
      }
  }

  if(inc[x] == -1) cout << "leave" << endl;
  else cout << "stay" << endl;
}
