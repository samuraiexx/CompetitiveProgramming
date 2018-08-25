#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e6 + 5;

string type[N];
int lc[N], rc[N];

bool ans[N];
bool val[N];

bool dfs1(int n){
  if(type[n] == "NOT")
    val[n] = !dfs1(lc[n]);
  else if(type[n] == "AND")
    val[n] = dfs1(lc[n])&dfs1(rc[n]);
  else if(type[n] == "XOR")
    val[n] = dfs1(lc[n])^dfs1(rc[n]);
  else if(type[n] == "OR")
    val[n] = dfs1(lc[n])|dfs1(rc[n]);

  return val[n];
}

void dfs(int n, bool cc){
  if(type[n] == "NOT"){
    dfs(lc[n], cc);
  }
  else if(type[n] == "IN"){
    ans[n] = cc;
  }
  else if(type[n] == "AND"){
    if(val[n] == 1)
      dfs(lc[n], cc), dfs(rc[n], cc);
    else if(val[rc[n]]|val[lc[n]])
      dfs(lc[n], cc&!val[lc[n]]), dfs(rc[n], cc&!val[rc[n]]); 
    else dfs(lc[n], false), dfs(rc[n], false);
  }
  else if(type[n] == "XOR"){
    dfs(lc[n], cc);
    dfs(rc[n], cc);
  }
  else if(type[n] == "OR"){
    if(val[n] == 0) dfs(lc[n], cc), dfs(rc[n], cc);
    else if((val[lc[n]]&val[rc[n]]) == 0)
      dfs(lc[n], cc&val[lc[n]]), dfs(rc[n], cc&val[rc[n]]);
    else dfs(lc[n], false), dfs(rc[n], false);
  }
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> type[i];

    if(type[i] == "NOT"){
      cin >> lc[i];
    } else if(type[i] == "IN") {
      cin >> val[i];
    } else {
      cin >> lc[i] >> rc[i];
    }
  }

  dfs1(1);
  dfs(1, true);
  for(int i = 1; i <= n; i++)
    if(type[i] == "IN")
      cout << (ans[i] ? !val[1] : val[1]);
  cout << endl;
}
